#include "array_digram_stack.h"
#include <iostream>
#include <string>

bool DigramStack::isEmpty()
{
    if (DigramStack::currentStackTop == -1)
    {
        return true;
    }
    return false;
}

bool DigramStack::isFull()
{
    if (DigramStack::currentStackTop == 3)
    {
        return true;
    }
    return false;
}

void DigramStack::push(std::string newDigram)
{
    if (DigramStack::isFull())
    {
        std::cout << "\nerror, overflow";
        return;
    }
    if (newDigram.length() != 2)
    {
        std::cout << "\nNot a digram, cannot push!";
        return;
    }
    DigramStack::digramStack[DigramStack::currentStackTop + 1] = newDigram;
    DigramStack::currentStackTop++;
}

std::string DigramStack::pop()
{
    if (DigramStack::isEmpty())
    {
        std::cout << "error, underflow\n";
        return "";
    }
    std::string returnDigram = DigramStack::digramStack[DigramStack::currentStackTop];
    DigramStack::digramStack[DigramStack::currentStackTop] = "";
    DigramStack::currentStackTop--;
    return returnDigram;
}

void DigramStack::printArrayStack()
{
    if (DigramStack::currentStackTop == -1)
    {
        std::cout << "\nStack is empty.";
    }
    for (int i = 0; i < DigramStack::currentStackTop; i++)
    {
        std::cout << std::endl << DigramStack::digramStack[i];
    }
}
