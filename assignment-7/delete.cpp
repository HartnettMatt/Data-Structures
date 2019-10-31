#include <bits/stdc++.h>
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
  if(LLmn->next == nullptr){
    cout << "Movie: " << title << " not found, cannot delete." << endl;
  } else if(LLmn->next->title.compare(title) == 0){
    LLMovieNode *temp = LLmn->next;
    LLmn->next = LLmn->next->next;
    delete temp;
  } else {
    deleteLL(title, LLmn->next);
  }
}
void deleteNode(TreeNode *tN){
  if(tN->leftChild == NULL && tN->rightChild == NULL) {
    tN = NULL;
    delete tN;
  } else if(tN->leftChild == NULL) {
    TreeNode *temp = tN;
    if(tN->parent->titleChar > tN->titleChar){
      tN->parent->leftChild = tN->rightChild;
    } else {
      tN->parent->rightChild = tN->rightChild;
    }
    delete temp;
  } else if(tN->rightChild == NULL) {
    TreeNode *temp = tN;
    if(tN->parent->titleChar > tN->titleChar){
      tN->parent->leftChild = tN->leftChild;
    } else {
      tN->parent->rightChild = tN->leftChild;
    }
    delete temp;
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
          deleteNode(currNode);
        } else {
          LLMovieNode *temp = currNode->head;
          currNode->head = currNode->head->next;
          delete temp;
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
