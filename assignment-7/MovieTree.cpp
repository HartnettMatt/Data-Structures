#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

MovieTree::MovieTree() {
  root = nullptr;
}
void llDelete(LLMovieNode *LLmn){
  if(LLmn != nullptr){
    delete LLmn;
  } else {
    cout << "error: 0" << endl;
  }
}
void tnDelete(TreeNode *tN){
  if(tN != nullptr){
    delete tN;
  } else {
    cout << "error: 1" << endl;
  }
}
void deleteFLL(LLMovieNode *LLmn){
  LLMovieNode *crawler = LLmn;
  LLMovieNode *runner;
  while(crawler != nullptr){
    runner = crawler->next;
    llDelete(crawler);
    crawler = runner;
  }
}
void deleteTree(TreeNode *mN){
  if(mN == nullptr){
    return;
  } else {
    deleteTree(mN->leftChild);
    deleteTree(mN->rightChild);
    deleteFLL(mN->head);
    tnDelete(mN);
    return;
  }
}
MovieTree::~MovieTree() {
  deleteTree(root);
}

void printHelper(TreeNode *tN){
  if(tN == nullptr){
    return;
  } else {
    printHelper(tN->leftChild);
    cout << "Movies starting with letter: " << tN->titleChar << endl;
    LLMovieNode *crawler = tN->head;
    while(crawler != nullptr){
      cout << " >> " << crawler->title << " " << crawler->rating << endl;
      crawler = crawler->next;
    }
    printHelper(tN->rightChild);
  }
}
void MovieTree::printMovieInventory(){
  if(root == nullptr){
    return;
  } else {
    printHelper(root);
  }
}

char getChar(LLMovieNode *LLmn){
  int n = LLmn->title.length();
  char char_array[n + 1];
  strcpy(char_array, LLmn->title.c_str());
  char f = char_array[0];
  return f;
}
void addToLL(LLMovieNode *newLL, LLMovieNode *LLmn){
  if(LLmn->next == nullptr){
    LLmn->next = newLL;
  } else {
    if(LLmn->next->title.compare(newLL->title) >= 0){
      newLL->next = LLmn->next->next;
      LLmn->next = newLL;
    } else if(LLmn->next->title.compare(newLL->title) < 0){
      addToLL(newLL, LLmn->next);
    }
  }
}
void addHelper(LLMovieNode *newLL, TreeNode *currNode){
  char f = getChar(newLL);
  if(currNode->titleChar == f){
    if(currNode->head == nullptr){
      currNode->head = newLL;
    } else {
      if(currNode->head->title.compare(newLL->title) >= 0){
        newLL->next = currNode->head;
        currNode->head = newLL;
      } else {
        addToLL(newLL, currNode->head);
      }
    }
  } else if(f < currNode->titleChar){
    if(currNode->leftChild == nullptr){
      TreeNode *tN = new TreeNode;
      tN->head = newLL;
      tN->titleChar = f;
      tN->parent = currNode;
      currNode->leftChild = tN;
    } else {
      addHelper(newLL, currNode->leftChild);
    }
  } else if(f > currNode->titleChar){
    if(currNode->rightChild == nullptr){
      TreeNode *tN = new TreeNode;
      tN->head = newLL;
      tN->titleChar = f;
      tN->parent = currNode;
      currNode->rightChild = tN;
    } else {
      addHelper(newLL, currNode->rightChild);
    }
  }
}
void MovieTree::addMovie(int ranking, string title, int year, float rating) {
  LLMovieNode *newLL = new LLMovieNode(ranking, title, year, rating);
  char f = getChar(newLL);
  if(root == nullptr){
    TreeNode *newT = new TreeNode;
    newT->titleChar = f;
    root = newT;
    root->head = newLL;
  } else {
    addHelper(newLL, root);
  }
}

char getCharS(string str){
  int n = str.length();
  char char_array[n + 1];
  strcpy(char_array, str.c_str());
  char f = char_array[0];
  return f;
}
TreeNode* getMinValueNode(TreeNode* currNode) {
    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}
void deleteLL(string title, LLMovieNode *LLmn){
  if(LLmn == nullptr){
    return;
  }
  if(LLmn->next == nullptr){
    cout << "Movie: " << title << " not found, cannot delete." << endl;
  } else if(LLmn->next->title.compare(title) == 0 && LLmn->next != nullptr){
    LLMovieNode *temp = LLmn->next;
    LLmn->next = LLmn->next->next;
    llDelete(temp);
  } else {
    deleteLL(title, LLmn->next);
  }
}
void deleteNode(TreeNode *tN){
  if(tN == nullptr){
    return;
  }
  if(tN->leftChild == NULL && tN->rightChild == NULL) {
    // if(tN->parent == NULL){
      tnDelete(tN);
      tN = NULL;
      return;
    // }
    // if(tN->parent->titleChar > tN->titleChar){
    //   tN->parent->leftChild = NULL;
    // } else {
    //   tN->parent->rightChild = NULL;
    // }
    // tnDelete(tN);
    // tN = NULL;
  } else if(tN->leftChild == NULL) {
    TreeNode *temp = tN;
    // if(tN->parent == NULL){
      tN->rightChild->parent = tN->parent;
      tN = tN->rightChild;
      tnDelete(temp);
      return;
    // } else if(tN->parent->titleChar > tN->titleChar){
    //   tN->parent->leftChild = tN->rightChild;
    //   tN->rightChild->parent = tN->parent;
    // } else {
    //   tN->parent->rightChild = tN->rightChild;
    //   tN->rightChild->parent = tN->parent;
    // }
    // tnDelete(temp);
  } else if(tN->rightChild == NULL) {
    TreeNode *temp = tN;
    // if(tN->parent == NULL){
      tN->leftChild->parent = tN->parent;
      tN = tN->leftChild;
      tnDelete(temp);
      return;
    // } else if(tN->parent->titleChar > tN->titleChar){
    //   tN->parent->leftChild = tN->leftChild;
    //   tN->leftChild->parent = tN->parent;
    // } else {
    //   tN->parent->rightChild = tN->leftChild;
    //   tN->leftChild->parent = tN->parent;
    // }
    // tnDelete(temp);
  } else {
    TreeNode *min = getMinValueNode(tN->rightChild);
    tN->head = min->head;
    tN->titleChar = min->titleChar;
    deleteNode(min);
  }
}
void deleteHelper(string title, TreeNode *currNode){
  char f = getCharS(title);
  if(currNode->titleChar == f){
    if(currNode->head == nullptr){
      deleteNode(currNode);
    } else {
      if(currNode->head->title.compare(title) == 0){
        if(currNode->head->next == nullptr){
          deleteFLL(currNode->head);
          deleteNode(currNode);
        } else if(currNode->head != nullptr) {
          LLMovieNode *temp = currNode->head;
          currNode->head = currNode->head->next;
          llDelete(temp);
        }
      } else {
        deleteLL(title, currNode->head);
      }
    }
  } else if(f < currNode->titleChar){
    if(currNode->leftChild == nullptr){
      cout << "Movie: " << title << " not found, cannot delete." << endl;
    } else {
      deleteHelper(title, currNode->leftChild);
    }
  } else if(f > currNode->titleChar){
    if(currNode->rightChild == nullptr){
      cout << "Movie: " << title << " not found, cannot delete." << endl;
    } else {
      deleteHelper(title, currNode->rightChild);
    }
  }
}
void MovieTree::deleteMovie(std::string title){
  if(root == nullptr){
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  } else {
    deleteHelper(title, root);
  }
}
