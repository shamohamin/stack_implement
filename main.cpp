#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> *stack = new Stack<int>(3) ;
    try{
        stack->push(1) ;
        stack->push(2) ;
        stack->push(3) ;
        cout << stack->pop() << endl  ;
        cout << stack->pop() << endl ;
        cout << stack->pop() << endl ;
    }catch(const char *err){
        cout << err << endl ;
    }

    return 0;
}