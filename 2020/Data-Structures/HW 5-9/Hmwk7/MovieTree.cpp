#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}

void destruct(TreeNode* currNode){
    if(currNode == NULL){
        return;
    }
    destruct(currNode->leftChild);
    destruct(currNode->rightChild);
    LLMovieNode* crawler = currNode->head;
    while(crawler!= NULL){
        LLMovieNode* temp = crawler;
        crawler = crawler->next;
        delete temp;
    }
    delete currNode;
}

MovieTree::~MovieTree()
{
    destruct(root);
}

///////////////

void PrintLL(TreeNode* currNode){
    cout << "Movies starting with letter: " << currNode->titleChar << endl;
    LLMovieNode* crawler = currNode->head;
    while(crawler!= NULL){
        cout << " >> " << crawler->title << " " << crawler->rating << endl;
        crawler = crawler->next;
    }
}

void printHelper(TreeNode* currNode){
    if(currNode == NULL){
        return;
    }
    printHelper(currNode->leftChild);
    PrintLL(currNode);
    printHelper(currNode->rightChild);
}

void MovieTree::printMovieInventory() // need to do left root right traversal(inorder)
{
    printHelper(root);
}


//////////////////


TreeNode* createNode(char titlechar){
    TreeNode* temp = new TreeNode;
    temp->titleChar = titlechar;
    return temp;
}

LLMovieNode* newMovie(LLMovieNode* currNode, int ranking, string title, int year, float rating){
    LLMovieNode* crawler = currNode;
    LLMovieNode* prev = currNode;
    LLMovieNode* head = currNode;
    while(crawler!= NULL && crawler->title<title){
        prev = crawler;
        crawler = crawler->next;
    }
    if(crawler == prev){//head insert
        LLMovieNode* temp = crawler;
        crawler = new LLMovieNode(ranking, title, year, rating);
        crawler->next = temp;
        return crawler;
    }
    LLMovieNode* tempy = crawler;
    crawler = new LLMovieNode(ranking, title, year, rating);
    prev->next = crawler;
    crawler->next = tempy;
    return head;
}

TreeNode* addHelp(TreeNode* currNode, int ranking, string title, int year, float rating){
    if(currNode == NULL){// empty tree or no node with letter
        currNode = createNode(title[0]);
        currNode->head = new LLMovieNode(ranking, title, year, rating);
        return currNode;
    }
    else if(currNode->titleChar>title[0]){//go left
        TreeNode* lChild = addHelp(currNode->leftChild, ranking, title, year, rating);
        currNode->leftChild = lChild;
        lChild->parent = currNode;
    }
    else if(currNode->titleChar<title[0]){//go right
        TreeNode* RChild = addHelp(currNode->rightChild, ranking, title, year, rating);
        currNode->rightChild = RChild;
        RChild->parent = currNode;
    }
    else if(currNode->titleChar == title[0]){// match
       currNode->head = newMovie(currNode->head, ranking, title, year, rating);
    }
    return currNode;
}


void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
    root = addHelp(root,ranking, title, year, rating);
}


/////////////////

LLMovieNode* LLT(LLMovieNode* currNode,string title){
    LLMovieNode* head = currNode;
    LLMovieNode* prev = currNode;
    LLMovieNode* crawler = currNode;
    while(crawler->title != title){
        if(crawler == NULL){
            cout << "Movie: " << title << " not found, cannot delete." << endl; 
            return NULL;
        }
        prev = crawler;
        crawler = crawler->next;
    }
    if(prev == crawler){
        LLMovieNode* tempy = crawler->next;
        delete crawler;
        crawler = tempy;
        return crawler;
    }
    LLMovieNode* temp = crawler->next;
    delete crawler;
    prev->next = temp;
    return head;
}

TreeNode* getMin(TreeNode* currNode){
    TreeNode* temp = currNode;
    while(temp->leftChild!= NULL){
        temp = temp->leftChild;
    }
    return temp;
}

void replacer(TreeNode* currNode){
    TreeNode* temp = currNode;
    TreeNode* prev = currNode;
    while(temp->leftChild!= NULL){
        temp = temp->leftChild;
    }
    prev = temp->parent;
    if(temp->rightChild!= NULL){
        temp->rightChild->parent = prev;
        prev->leftChild = temp->rightChild;
    }
    delete temp;
}

TreeNode* deleteHelper(TreeNode* currNode, string title){
    if(currNode == NULL){
        return NULL;
    }
    else if(title[0]<currNode->titleChar){
        currNode->leftChild = deleteHelper(currNode->leftChild, title);
    }
    else if(title[0]>currNode->titleChar){
        currNode->rightChild = deleteHelper(currNode->rightChild, title);
    }
    else{
        currNode->head = LLT(currNode->head,title);
        if(currNode->head == NULL){
            if(currNode->leftChild == NULL && currNode->rightChild == NULL){
                delete currNode;
                return NULL;
            } 
            else if(currNode->leftChild == NULL && currNode->rightChild != NULL){
                TreeNode* righty = currNode->rightChild;
                righty->parent = currNode->parent;
                delete currNode;
                return righty;
            }
            else if (currNode->leftChild!= NULL && currNode->rightChild == NULL){
                TreeNode* lefty = currNode->leftChild;
                lefty->parent = currNode->parent;
                delete currNode;
                return lefty;
            }
            else{
                TreeNode* rsm = getMin(currNode->rightChild);
                currNode->titleChar = rsm->titleChar;
                currNode->head = rsm->head;
                replacer(currNode->rightChild);
            } 
        }
    }
    return currNode;
}



void MovieTree::deleteMovie(std::string title)
{
    if(root ==  NULL){
        cout << "Movie: " << title << " not found, cannot delete." << endl; 
        return;
    }
    root = deleteHelper(root, title);
}


/////////////////


void MovieTree::leftRotation(TreeNode* curr)
{
    if(curr->rightChild == NULL){
        return;
    }
    TreeNode* moveUp = curr->rightChild;
    if(curr == root){
        root = moveUp;
        curr->parent = moveUp;
        moveUp->parent = NULL;
        curr->rightChild = moveUp->leftChild;
        moveUp->leftChild = curr;
        return;
    }
    TreeNode* temp = curr->parent;
    curr->parent = moveUp;
    moveUp->parent = temp;
    curr->rightChild = moveUp->leftChild;
    moveUp->leftChild = curr;
    if(moveUp->head->title>temp->head->title){
        temp->rightChild = moveUp;
    }
    else{
        temp->leftChild = moveUp;
    }
    return;
}




//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode * root)
{
	if (root == NULL) {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}
