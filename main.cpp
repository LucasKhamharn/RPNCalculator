//
//  main.cpp
//  RPN Calculator
//
//  Created by Lucas on 3/28/24.
//

#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept> // for std::runtime_error
#include "Operand.h"

double Calculate(std::queue<Operand*> q)
{
    std::stack<double> s;
    
    while (q.empty() == false)
    {
        Operand* o = q.front();
        q.pop();
        
        Number* n = dynamic_cast<Number*>(o);
        
        if ( n != nullptr)
        {
            s.push(n->value);
        }
        else if (dynamic_cast<Add*>(o) != nullptr)
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(a + b);
        }
        else if (dynamic_cast<Subtract*>(o) != nullptr)
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(b - a);
        }
        else if (dynamic_cast<Multiply*>(o) != nullptr)
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(a * b);
        }
        else if (dynamic_cast<Divide*>(o) != nullptr)
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(b / a);
        }
        else if (dynamic_cast<Square*>(o) != nullptr)
        {
            double a = s.top();
            s.pop();
            s.push(a * a);
        }
    }
    if (s.size() != 1)
    {
        throw std::runtime_error("Stack contains wrong number of elements!");
    }
    return s.top();
}


int main()
{
    std::queue<Operand*> a;
    a.push(new Number (1));
    a.push(new Number (2));
    a.push(new Square());
    a.push(new Multiply());
    std::cout << Calculate(a) << std::endl;
    
    
    return 0;
}
