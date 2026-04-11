#include "RPN.hpp"

bool isOperator(const std::string &token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int applyOperation(int a, int b, const std::string &op)
{
    long c = static_cast<long>(a);
    long d = static_cast<long>(b);
    if (op == "+")
    {
        if (c + d > 2147483647 || c + d < -2147483648)
            throw std::runtime_error("Error: OVERFLOW.");
        return a + b;
    }
    if (op == "-")
    {
        if (c - d > 2147483647 || c - d < -2147483648)
            throw std::runtime_error("Error: OVERFLOW.");
        return a - b;
    }
    if (op == "*")
    {
        if (c * d > 2147483647 || c * d < -2147483648)
            throw std::runtime_error("Error: OVERFLOW.");
        return a * b;
    }
    if (op == "/")
    {
        if (d == 0)
            throw std::runtime_error("Error: Division by zero.");
        if (c / d > 2147483647 || c / d < -2147483648)
            throw std::runtime_error("Error: OVERFLOW.");
        return a / b;
    }
    throw std::runtime_error("Error: Invalid operator.");
}

int evaluateRPN(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) && token.size() == 1)
            stack.push(token[0] - '0');
        else if (isOperator(token))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Not enough operands.");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(applyOperation(a, b, token));
        } 
        else
            throw std::runtime_error("Error: Invalid token.");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression.");
    return stack.top();
}