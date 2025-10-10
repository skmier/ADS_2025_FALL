#include <iostream>
#include <algorithm>
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

    int findDiaemetr(Node *node, int &diameter){
        if(node == nullptr) 
            return 0;

        int left = findDiaemetr(node->left, diameter);
        int right = findDiaemetr(node->right, diameter);

        diameter = max(diameter, left + right+1);
        return 1 + max(left, right);
    }


};

int main(){
    int n; cin >> n;
    BST killer_kilua;
    
    for(int i = 0; i < n; i++){
        int t; cin >>t;
        killer_kilua.root = killer_kilua.insert(killer_kilua.root, t);
    }

    int diameter = 0;
    killer_kilua.findDiaemetr(killer_kilua.root, diameter);
    cout << diameter;

}