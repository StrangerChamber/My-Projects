#include "RPNCalculator.hpp"
#include <iostream>
using namespace std;

RPNCalculator :: RPNCalculator(){
    stackHead= NULL;
}
RPNCalculator:: ~RPNCalculator(){
    Operand* crawler = stackHead;
    while(crawler!=NULL){
        crawler = stackHead->next;
        delete stackHead;
        stackHead = crawler;
    }
}

bool RPNCalculator:: isEmpty(){
    if(stackHead == NULL){
        return true;
    }
    else{
        return false;
    }
}

void RPNCalculator:: push(float number){
    Operand* oldHead = stackHead;
    stackHead = new Operand;
    stackHead->next = oldHead;
    stackHead->number = number;
}

void RPNCalculator:: pop(){
    if(stackHead == NULL){
        cout << "Stack empty, cannot pop an item." << endl;
    }
    else{
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
}

Operand* RPNCalculator:: peek(){
    if(stackHead==NULL){
        cout <<"Stack empty, cannot peek." << endl;
        return NULL;
    }
    else{
        return stackHead;
    }
}

bool RPNCalculator:: compute(string symbol){
    if(symbol!= "+" && symbol!= "*"){
        cout << "err: invalid operation" << endl;
        return false;
    }
    else{
        if(stackHead == NULL || stackHead->next == NULL){
            cout << "err: not enough operands" << endl;
            return false;
        }
        else{
            float first = stackHead->number;
            pop();
            float second = stackHead->number;
            pop();
            if(symbol == "+"){
                float total = first + second;
                push(total);
            }
            if(symbol == "*"){
                float sum = first*second;
                push(sum);
            }
            return true;
        }
    }
}


