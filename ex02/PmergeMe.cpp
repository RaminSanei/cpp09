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

template <typename Container>
void PmergeMe::mergeInsertionSort(Container &container)
{
    if (container.size() <= 1)
        return;

    typename Container::iterator middle = container.begin() + container.size() / 2;
    Container left(container.begin(), middle);
    Container right(middle, container.end());

    mergeInsertionSort(left);
    mergeInsertionSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}

template <typename Container>
void PmergeMe::displaySequence(const std::string &message, const Container &container) const
{
    std::cout << message;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::sortWithContainer(const Container &sequence, const std::string &containerName)
{
    Container container(sequence);
    displaySequence("Before: ", container);

    std::clock_t start = std::clock();
    mergeInsertionSort(container);
    double elapsedTime = getElapsedTime(start);

    displaySequence("After: ", container);
    std::cout << "Time to process a range of " << container.size() << " elements with " << containerName << ": "
              << std::fixed << std::setprecision(5) << elapsedTime << " us" << std::endl;
}

double PmergeMe::getElapsedTime(const std::clock_t &start) const
{
    return (std::clock() - start) / (double)CLOCKS_PER_SEC * 1000000; 
}

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