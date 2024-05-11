/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:00:31 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/19 21:15:41 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{

    RPN calcule;


    if (ac != 2)
    {
        std::cout << "number of argument" << std::endl;
        return 1;
    }
    try
    {
        double result = calcule.checkrpn(av[1]);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}