/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:34:54 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/26 14:47:22 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
Includes
*/
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <string.h>

/*
Error messages
*/
# define PHILO_ALLOC_ERR_MSG "Our apologies, but it appears we've run out of \
room at the table. A rare oversight...\n"
# define FORKS_ALLOC_ERR_MSG "Our apologies, but it appears we've run out of \
forks. A rare oversight...\n"
# define NB_PHILO_ERR_MSG "We're sorry, but we can't host a dinner for less \
than one guest or more than two hundred.\n"
# define ARG_ERR_MSG "A successful dinner requires careful planning. Please \
revise your input and join us again.\n"
# define INPUT_FMT_MSG "nb_philo, time_to_die, time_to_eat, time_to_sleep, \
[number_of_times_each_philosopher_must_eat]\n"
# define THREAD_ERR_MSG "One of our guests had to cancel at the last minute. \
We apologize for the inconvenience.\n"
# define DMONITOR_ERR_MSG "Our medical team is currently busy and won't be able \
to monitor the guests' health. We apologize for the inconvenience.\n"
# define HMONITOR_ERR_MSG "Our hunger monitor is currently indisposed and won't \
be able to check if all guests are satisfied. We apologize for the \
inconvenience.\n"
# define NARR_ALLOC_ERR_MSG "The narrator is indisposed and won't be able to \
comment on the dinner. We have no idea what happened.\n"
# define FORK_COMMENTARY "has taken a fork\n"
# define EAT_COMMENTARY "is eating\n"
# define SLEEP_COMMENTARY "is sleeping\n"
# define THINK_COMMENTARY "is thinking\n"
# define DIE_COMMENTARY "died\n"
# define SATISFIED_COMMENTARY "All guests are satisfied, the dinner is over.\n"

/*
Structures
*/

typedef enum e_end_cause
{
	DEATH,
	SATISFIED,
	END
}	t_end_cause;

typedef struct s_protected_status
{
	pthread_mutex_t	mutex;
	bool			initialized;
	bool			value;
}					t_protected_status;

typedef struct s_protected_value
{
	pthread_mutex_t	mutex;
	bool			initialized;
	long			value;
}					t_protected_value;

typedef struct s_fork
{
	pthread_mutex_t		mutex;
	t_protected_status	taken;
}						t_fork;

typedef struct s_philosopher
{
	int						id;
	long					must_eat_count;
	bool					left_fork_taken;
	bool					right_fork_taken;
	pthread_t				thread;
	t_fork					*left_fork;
	t_fork					*right_fork;
	t_protected_value		last_meal_time;
	t_protected_value		meals_eaten;
	struct s_table_plan		*table;
}							t_philosopher;

typedef struct s_table_plan
{
	long				nb_philo;
	int					nb_forks;
	int					nb_threads;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				start_time;
	pthread_t			death_monitor;
	pthread_t			hunger_monitor;
	t_philosopher		*p;
	t_fork				*forks;
	t_protected_status	ready_to_start;
	t_protected_status	annoying_narration;
	t_protected_status	end_annoying_narration;
	t_protected_status	having_dinner;
}						t_table_plan;

/*
utils
*/
size_t	ft_strlen(const char *s);
bool	parse_long(const char *str, long *out_value, bool philo);
void	swap_index(int *left_index, int *right_index);

/*
time related functions
*/
long	get_current_time(void);
long	get_elapsed_time(long start_time);
void	ft_usleep(long int time_in_ms, t_protected_status *having_dinner);

/*
preparation functions
*/
void	verify_booking(int ac);
void	prepare_dinner(char **av, t_table_plan *table);
void	have_dinner(t_table_plan *table);

/*
printing functions
*/
void	narrator(t_philosopher *philo, char *commentary);
void	end_narrator(t_philosopher *philo, char *commentary, t_end_cause cause);
void	ft_putstr_fd(char *s, int fd);

/*
philo threads functions
*/
void	eat(t_philosopher *philo);
void	think(t_philosopher *philo);
void	ft_sleep(t_philosopher *philo);
bool	take_fork(t_protected_status *status, bool new_state);
void	pick_up_forks(t_philosopher *philo);
void	drop_forks_if_held(t_philosopher *philo);

/*
monitors functions
*/
void	*hunger_monitor(void *arg);
bool	are_philo_satisfied(t_table_plan *table);
void	*death_monitor(void *arg);
bool	is_there_a_dead_philo(t_table_plan *table);

/*
end of program functions
*/
void	put_and_end_to_this_masquerade(t_table_plan *table, int status);
void	wait_for_empty_plates(t_table_plan *table);

/*
mutex functions
*/
bool	protected_value_init(t_protected_value *value, long initial_value);
long	protected_value_read(t_protected_value *value);
void	protected_value_write(t_protected_value *value, long new_value);
void	protected_value_destroy(t_protected_value *value);
bool	protected_status_init(t_protected_status *status, bool initial_state);
bool	protected_status_read(t_protected_status *status);
void	protected_status_write(t_protected_status *status, bool new_state);
void	protected_status_destroy(t_protected_status *status);

#endif
