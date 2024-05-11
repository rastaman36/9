/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:40:35 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/19 21:14:37 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): mapD(other.mapD), date(other.date), value(other.value)
{
    
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        mapD = other.mapD;
        date = other.date;
        value = other.value;
        
    }
    return *this;
}

void    BitcoinExchange::insertdata(std::string& date, double value)
{
    mapD[date] = value;
}

void BitcoinExchange::readfile(std::string filename) {
    std::ifstream file(filename.c_str()); 
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double value;

        if (std::getline(iss, date, ',') && iss >> value) {
            insertdata(date, value);
        }
    }
}

double BitcoinExchange::getData(std::string date) {
    std::map<std::string, double>::const_iterator iter = mapD.find(date);

    if (iter == mapD.end()) {
        iter = mapD.lower_bound(date);
        
        if (iter == mapD.begin()) {
            return 0.0;
        }
        
        --iter;
    }

    return iter->second;
}
void    BitcoinExchange::hantdatevalue(std::string line)
{

    std::istringstream iss(line);
    std::string datestr , valuestr;
    double valueBtc;
    size_t pos = line.find("| ");
    if (pos == std::string::npos || pos + 2 >= line.length()) {
       // If "| " is not found or there are no characters after it, print an error and return
       throw std::runtime_error("bad input : " + line);
    }
    if(getline(iss, datestr, '|') && getline(iss, valuestr))
    {

        datestr.erase(0, datestr.find_first_not_of(" \t"));
        datestr.erase(datestr.find_last_not_of(" \t") + 1);
        valuestr.erase(0, valuestr.find_first_not_of(" \t"));
        valuestr.erase(valuestr.find_last_not_of(" \t") + 1);

        date = datestr;
        

        size_t firstDash = date.find('-');
        size_t secondDash = date.find('-', firstDash + 1);
        
        // Extract substrings for year, month, and day
        std::string yearStr = date.substr(0, firstDash);
        std::string monthStr = date.substr(firstDash + 1, secondDash - firstDash - 1);
        std::string dayStr = date.substr(secondDash + 1);
        
        // Check if month and day have length 2
        if (monthStr.length() != 2 || dayStr.length() != 2) {
            throw std::runtime_error("invalide format of date ");
        }
        
        for (std::string::size_type i = 0; i < date.size(); ++i) {
            if (!std::isdigit(date[i]) && date[i] != '-') {
                throw std::runtime_error("date not valide");
            }
        }
        std::istringstream iss(date);

        int year, month, day;

        //handle the format of the day lenght 2

        char dash;
        iss >> year >> dash >> month >> dash >> day;
        if (year >= 0 && month >= 1 && month <= 12 && day >= 1) {
            int maxDays = 31; // Default maximum number of days
            if (month == 2) {
                // Check if it's a leap year
                bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
                maxDays = isLeapYear ? 29 : 28;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                maxDays = 30;
            }
            
            // Check if the day is within the valid range for the given month
            if (day <= maxDays) {
                valueBtc = getData(date);
            } else {
                throw std::runtime_error("Invalid day for the given month: " + line);
            }
        }
        else
            throw std::runtime_error("bad format of date : " + line);
            
        if (valuestr[0] == '.' || valuestr[valuestr.length() - 1] == '.')
            throw std::runtime_error("bad form");
        char lefover;
        std::istringstream valueStream(valuestr);
        if (!(valueStream >> value) || valueStream.get(lefover)) {
            throw std::runtime_error("bad format of the value : " + line);
        }
        if (value > 1000)
            throw std::runtime_error("value too large. ");
        if (value < 0 || value > 1000)
            throw std::runtime_error("not a positive number.");
        if (value >  2147483647)
            throw std::runtime_error("too large a number.");
        std::cout << date <<  " >> " << (value *  valueBtc ) << std::endl;
    }

}

void    BitcoinExchange::parsdata(std::string line)
{
    hantdatevalue(line);
}

void    BitcoinExchange::readfiletxt(std::string filename){
    std::ifstream file(filename.c_str());

    if (!file.is_open()){
        std::cerr << "failed to open file: " << filename << std::endl;
        return;
    }

    std::string firstLine;
    if (!std::getline(file, firstLine)) {
        std::cerr << "Failed to read the first line from file: " << filename << std::endl;
        return;
    }
    if (firstLine != "date | value")
    {
         std::cerr << "Error: The first line does not match the expected format." << std::endl;
         return ;
    }
    std::string line;
    while (std::getline(file, line))
    {
        try{
            parsdata(line);

        }
        catch(std::exception &e)
        {
            std::cout << "Error : " << e.what() << std::endl;
        }

    }
}

BitcoinExchange::~BitcoinExchange()
{
    
}
