#ifndef ARRAY_DIGRAM_STACK_H_INCLUDED
#define ARRAY_DIGRAM_STACK_H_INCLUDED

#include <string>

class DigramStack
{
    std::string digramStack[4] = {""};
    int currentStackTop = -1;
    public:
        void push(std::string);
        std::string pop();
        bool isEmpty();
        bool isFull();
        void printArrayStack();
};


#endif // ARRAY_DIGRAM_STACK_H_INCLUDED
