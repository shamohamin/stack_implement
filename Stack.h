//w
// Created by Amin on 2019-10-10.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template  <class T>
class Stack {
private:
    int size ;
    int top ;
    T *arr ;
public:
    Stack(int);
    ~Stack();
    bool is_full() ;
    bool is_empty() ;
    void push(T) ;
    T pop();
};


#endif //STACK_STACK_H
