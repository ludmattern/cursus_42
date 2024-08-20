/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/28 16:39:02 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();

		enum Field
		{
			FIRST_NAME,
			LAST_NAME,
			NICKNAME,
			PHONE_NUMBER,
			DARKEST_SECRET
		};

		void setField(Field field, const std::string& value);
		std::string	getField(Field field) const;

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
