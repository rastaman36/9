/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:16:01 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/18 22:55:52 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE


#include <string>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>



class BitcoinExchange
{
    private:
        std::map<std::string, double> mapD;
        std::string date;
        double value;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange&    operator=(const BitcoinExchange& other);
        
        double getData(std::string date);
        void    readfile(std::string filename);
        void    readfiletxt(std::string filename);
        
        void    insertdata(std::string& date, double value);
        void    parsdata(std::string line);
        void    hantdatevalue(std::string line);
        ~BitcoinExchange();
};



#endif