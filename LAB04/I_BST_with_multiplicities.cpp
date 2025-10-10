#include <iostream>

using namespace std;

struct Node{
    int data,count;
    Node *left, *right;

    Node(int val){
        data = val;
        count = 1;
        left = right = nullptr;
    }
};

class BST{
    public:
    Node *root;

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
        else{
            node->count++;
        }
        return node;
    }

    Node *finDmin(Node *node){
        Node *current = node;
        while(current && current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *node, int val){
        if(node == nullptr){
            return node;
        }

        if(val < node->data){
            node->left = deleteNode(node->left,val);
        }
        else if(val > node->data){
            node->right = deleteNode(node->right,val);
        }
        else{
            node->count--;
            if(node->count > 0) return node;

            if(node->left == nullptr){
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr){
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *curr = finDmin(node->right);
            node->data = curr->data;
            node->count = curr->count;

            node->right = deleteNode(node->right, curr->data);
        }

        return node;
    }

    int searchcounter(Node *node, int val){
        if(node == nullptr){
            return 0;
        }

        if(val < node->data){
            return searchcounter(node->left,val);
        }
        else if(val > node->data){
            return searchcounter(node->right,val);
        }
        else{
            return node->count;
        }
    }

};


int main(){
    int n; cin >> n;
    BST task9;
    for(int i = 0; i < n; i++){
        string command; cin >> command;
        if(command == "insert"){
            int t; cin >> t;
            task9.root = task9.insert(task9.root, t);
        }
        else if(command == "cnt"){
            int t; cin >> t;
            cout << task9.searchcounter(task9.root, t) << endl;
        }
        else if(command == "delete"){
            int t; cin >> t;
            task9.root = task9.deleteNode(task9.root, t);
        }
        
    }
}