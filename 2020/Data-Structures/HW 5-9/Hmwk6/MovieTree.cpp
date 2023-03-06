#include "MovieTree.hpp"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  root = NULL;
}

void destroyTree(MovieNode* node){
  if(node == NULL){
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}

MovieTree::~MovieTree() {
  destroyTree(root);
  root = NULL;
}

void printTreeHelper(MovieNode* currNode){
  if(currNode){
    printTreeHelper(currNode->left);
    cout << "Movie: " << currNode->title << " " << currNode->rating << endl;
    printTreeHelper(currNode->right);
  }
}

void MovieTree::printMovieInventory() {
  if(root==NULL){
    cout << "Tree is empty. Cannot print" << endl;
    return;
  }
  else{
    printTreeHelper(root);
  }
}

MovieNode* createNode(int ranking, string title, int year, float rating){
  MovieNode* newbie = new MovieNode(ranking, title, year, rating);
  return newbie;
}

MovieNode* addHelper(MovieNode* currNode, int ranking, string title, int year, float rating){
  string s1(title);
  if(currNode == NULL){
    return createNode(ranking, title, year, rating);
  }
  else if(s1.compare(currNode->title)<0){// go left before in the alphabet 
    currNode->left = addHelper(currNode->left, ranking, title, year, rating);
  }
  else if(s1.compare(currNode->title)>0){// go right after in the alphabet
    currNode->right = addHelper(currNode->right, ranking, title, year, rating);
  }
  return currNode;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  root = addHelper(root, ranking, title, year, rating);
}

void titleFinder(string title, MovieNode* currNode, int* count){
  if(currNode->title == title){
    cout << "Movie Info: " << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << currNode->ranking << endl;
    cout << "Title  :" << currNode->title << endl;
    cout << "Year   :"<< currNode->year << endl;
    cout << "rating :"<< currNode->rating << endl;
    *count = 1;
    return;
  }
  if(currNode->left != NULL){
    titleFinder(title, currNode->left, count);
  }
  if(currNode->right != NULL){
    titleFinder(title, currNode->right, count);
  }
  return;
}

void MovieTree::findMovie(string title) {
  int counter = 0;
  int* count = &counter;
  titleFinder(title, root, count);
  if(counter == 0){
      cout << "Movie not found." << endl;
  }
}

void queryHelper(MovieNode* node, float rating, int year){
  if(node == NULL){
    return;
  }
  if(node->rating>=rating && node->year>year){
    cout << node->title << "(" << node->year << ") " << node->rating << endl;
  }
  queryHelper(node->left, rating, year);
  queryHelper(node->right, rating, year);
  return;
}

void MovieTree::queryMovies(float rating, int year) {
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  if(root == NULL){
    cout << "Tree is empty. Cannot query Movies" << endl;
  }
  else{
    queryHelper(root, rating, year);
  }    
}

float averageHelper(MovieNode* node, float* total, int* counter){// give me total ratings summed
  if(node == NULL){
    return 0;
  }
  *counter = *counter + 1;
  *total = *total + node->rating;
  averageHelper(node->left,total,counter);
  averageHelper(node->right,total, counter);
  return *total;
}

void MovieTree::averageRating(){
  if(root == NULL){
    cout << "Average rating:0.0" << endl;
  }
  else{
    float total = 0;
    int counter = 0;
    int* nodeCount = &counter;
    float* tCount = &total;
    averageHelper(root, tCount, nodeCount);
    float average = total/counter;
    cout << "Average rating:" << average << endl;
  }
}

void levelHelper(MovieNode* node, int level){
  if(node == NULL){
    return;
  }
  if(level == 0){
    cout << "Movie: " << node->title << " " << node->rating << endl;
  }
  else{
    levelHelper(node->left, level-1);
    levelHelper(node->right, level-1);
  }
}

void MovieTree::printLevelNodes(int level) {
  if(level == 0){
    cout<< "Movie: " << root->title <<" " << root->rating <<endl;
  }
  else{
  levelHelper(root,level);
  }
}