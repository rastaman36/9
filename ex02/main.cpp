/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:21 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/17 20:44:53 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac , char **av)
{
    PmergeMe mergss;

    if (ac < 2){
        std::cerr << "check your arguments " << std::endl;
        return 1;
    }
    
    // for (int i = 1; i < ac; i++)
    mergss.data_pairs(ac, av);
    mergss.data_pairs1();

}
