#include <iostream>

using namespace std;

struct Node{
    int data;
    Node * right, *left;
    
    Node(int val){
        data = val;
        right = left = nullptr;
    }
};

class BST{
    public:
        Node* root;
    
    BST(){
        root = nullptr;
    }

    Node *insert(Node *node, int val){
        if(node == nullptr){
            node = new Node(val);
            return node;
        }

        if(val < node->data){
            node->left = insert(node->left,val);
        }

        else if(val > node->data){
            node->right = insert(node->right, val);
     
        }

        return node;
        }

    int countTriangle(Node *node){
        if(node == nullptr) 
            return 0;
 
        int currentCount = 0;
        if(node->left != nullptr && node->right != nullptr){
            currentCount = 1;
        }

        int leftCount = countTriangle(node->left);
        int rightCount = countTriangle(node->right);

        return currentCount + leftCount + rightCount;
    }

};

int main(){
    int n; cin >> n;
    BST task6;
    for(int i = 0; i < n; i++){
        int t; cin >>t;
        task6.root = task6.insert(task6.root, t);
    }

    cout << task6.countTriangle(task6.root);
}