/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:25:18 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/03/25 15:25:24 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	make_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper (str[i]);
		i++;
	}
	return;
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	if (argc == 1)
	{
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < argc)
		{
			str = argv[i];
			make_upper (str);
			std::cout<< str;
			i ++;
		}
		std::cout<< std::endl;
	}
	return (0);
}