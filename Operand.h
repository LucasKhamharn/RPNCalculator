//
//  Operand.h
//  RPN Calculator
//
//  Created by Lucas on 3/28/24.
//

#pragma once

class Operand
{
public:
    virtual ~Operand();
};


class Number : public Operand
{
public:
    Number(double v);
    double value;
};


class Operator : public Operand
{
    //nothing here
};


class Add : public Operator
{
    // nothing here
};


class Subtract : public Operator
{
    // nothing here
};


class Multiply : public Operator
{
    // nothing here
};


class Divide : public Operator
{
    // nothing here
};


class Square : public Operator
{
    // nothing here
};
