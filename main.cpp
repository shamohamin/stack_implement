#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "map"
#include "iterator"
#include "string"
#define size 80
using namespace std ;

map <char,int> precedence ;
Stack<char> *operators = new Stack<char>(size) ;
int last_precedence = 0 ;
string postfix = "";

bool find_operator(char) ;
bool checker(char) ;
void pop_operators(char) ;

int main() {

    precedence['+'] = 1 ;
    precedence.insert(pair<char , int>('-' , 1)) ;
    precedence['/'] = 2 ;
    precedence['*'] = 2 ;
    precedence['^'] = 3 ;

    string infix= "1-2^3^3-(4+5*6)*7" ;

    for(int i = 0 ; i < infix.length() ; i++){
        char hold = infix.at(i) ;
        if(!find_operator((char)hold)) postfix += hold ;
        else{
            if (checker((char)hold) || hold == '(' ) operators->push((char)hold) ;
            else {
                pop_operators(hold) ;
                if(hold != ')'){
                    operators->push(hold) ;
                }
            }
        }
    }

    return 0;
}

//this function is for pop and insert operators to post fix expression
void pop_operators(char scanned_operator){

    map<char , int >::iterator it ;

    while(1){
        char operator_precedence = operators->pop() ;
        it = precedence.find(operator_precedence) ;
        last_precedence = it->second ;
        if(checker(scanned_operator)) {
            operators->push(operator_precedence) ;
            break ;
        }else if(operator_precedence == '(' || operator_precedence == ')'){
            break ;
        }else{
            postfix += operator_precedence ;
            continue ;
        }
    }
}

//this function is for precedence check
bool checker(char precedence_char){

    map<char , int>::iterator it ;
    it = precedence.find(precedence_char) ;

    if(it->second > last_precedence){
        last_precedence = it->second ;
        return true ;
    }
    return false ;
}

//this function is for recognition of operators
bool find_operator(char single){
    switch(single){
        case '*' :
        case '+' :
        case '-' :
        case '/' :
        case '^' :
            return true ;
        default:
            return false ;
    }
}