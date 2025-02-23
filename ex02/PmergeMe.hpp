#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortWithVector(const std::vector<int>& sequence);
    void sortWithDeque(const std::deque<int>& sequence);
    void validateInput(int argc, char* argv[]);

};

#endif