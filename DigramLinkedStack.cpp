#include "DigramLinkedStack.h"
#include <memory>
#include <iostream>


DigramLinkedStack::DigramLinkedStack()
{
    DigramLinkedStack::bottom = new DigramLinkedStack::StackNode;
}

DigramLinkedStack::~DigramLinkedStack()
{
    if (DigramLinkedStack::top == nullptr)
    {
        delete DigramLinkedStack::bottom;
    }
    else
    {
        while (DigramLinkedStack::top != DigramLinkedStack::bottom)
        {
            StackNode* tempNode = DigramLinkedStack::top->next;
            delete DigramLinkedStack::top;
            DigramLinkedStack::top = tempNode;
        }
        delete DigramLinkedStack::bottom;
    }
}

int DigramLinkedStack::updateNodeValue(StackNode* nodeToFix, char* newValue)
{
    try
    {
        if (int(newValue[0]) < 97 or int(newValue[0]) > 122)
        {
            nodeToFix->value.firstChar = newValue[1];
            nodeToFix->value.secondChar = ' ';
        }
        else
        {
            nodeToFix->value.firstChar = newValue[0];
            if (int(newValue[1]) == 0)
            {
                return 0;
            }
            if (int(newValue[1]) < 97 or int(newValue[1]) > 122)
            {
                nodeToFix->value.secondChar = ' ';
            }
            else
            {
                nodeToFix->value.secondChar = newValue[1];
            }
        }
        return 0;

    }
    catch(...)
    {
        return -1;
    }
}

int DigramLinkedStack::printNodeValue(StackNode* nodeToPrint) const
{
    if (nodeToPrint == nullptr)
    {
        std::cout << "\nDigram does not exist.";
        return -1;
    }
    std::cout << std::endl << nodeToPrint->value.firstChar;
    if (nodeToPrint->value.secondChar != '-')
    {
        std::cout << nodeToPrint->value.secondChar;
    }
    return 0;
}

int DigramLinkedStack::printLinkedStack() const
{
    StackNode* stackIterator = DigramLinkedStack::top;
    if (stackIterator == nullptr)
    {
        std::cout << "\nStack is empty.";
        return 0;
    }
    else
    {
        while (stackIterator != DigramLinkedStack::bottom)
        {
            DigramLinkedStack::printNodeValue(stackIterator);
            stackIterator = stackIterator->next;
        }
        DigramLinkedStack::printNodeValue(stackIterator);
        return 0;
    }
    return -1;
}

int DigramLinkedStack::push(char* newDigram)
{
    if (DigramLinkedStack::length == 3)
    {
        std::cout << "\nerror, overflow";
        return -3;
    }
    try
    {
        if (DigramLinkedStack::top == nullptr)
        {
            DigramLinkedStack::updateNodeValue(DigramLinkedStack::bottom, newDigram);
            DigramLinkedStack::top = DigramLinkedStack::bottom;
            DigramLinkedStack::length++;
            return 0;
        }
        else
        {
            DigramLinkedStack::StackNode* newNode = new DigramLinkedStack::StackNode;
            DigramLinkedStack::updateNodeValue(newNode, newDigram);
            newNode->next = DigramLinkedStack::top;
            DigramLinkedStack::top = newNode;
            DigramLinkedStack::length++;
            return 0;
        }
    }
    catch(...)
    {
        return -1;
    }
    return -2;
}

int DigramLinkedStack::pop()
{
    if (DigramLinkedStack::top == nullptr)
    {
        std::cout << "\nerror, underflow";
        return -1;
    }
    else
    {
        DigramLinkedStack::printNodeValue(DigramLinkedStack::top);
        if (DigramLinkedStack::top->next != nullptr)
        {
            StackNode* tempNode = DigramLinkedStack::top->next;
            delete DigramLinkedStack::top;
            DigramLinkedStack::top = tempNode;
        }
        else
        {
            DigramLinkedStack::top = nullptr;
        }
        DigramLinkedStack::length--;
        return 0;
    }
    return -2;
}
