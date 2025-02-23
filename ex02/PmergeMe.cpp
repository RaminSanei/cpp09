#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::validateInput(int argc, char *argv[])
{
    if (argc < 2)
    {
        throw std::runtime_error("Error: No sequence provided.");
    }

    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num) || num < 0)
        {
            throw std::runtime_error("Error: Invalid number '" + std::string(argv[i]) + "'.");
        }
    }
}

void PmergeMe::sortWithVector(const std::vector<int> &sequence)
{
    sortWithContainer(sequence, "std::vector");
}

void PmergeMe::sortWithDeque(const std::deque<int> &sequence)
{
    sortWithContainer(sequence, "std::deque");
}