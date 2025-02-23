#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    this->_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, const std::string &op) const
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Invalid operator");
}

int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            _stack.push(std::stoi(token));
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
            {
                throw std::runtime_error("Invalid expression: insufficient operands");
            }
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            _stack.push(performOperation(a, b, token));
        }
        else
        {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    if (_stack.size() != 1)
    {
        throw std::runtime_error("Invalid expression: leftover operands");
    }

    return _stack.top();
}