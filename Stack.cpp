//
// Created by Amin on 2019-10-10.
//

#include "Stack.h"

template<class T>
Stack<T>::Stack(int size) {
    this->size = size ;
    this->top = -1 ;
    this->arr = new T[size] ;
}


template <class T>
bool Stack<T>::is_empty() {
    if(top == -1) return true ;
    return false ;
}

template <class T>
bool Stack<T>::is_full() {
    if(top == size - 1) return true ;
    return false ;
}

template <class T>
void Stack<T>::push(T value){
    std::cout << is_full() ;
    if (!is_full()) this->arr[++top] = value ;
    else throw "stack is full" ;

}

template <class T>
T Stack<T>::pop() {
    if (!is_empty()) return this->arr[top--] ;
    throw "stack is empty" ;
}

template <class T>
Stack<T>::~Stack() {
    delete [] this->arr ;
}
