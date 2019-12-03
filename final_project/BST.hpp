
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class BST{
  public:
        Node* root;
        Node* createNode(int data);

        Node* addNodeHelper(Node*, int);
        void printTreeHelper(Node*);
        void print2DUtilHelper(Node *, int);



        Node* getMinValueNode(Node*);
        Node* getMaxValueNode(Node*);

        void destroyNode(Node *root);

        Node* deleteNode(Node*, int);
        bool isValidHelper(Node*);

        Node* getRoot();                // Returns the root of the tree;
        void addNode(int);              // function to insert a node in the tree.
        Node* searchKeyHelper(Node*, int); // function to search data in tree and return node of key
        bool searchKey(int);            // function to search a data in the tree
        void printTree();               //function to print the tree
        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        ~BST();                         // destructor
        void removeRange(int, int);
        void print2DUtil(int);
        bool isValidBST();

};
