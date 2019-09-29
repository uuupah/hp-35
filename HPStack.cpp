#include "HPStack.h"

// initialise class variables
HPStack::HPStack()
{
    for (int i = 0; i < 4; i++)
    {
        stack_[i] = 0;
    }
}

// add input to the bottom of the stack and push every other item up one step
void HPStack::push(double input) 
{
    stack_[3] = stack_[2];
    stack_[2] = stack_[1];
    stack_[1] = stack_[0];
    stack_[0] = input;
}

// remove the item at the bottom of the stack and move every item down one step
double HPStack::pop()
{
    double output = stack_[0];
    stack_[0] = stack_[1];
    stack_[1] = stack_[2];
    stack_[2] = stack_[3];
    return output;
}

// return item at bottom of stack
double HPStack::peek()
{
    return stack_[0];
}