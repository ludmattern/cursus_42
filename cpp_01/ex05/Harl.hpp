/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:45:06 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/05 17:01:21 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
    public:
        Harl();
        ~Harl();

        void complain(std::string level);

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

        int hashString(const std::string& str);
};
#endif