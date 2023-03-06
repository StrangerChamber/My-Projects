#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include <string>


using namespace std;

struct node//struct used to create the tables
{
    int key;
    struct node* next;
};

class HashTable//my class
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision =0;
    
    node* createNode(int key, node* next){// create node function
        node* newGuy = new node;
        newGuy->key = key;
        newGuy->next = next;
        return newGuy;
    };
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    //I put all the different insert and search methods into the same class 
    bool insertItemLinear(int key);//linear pribe
    bool insertItemQuad(int key);//quadratic probe
    bool insertItemChain(int key);//chaining
    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItemLinear(int key);//linear probe
    node* searchQuad(int key);//quadratic probe
    node* searchChain(int key);//chaining
};

#endif











HashTable::HashTable(int bsize){//constructor
    tableSize = bsize;
    table = new node * [bsize];
    for(int i = 0;i<bsize;i++){
        table[i] = NULL;
    }
}


unsigned int HashTable:: hashFunction(int key){//division method spelled out in write up
    return key%tableSize;
}


bool HashTable:: insertItemLinear(int key){//insert function with linear probing
    int hashIndex = hashFunction(key);
    if(table[hashIndex]!=NULL){
        numOfcolision++;
    }
    while(table[hashIndex]!=NULL){
        hashIndex++;
        if(hashIndex == tableSize){
            hashIndex = 0;
        }
    }
    node* newGuy = createNode(key, NULL);
    if(table[hashIndex] == NULL){
        table[hashIndex] = newGuy;
        cout << "insert success" << endl;
        return true;
    }
    else{
        cout << "insert fail" << endl;
        return false;
    }
}






bool HashTable:: insertItemQuad(int key){//insert method with quadratic probing
    int i = hashFunction(key);
    int index = i;
    if(table[index]!= NULL){
        numOfcolision++;
    }
    int a = 1;
    while(table[index] != NULL){
        index = (i + (a*a))%tableSize;
        a++;
    }
    node* newGuy = createNode(key,NULL);
    if(table[index]==NULL){
        table[index] = newGuy;
        cout << "insert success" << endl;
        return true;
    }
    else{
        cout << "insert hath failed" << endl;
        return false;
    }
}







bool HashTable:: insertItemChain(int key){// insert method for chaining
    int index = hashFunction(key);
    node* newGuy = createNode(key,NULL);
    if(table[index] == NULL){
        table[index] = newGuy;
        cout << "input successful" << endl;
        return true;
    }
    else{
        numOfcolision++;
        newGuy->next = table[index];
        table[index] = newGuy;
        cout << "input good"<<endl;
        return true;
    }
}








node* HashTable:: searchItemLinear(int key){//linear probing search method
    int hashIndex = hashFunction(key);
    if(table[hashIndex]->key == key){
        cout << "item found" << endl;
        return table[hashIndex];
    }
    numOfcolision++;
    while(table[hashIndex]->key!=key){
        hashIndex++;
        if(hashIndex == tableSize){
            hashIndex = 0;
        }
    }
    if(table[hashIndex]->key == key){
        cout << "item found" << endl;
        return table[hashIndex];
    }
    else{
        cout << "item not found" << endl;
        return NULL;
    }
}







node* HashTable::searchQuad(int key){//quadratic probing search
    int i = hashFunction(key);
    int index = i;
    if(table[index]->key == key){
        cout << "key found" << endl;
        return table[index];
    }
    numOfcolision++;
    int a = 1;
    while(table[index]->key!=key){
        index = (i +(a*a))%tableSize;
        a++;
    }
    if(table[index]->key == key){
        cout << "item found" << endl;
        return table[index];
    }
    else{
        cout << "item not found" << endl;
        return NULL;
    }
}




node* HashTable:: searchChain(int key){//chaining search function
    int index = hashFunction(key);
    if(table[index]->key == key){
        cout << "key found" << endl;
        return table[index];
    }
    numOfcolision++;
    node* crawler = table[index];
    while(crawler->next!=NULL){
        if(crawler->key == key){
            cout << "key found " << endl;
            return crawler;
        }
        crawler = crawler->next;
    }
}





void HashTable:: printTable(){//printing the table
    for(int i = 0; i<tableSize;i++){
        if(table[i] == NULL){
            cout << i<< ": " << "NULL" << ", ";
        }
        else{
            if(table[i]->next!=NULL){
                node* crawler = table[i];
                cout << i <<": ";
                while(crawler->next != NULL){
                    cout << crawler->key << ",";
                    crawler = crawler->next;
                }
            }
            cout << i<< ": "<< table[i]->key << ", ";
        }    
    }
    cout << endl<<"end of table" << endl;
}

int HashTable:: getNumOfCollision(){//get number of collisions
    int dummy = numOfcolision;
    numOfcolision = 0;// resetting number of collisions such that my data is recorded correctly to get collisions per 100 inserts and searches
    return dummy;
}