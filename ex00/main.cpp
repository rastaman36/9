/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:54:14 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/17 21:19:11 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac , char **av)
{
    BitcoinExchange stock;

    if (ac != 2)
        return 0;

    std::string file1 = av[1];

    stock.readfile("data.csv");
    stock.readfiletxt(file1);
    
}