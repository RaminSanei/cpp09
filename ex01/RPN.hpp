#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>

class RPN
{
private:
    bool isOperator(const std::string &token) const;
    int performOperation(int a, int b, const std::string &op) const;
    std::stack<double> _stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    int evaluate(const std::string &expression);
};

#endif