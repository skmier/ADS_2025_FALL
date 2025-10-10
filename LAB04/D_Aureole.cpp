#include <iostream>
#include <vector>
#include <queue>
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

    vector<int> lvlSum(Node *node){
        vector<int> result;
        if(node == nullptr) 
            return result;
        queue<Node*> myque;
        myque.push(node);

        while (!myque.empty()){
            int levelsum = 0;
            int levelSize = myque.size();
            for(int i = 0; i < levelSize; i++){
                Node *current = myque.front();
                myque.pop();
                levelsum += current->data;

                if(current->left != nullptr){
                    myque.push(current->left);
                }
                if(current->right != nullptr){
                    myque.push(current->right);
                }
            }
            result.push_back(levelsum);
        }
        
        return result;
    }
};


int main(){
    int n; cin >> n;
    BST task4;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        task4.root = task4.insert(task4.root, t);
    }

    vector<int> answer = task4.lvlSum(task4.root);

    cout << answer.size() << endl;

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";   
    }
}