#ifndef DIGRAMLINKEDSTACK_H
#define DIGRAMLINKEDSTACK_H

#include <memory>

class DigramLinkedStack
{
    struct Digram
    {
        char firstChar, secondChar;
        Digram()
        {
            firstChar = '-';
            secondChar = '-';
        }
    };
    struct StackNode
    {
        Digram value;
        StackNode* next = nullptr;
    };
    StackNode* bottom = nullptr;
    StackNode* top = nullptr;
    int length = -1;
    int updateNodeValue(StackNode*, char*);
    int printNodeValue(StackNode*) const;
    public:
        DigramLinkedStack();
        ~DigramLinkedStack();
        int push(char*);
        int pop();
        int printLinkedStack() const;
};

#endif // DIGRAMLINKEDSTACK_H
