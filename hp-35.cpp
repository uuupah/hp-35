/**
 * hp-35 emulator - version 1 (25/8/19)
 * made by jonathan souter - 
 */

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

//========================================== CLASS DEFINITIONS ==========================================//

class HPStack
{
public:
    HPStack();
    void push(double);
    double pop();
    double peek();
    double get_memory();
    void set_memory(double);
    void swap();
    void roll();
    void enter();
    void view();

private:
    double stack_[4];
    double memory_;
};

//======================================== METHOD IMPLEMENTATION ========================================//

// default constructor
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

double HPStack::get_memory()
{
    return memory_;
}

void HPStack::set_memory(double input)
{
    memory_ = input;
}

void HPStack::swap()
{
    double temp;
    temp = stack_[0];
    stack_[0] = stack_[1];
    stack_[1] = temp;
}

void HPStack::roll()
{
    double temp;
    temp = stack_[0];
    stack_[0] = stack_[1];
    stack_[1] = stack_[2];
    stack_[2] = stack_[3];
    stack_[3] = temp;
}

void HPStack::enter()
{
    stack_[3] = stack_[2];
    stack_[2] = stack_[1];
    stack_[1] = stack_[0];
}

void HPStack::view()
{
    cout << "x > " << stack_[0] << endl;
    cout << "y > " << stack_[1] << endl;
    cout << "z > " << stack_[2] << endl;
    cout << "t > " << stack_[3] << endl;
}

//========================================== MAIN FUNCTION ===============================================//

int main(int argc, char *argv[])
{
    HPStack stack;
    string line;
    while (getline(cin, line))
    {
        stringstream expression(line);
        string token;
        while (expression >> token)
        {
            if (isdigit(token[0]))
            {
                stack.push(atof(token.data()));
            }

            // basic arithmetic operators
            else if (token == "+")
            {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y + x);
            }
            else if (token == "-")
            {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y - x);
            }
            else if (token == "*")
            {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y * x);
            }
            else if (token == "/")
            {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y / x);
            }

            // scientific mathematic operators
            else if (token == "PI" || token == "pi") // pi
            {
                stack.push(M_PI);
            }
            else if (token == "CHS" || token == "chs") // change sign
            {
                double x = stack.pop();
                stack.push(x * -1);
            }
            else if (token == "RECIP" || token == "recip") // reciprocal
            {
                double x = stack.pop();
                stack.push(1 / x);
            }
            else if (token == "LOG" || token == "log") // decimal logarithm
            {
                double x = stack.pop();
                stack.push(log10(x));
            }
            else if (token == "LN" || token == "ln") // natural logarithm
            {
                double x = stack.pop();
                stack.push(log(x));
            }
            else if (token == "EXP" || token == "exp") // exponential function
            {
                double x = stack.pop();
                stack.push(exp(x));
            }
            else if (token == "SQRT" || token == "sqrt") // square root
            {
                double x = stack.pop();
                stack.push(sqrt(x));
            }
            else if (token == "SIN" || token == "sin") // sine
            {
                double x = stack.pop();
                stack.push(sin(x));
            }
            else if (token == "COS" || token == "cos") // cosine
            {
                double x = stack.pop();
                stack.push(cos(x));
            }
            else if (token == "TAN" || token == "tan") // tangent
            {
                double x = stack.pop();
                stack.push(tan(x));
            }
            else if (token == "ARCSIN" || token == "arcsin") // arc sine
            {
                double x = stack.pop();
                stack.push(asin(x));
            }
            else if (token == "ARCCOS" || token == "arccos") // arc cosine
            {
                double x = stack.pop();
                stack.push(acos(x));
            }
            else if (token == "ARCTAN" || token == "arctan") // arc tangent
            {
                double x = stack.pop();
                stack.push(atan(x));
            }
            else if (token == "POW" || token == "pow") // power function
            {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(pow(x, y));
            }

            // memory management functions
            else if (token == "STO" || token == "sto") // store x to memory
            {
                double x = stack.peek();
                stack.set_memory(x);
            }
            else if (token == "RCL" || token == "rcl") // recall from memory
            {
                double x = stack.get_memory();
                stack.push(x);
            }
            else if (token == "CLR" || token == "clr") // clear stack
            {
                for (int i = 0; i < 4; i++)
                {
                    stack.push(0);
                }
            }
            else if (token == "CLX" || token == "CLx" || token == "clx") // drop x value
            {
                stack.pop();
            }

            // stack control functions
            else if (token == "SWAP" || token == "swap") // swap x and y
            {
                stack.swap();
            }
            else if (token == "ROLL" || token == "roll")
            {
                stack.roll();
            }
            else if (token == "ENTER" || token == "enter")
            {
                stack.enter();
            }
            else if (token == "VIEW" || token == "view")
            {
                stack.view();
            }
        }
        cout << stack.peek() << endl;
    }

    return 0;
}