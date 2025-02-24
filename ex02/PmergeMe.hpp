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
private:
    template <typename Container>
    void mergeInsertionSort(Container& container);

    template <typename Container>
    void displaySequence(const std::string& message, const Container& container) const;

    template <typename Container>
    void sortWithContainer(const Container& sequence, const std::string& containerName);

    double getElapsedTime(const std::clock_t& start) const;

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