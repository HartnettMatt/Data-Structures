#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  root = nullptr;
}

void deleteTree(MovieNode *mN){
  if(mN == nullptr){
    return;
  } else {
    deleteTree(mN->left);
    deleteTree(mN->right);
    delete mN;
    return;
  }
}
MovieTree::~MovieTree() {
  deleteTree(root);
}

void printTree(MovieNode *mN){
  if(mN == nullptr){
    return;
  } else {
    printTree(mN->left);
    cout << "Movie: " << mN->title << " " << mN->rating << endl;
    printTree(mN->right);
  }
}

void MovieTree::printMovieInventory() {
  if(root == nullptr){
    cout << "Tree is Empty. Cannot print" << endl;
  } else {
    printTree(root);
  }
}

void addHelper(MovieNode *currNode, MovieNode *nN){
  if(nN->title < currNode->title){
    if(currNode->left == nullptr){
      currNode->left = nN;
    }
    addHelper(currNode->left, nN);
  } else if(nN->title > currNode->title){
    if(currNode->right == nullptr){
      currNode->right = nN;
    }
    addHelper(currNode->right, nN);
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  MovieNode *nN = new MovieNode(ranking, title, year, rating);
  if(root == nullptr){
    root = nN;
  } else {
    addHelper(root, nN);
  }
}

void printInfo(MovieNode *mN){
  cout << "Movie Info:" << endl;
  cout << "==================" << endl;
  cout << "Ranking:" <<mN->ranking << endl;
  cout << "Title  :" << mN->title << endl;
  cout << "Year   :" << mN->year << endl;
  cout << "rating :" << mN->rating << endl;
}
void findHelper(MovieNode *currNode, string title){
  if(currNode == nullptr){
    cout << "Movie not found." << endl;
  } else {
    if(title.compare(currNode->title) == 0){
      printInfo(currNode);
    } else if (title < currNode->title){
      findHelper(currNode->left, title);
    } else if (title > currNode->title){
      findHelper(currNode->right, title);
    }
  }
}
void MovieTree::findMovie(string title) {
  findHelper(root, title);
}

void queryHelper(MovieNode *mN, float rating, int year){
  if(mN == nullptr){
    return;
  }
  if(mN->rating >= rating && mN->year > year){
    cout << mN->title << "(" << mN->year << ") " << mN->rating << endl;
  }
  queryHelper(mN->left, rating, year);
  queryHelper(mN->right, rating, year);
}
void MovieTree::queryMovies(float rating, int year) {
  if(root == nullptr){
    cout << "Tree is Empty. Cannot query Movies" << endl;
    return;
  }
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  queryHelper(root, rating, year);
}

float sum(MovieNode *m){
  if(m == nullptr){
    return 0.0;
  } else {
    return sum(m->left)+sum(m->right)+m->rating;
  }
}
int count(MovieNode *m){
  if(m == nullptr){
    return 0;
  } else {
    return count(m->left)+count(m->right)+1;
  }
}
void MovieTree::averageRating() {
  if(root == nullptr){
    cout << "Average rating:0.0" << endl;
  } else {
    float average = sum(root)/count(root);
    cout << "Average rating:" << average << endl;
  }
}
