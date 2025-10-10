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
    Node *root;

    BST(){
        root = nullptr;
    }

    Node *insert(Node *node, int val){
        if (node == nullptr){
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

    void mountain(Node *node,string path){
        if(node == nullptr) 
            return;

        Node *current = node;

        for(int i = 0; i < path.size(); i++){
            if(path[i] == 'L'){
                current = current->left;
            }
            else if(path[i] == 'R'){
                current = current->right;
            }
            if(current == nullptr){
                break;
            }
        }
        if (current != nullptr)
        {
            cout <<"YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
};


int main(){
    int n,m; cin >> n >>m;
    BST mount;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        mount.root = mount.insert(mount.root, t);
    }
    while (m--)
    {
        string path; cin >> path;
        mount.mountain(mount.root,path);
    }
    return 0;
}