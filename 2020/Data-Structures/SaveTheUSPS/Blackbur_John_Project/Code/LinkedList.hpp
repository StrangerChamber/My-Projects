#include <iostream>
using namespace std;

struct Node{//struct used for LL
    int key;
    Node * next;
};

class LL{// class to build insert display and search
    public:
    LL();
    void insert(int key);
    void search(int key);
    void display();
    private:
    Node* head;
};

LL:: LL(){
    head = NULL;
}

void LL:: insert(int key){//inserting at the end of the LL each time 
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        Node* crawler = head;
        while(crawler->next!=NULL){
            crawler = crawler->next;
        }
        crawler->next = newNode;
    }
}


void LL:: search(int key){//search for desired node
    Node* crawler = head;
    while(crawler!=NULL){
        if(crawler->key == key){
            return;
        }
        crawler = crawler->next;
    }
    cout << "Mail Not Found :(" << endl;
}

void LL:: display(){//display function
    Node* crawler = head;
    while(crawler!=NULL){
        cout << crawler->key << ", ";
        crawler = crawler->next;
    }
    cout << "end"<< endl;
}

