/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_print.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:03:16 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/02 10:03:24 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_PRINT_HPP
# define PHONE_BOOK_PRINT_HPP

#include "PhoneBook.hpp"

void	PrintSeperator(int ColumnCount, int ColumnWidth, bool edge);
void	PrintRow(int ColumnCount, int ColumnWidth, std::string *Content);
void	PrintTable(int ColumnCount, int ColumnWidth, const PhoneBook *book, std::string headers[]);
void	PrintContact(Contact contact);

#endif
