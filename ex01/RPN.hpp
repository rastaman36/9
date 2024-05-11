/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:05:44 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/19 21:23:49 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP


#include <string>
#include <iostream>
#include <stack>
#include <sstream>


class RPN
{
    private:
        std::stack<double> stack;
        
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        double checkrpn(std::string input);
        ~RPN();
    
};


#endif