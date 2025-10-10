#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;


struct Node{
    int data;
    Node *left,*right;

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

    int Width(Node *node){
        queue<Node*> myque;
        myque.push(node);
        int maxWidth = 0;

        while (!myque.empty())
        {
            int count = myque.size();
            maxWidth = max(maxWidth, count);
            
            for(int i =0; i < count; i++){
                Node *current = myque.front();
                myque.pop();

                if(current->left != nullptr){
                    myque.push(current->left);
                }
                if(current->right != nullptr){
                    myque.push(current->right);
                }
            }
        }
        return maxWidth;
    }
};

int main(){
    int n; cin >> n;
    BST mybst;
    map<int, Node*> mymap;

    mymap[1] = new Node(1);

    for(int i = 0; i < n-1; i++){
        int x,y,z; cin >> x >> y >> z;
        if(mymap.find(x) == mymap.end()){
            mymap[x] = new Node(x);
        }
        if(mymap.find(y) == mymap.end()){
            mymap[y] = new Node(y);
        }
        if(z == 0){
            mymap[x]->left = mymap[y];
        }
        else{
            mymap[x]->right = mymap[y];
        }
    }

    cout << mybst.Width(mymap[1]);
}