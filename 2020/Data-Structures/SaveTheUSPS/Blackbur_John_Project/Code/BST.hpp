#include <iostream>
using namespace std;


struct Node{//struct for my bst
    int key;
    Node* right;
    Node* left;
};

class Tree{//tree class
    private:
        Node* root;
    public:
        Tree();  
        void insert(int key);
        void search(int key);
        void display();  
};


Tree::Tree(){//constructor setting root to null
    root = NULL;
}




Node* createNode(int key){// create node function
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right =NULL;
    return newNode;
}




Node* addHelp(Node* currNode,int key){//insert helper function
    if(currNode == NULL){//base case
        return createNode(key);
    }
    else if(key<currNode->key){//go left
        currNode->left = addHelp(currNode->left, key);
    }
    else if(key>currNode->key){//go right
        currNode->right = addHelp(currNode->right,key);
    }
    return currNode;
}

void Tree:: insert(int key){//insert function
    root = addHelp(root,key);
}




void printHelp(Node* currNode){//display helper
    if(currNode){
        printHelp(currNode->left);
        cout << currNode->key <<endl;
        printHelp(currNode->right);
    }
}

void Tree:: display(){//display function
    if(root == NULL){
        cout << "tree empty" << endl;
        return;
    }
    printHelp(root);
}




void find(int key, Node* currNode){//search helper function
    if(currNode->key == key){
        cout << "key found" << endl;
        return;
    }
    if(key<currNode->key && currNode->left !=NULL){
        find(key,currNode->left);//recurse left
    }
    if(key>currNode->key && currNode->right != NULL){
        find(key,currNode->right);//recurse right
    }
    return;
}


void Tree:: search(int key){//search function
    find(key,root);
}