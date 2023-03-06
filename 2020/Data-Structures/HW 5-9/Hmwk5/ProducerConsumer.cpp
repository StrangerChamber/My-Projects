#include <iostream>
#include "ProducerConsumer.hpp"
using namespace std;

ProducerConsumer:: ProducerConsumer(){
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer:: isEmpty(){
    if(counter==0){
        return true;
    }
    else{
        return false;
    }
}

bool ProducerConsumer:: isFull(){
    if(counter == 20){
        return true;
    }
    else{
        return false;
    }
}

void ProducerConsumer:: enqueue(string item){
    if(isFull() == false){
        counter++;
        queue[queueEnd] = item;
        if(queueEnd == 19){
            queueEnd = 0;
        }
        else{
            queueEnd++;
        }
    }
    else{
        cout << "Queue full, cannot add new item" << endl;
    }
}

void ProducerConsumer:: dequeue(){
    if(isEmpty() == false){
        counter--;
        queue[queueFront] = "";
        if(queueFront == 19){
            queueFront = 0;
        }
        else{    
            queueFront++;
        }
    }
    else{
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
}

string ProducerConsumer:: peek(){
    if(isEmpty()==true){
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
    else{
        return queue[queueFront];
    }
}

int ProducerConsumer:: queueSize(){
    return counter;
}

/*int ProducerConsumer:: getQueueFront(){
    return queueFront;
}

int ProducerConsumer:: getQueueEnd(){
    return queueEnd;
}

string* ProducerConsumer::getQueue(){
    return queue;
}*/







