/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:54 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/19 21:25:16 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    stack = other.stack;
}

RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}

bool isNomad(std::string token) {
        return (token.find_first_not_of("0123456789") == std::string::npos);
    }
bool isoperator(std::string token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }

double magic(double first, double secound, std::string op)
{
    if (op == "+")
        return first + secound;
    else if (op == "-")
        return first - secound;
    else if (op == "*")
        return first * secound;
    else if (op == "/")
    {
        if (secound == 0)
            throw std::runtime_error("Division by 0 ummm !");
        return first / secound;
    }
    return (0);
}

double RPN::checkrpn(std::string input)
{
    std::istringstream iss(input);
    std::string token;


    

    while(iss >> token)
    {
        if (isNomad(token))
        {
            double op;
            std::istringstream(token) >> op;
            if (op < 0 && op > 9)
                throw std::runtime_error("bad range");
            stack.push(op);
        }
        else if (isoperator(token))
        {
            if (stack.size() < 2)
                throw std::runtime_error("stack less then 2");
                
            double secound = stack.top();
            stack.pop();
            double first = stack.top();
            stack.pop();
            double result = magic(first, secound, token);
            stack.push(result);
        }
        else 
        {
            throw std::runtime_error("ERROR");
        }
    }

    
    if (stack.size() != 1)
        throw std::runtime_error("ERROR 1");
    if (!stack.empty())
        return (stack.top());
    else
       throw std::runtime_error("stack empty");
    
}

RPN::~RPN() {}