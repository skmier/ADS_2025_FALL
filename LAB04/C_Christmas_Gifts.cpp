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

        Node *search(Node *node, int k){
            if(node == nullptr || node->data == k){
                return node;
            }

            if(k < node->data){
                return search(node->left, k);
            }
            else {
                return search(node->right, k);
            }

            return search(node->right, k);
        }

    void christmasGifts(Node *node, int k){
            if(node == nullptr) 
                return;
            cout << node->data << " ";
            christmasGifts(node->left, k);
            
            christmasGifts(node->right, k);
        }
};


\

int main(){
    int n; cin >> n;
    BST task3;
    for(int i = 0; i < n; i++ ){
        int t; cin >> t;
        task3.root = task3.insert(task3.root, t);
    }
    int k; cin >> k;
    Node *res = task3.search(task3.root, k);
    if(res != nullptr){
        task3.christmasGifts(res, k);
    }
}