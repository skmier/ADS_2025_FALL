#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *right, *left;
    
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
        else if(val> node->data){
            node->right = insert(node->right, val);
        }
        return node;
    }

    void greaterSumTree(Node *node, int &sum){
        if(node == nullptr) 
            return;
        greaterSumTree(node->right, sum);
        sum += node->data;
        node->data = sum ;
        cout << node->data << " ";
        greaterSumTree(node->left, sum);
    }
};


int main(){
    int n; cin >> n;
    BST mybst;
    for(int i = 0; i <n; i++){
        int t; cin >> t;
        mybst.root = mybst.insert(mybst.root, t);
    }

    int sum = 0;
    mybst.greaterSumTree(mybst.root, sum);
}