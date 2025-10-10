#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *right,*left;

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

        void inorder(Node *node){
            if(node == nullptr) 
                return;

            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }


        int counter(Node *node){
            if(node == nullptr) 
                return 0;

            return 1 + counter(node->left) + counter(node->right);
       }
};


int main(){
    int n; cin >>n;
    BST task2;
    for(int i = 0; i < n; i++ ){
        int t; cin >> t;
        task2.root = task2.insert(task2.root, t);
    }

    int x; cin >> x;
    Node *current = task2.root;
    while (current != nullptr && current->data != x){
        if(x < current->data){
            current = current->left;
        }
        else if(x > current->data){
            current = current->right;
        }
    }

    if(current != nullptr){
        cout << task2.counter(current) << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}