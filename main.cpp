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
void pop_inside_practense() ;

int main() {

    precedence['+'] = 1 ;
    precedence.insert(pair<char , int>('-' , 1)) ;
    precedence['/'] = 2 ;
    precedence['*'] = 2 ;
    precedence['^'] = 3 ;

    string infix= "a+b*(c^d-e)^(f+g*h)-i" ;

    try {
        for (int i = 0; i < infix.length(); i++) {
            char hold = infix.at(i);
            if (!find_operator((char) hold) && hold != '(' && hold != ')') postfix += hold;
            else {
                if(hold == '('){
                    operators->push(hold);
                    last_precedence = 0 ;
                }else if(hold == ')'){
                    pop_inside_practense() ;
                }else{
                    if(checker(hold)) operators->push(hold) ;
                    else pop_operators(hold) ;
                }
            }
        }
    }catch (const char *err){
        cout << err << endl ;
    }

    while(!operators->is_empty()){
        postfix += operators->pop() ;
    }

    cout << postfix ;

    return 0;
}

//this functions is for poping inside the prantense
void pop_inside_practense(){
    char operators_inside_stack = ' ' ;

    while(operators_inside_stack != '('){
        operators_inside_stack = operators->pop() ;
        if (operators_inside_stack == '(' || operators_inside_stack == ')'){
            continue ;
        }
        postfix += operators_inside_stack ;
    }
    operators_inside_stack = operators->pop() ;
    map<char , int>::iterator it ;
    it = precedence.find(operators_inside_stack) ;
    last_precedence = it->second ;
    operators->push(operators_inside_stack) ;
}

//this function is for pop and insert operators to post fix expression
void pop_operators(char scanned_operator){

    map<char , int >::iterator it ;

    while(1){
        char operator_precedence = operators->pop() ;
        it = precedence.find(operator_precedence) ;
        last_precedence = it->second ;
        if(checker(scanned_operator)) {
            operators->push(operator_precedence);
            operators->push(scanned_operator);
            break;
        }else if (operators->is_empty()){
            postfix += operator_precedence ;
            last_precedence = 0 ;
            operators->push(operator_precedence) ;
            break ;
        }else if(operator_precedence == '('){
            last_precedence = 0 ;
            operators->push(operator_precedence) ;
            operators->push(scanned_operator) ;
            break ;
        }
        postfix += operator_precedence ;
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