#include <iostream>
#include "array_digram_stack.h"
#include "DigramLinkedStack.h"

using namespace std;

int main()
{
    std::cout << "Test 1 (Array):";
    //array/table limited size implementation test
    DigramStack arrayStack;
    arrayStack.push("ab");
    arrayStack.push("cd");
    std::cout << std::endl << arrayStack.pop();
    std::cout << std::endl << arrayStack.pop();
    std::cout << std::endl << arrayStack.pop();

    std::cout << "Test 2 (Linked List):";
    //object theoretically infinite size (although has forced overflow checker) implementation test
    std::cout << std::endl << "Starting object test: ";
    DigramLinkedStack objectStack;
    objectStack.push("ab");
    objectStack.push("c");
    objectStack.pop();
    objectStack.push("de");
    objectStack.push("f ");
    objectStack.push("g.");
    objectStack.push("hi");

    return 0;
}
