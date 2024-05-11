/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:32 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/19 21:20:30 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <deque>
#include <iomanip>



class PmergeMe
{
    private:
        std::vector<int> numbers;
        std::deque<int>  numbers1;
        std::vector<std::pair<int, int> > pairsVector;
        std::vector<int> firstelements;
        std::vector<int> secondelements;
        std::deque<std::pair<int, int> > pairsDeque;
        std::deque<int> firstelements1;
        std::deque<int> secondelements1;

    public:
        
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        void  data_pairs(int ac , char **av);
        void data_pairs1();
        void sortPlace(const std::vector<int> &left, const std::vector<int> &right, std::vector<int> &arr) ;
        void partition(std::vector<int> &arr) ;
        void sortPlace1(const std::deque<int> &left, const std::deque<int> &right, std::deque<int> &arr) ;
        void partition1(std::deque<int> &arr) ;

        void insertWithLowerBound(std::vector<int>& first, std::vector<int>& second);
        void insertWithLowerBound1(std::deque<int>& first, std::deque<int>& second);

         void displayPairs(std::vector<int> elements);
         void displayPairs1(std::deque<int> elements);
         ~PmergeMe();
    
};







#endif