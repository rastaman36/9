/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <mochaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:15 by mochaoui          #+#    #+#             */
/*   Updated: 2024/03/19 21:22:34 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
        numbers = other.numbers;
        numbers1 = other.numbers1;
        pairsVector = other.pairsVector;
        firstelements = other.firstelements;
        secondelements = other.secondelements;
        pairsDeque = other.pairsDeque;
        firstelements1 = other.firstelements1;
        secondelements1 = other.secondelements1;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        numbers = other.numbers;
        numbers1 = other.numbers1;
        pairsVector = other.pairsVector;
        firstelements = other.firstelements;
        secondelements = other.secondelements;
        pairsDeque = other.pairsDeque;
        firstelements1 = other.firstelements1;
        secondelements1 = other.secondelements1;
    }
    return *this;
}



void PmergeMe::partition(std::vector<int> &arr) {
    int size = arr.size();
    if (size <= 1) {
        return;
    } else {
        int mid = size / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        partition(left);
        partition(right);
        
        sortPlace(left, right, arr);
    }
}


void PmergeMe::sortPlace(const std::vector<int> &left, const std::vector<int> &right, std::vector<int> &arr)
{

    int i = 0, j = 0, k = 0;
    int n1 = left.size();
    int n2 = right.size();

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void PmergeMe::partition1(std::deque<int> &arr) 
{
    int size = arr.size();
    if (size <= 1) {
        return;
    } else {
        int mid = size / 2;
        std::deque<int> left(arr.begin(), arr.begin() + mid);
        std::deque<int> right(arr.begin() + mid, arr.end());

        partition1(left);
        partition1(right);

        sortPlace1(left, right, arr);
    }
}


void PmergeMe::sortPlace1(const std::deque<int> &left, const std::deque<int> &right, std::deque<int> &arr) {
    int i = 0, j = 0, k = 0;
    int n1 = left.size();
    int n2 = right.size();

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}



void PmergeMe::insertWithLowerBound(std::vector<int>& first, std::vector<int>& second) {
    for (size_t i = 0; i < second.size(); ++i) {
        if (second[i] == -1)
            continue;
        std::vector<int>::iterator it = std::lower_bound(first.begin(), first.end(), second[i]);
        
        first.insert(it, second[i]);
    }
}

void PmergeMe::insertWithLowerBound1(std::deque<int>& first, std::deque<int>& second) {
    for (size_t i = 0; i < second.size(); ++i) {
        if (second[i] == -1)
            continue;
        std::deque<int>::iterator it = std::lower_bound(first.begin(), first.end(), second[i]);
        
        first.insert(it, second[i]);
    }
}



void PmergeMe::data_pairs(int ac , char **av)
{
 if (ac < 3 ) {
            std::cerr << "Invalid number of arguments. Please provide an even number of numbers." << std::endl;
            return;
        }

        for(int i = 1; i < ac; ++i) {
            std::istringstream iss(av[i]);
            int number;
            if (!(iss >> number)) {
                std::cerr << "Invalid number: " << av[i] << std::endl;
                continue;
            }
            numbers.push_back(number);
            numbers1.push_back(number);
        }
        std::cout << "this is the pairs before sorting *******VEEEEECTOORRRR***** ::::::> " << std::endl;
        displayPairs(numbers);
        std::cout << std::endl;
        
        clock_t start = clock();
        for (size_t i = 0; i + 1 < numbers.size(); i += 2) {
            pairsVector.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        }
        if (numbers.size() % 2 == 1) {
        pairsVector.push_back(std::make_pair(numbers.back(), -1));
        }

        
        for (size_t i = 0; i < pairsVector.size(); ++i) {
                if (pairsVector[i].first < pairsVector[i].second) {
                        std::swap(pairsVector[i].first, pairsVector[i].second);
             }
        }

        for (std::vector<std::pair<int, int> >::const_iterator it = pairsVector.begin(); it != pairsVector.end(); ++it) {
            firstelements.push_back(it->first);
            secondelements.push_back(it->second);
        }
        partition(firstelements);
        insertWithLowerBound(firstelements, secondelements);
        clock_t end = clock();
        std::cout << "this is the pairs after sorting  *******VEEEEECTOORRRR***** ::::::> " << std::endl;
        displayPairs(firstelements);
        std::cout << std::endl;
        double duration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
        std::cout << "Time to process a range of elements with std::vector : " << duration << " us" << std::endl;

}



void PmergeMe::data_pairs1()
{


        std::cout << "this is the pairs before sorting *******DEEEEEEQUEEEEE***** ::::::> " << std::endl;
        displayPairs1(numbers1);
        std::cout << std::endl;
        
        clock_t start = clock();
        for (size_t i = 0; i + 1 < numbers.size(); i += 2) {
            pairsDeque.push_back(std::make_pair(numbers1[i], numbers1[i + 1]));
        }
        if (numbers1.size() % 2 == 1) {
        pairsDeque.push_back(std::make_pair(numbers1.back(), -1));
        }

        
        for (size_t i = 0; i < pairsDeque.size(); ++i) {
                if (pairsDeque[i].first < pairsDeque[i].second) {
                        std::swap(pairsDeque[i].first, pairsDeque[i].second);
             }
        }

        for (std::deque<std::pair<int, int> >::const_iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it) {
            firstelements1.push_back(it->first);
            secondelements1.push_back(it->second);
        }
        partition1(firstelements1);
        insertWithLowerBound1(firstelements1, secondelements1);
        clock_t end = clock();
        std::cout << "this is the pairs after sorting  *******DEEEEEEQUEEEEEE***** ::::::> " << std::endl;
        displayPairs1(firstelements1);
        std::cout << std::endl;
        double duration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
        std::cout << "Time to process a range of elements with std::dequee : " << duration << " us" << std::endl;

}



void PmergeMe::displayPairs(std::vector<int> elements) {
   for (std::vector<int >::const_iterator it = elements.begin(); it != elements.end(); ++it) {
       std::cout << *it << " ";
   }
}

void PmergeMe::displayPairs1(std::deque<int> elements) {
   for (std::deque<int >::const_iterator it = elements.begin(); it != elements.end(); ++it) {
       std::cout << *it << " ";
       }
}


PmergeMe::~PmergeMe() {}