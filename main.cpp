#include <iostream>
#include "array_digram_stack.h"
#include "DigramLinkedStack.h"

using namespace std;

int main()
{
    //array/table limited size implementation test
    DigramStack arrayStack;
    arrayStack.push("ab");
    arrayStack.push("cd");
    std::cout << std::endl << arrayStack.pop();
    std::cout << std::endl << arrayStack.pop();
    std::cout << std::endl << arrayStack.pop();

    //object theoretically infinite size implementation test
    std::cout << std::endl << "Starting object test: ";
    DigramLinkedStack objectStack;
    objectStack.push("ab");
    objectStack.push("c");
    objectStack.pop();
    objectStack.push("de");
    objectStack.push("f ");
    objectStack.push("g.");
    objectStack.push("hi");

    //checking that all values are correct:
    std::cout << std::endl << "Array Stack Contents: ";
    arrayStack.printArrayStack();
    std::cout << std::endl << "Object Stack Contents: ";
    objectStack.printLinkedStack();
    return 0;
}
