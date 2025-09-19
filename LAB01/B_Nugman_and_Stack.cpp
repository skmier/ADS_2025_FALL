#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> myvec;
    stack<int> mystack;

    for (int i = 0; i < n; i++){
        int t; cin >>t;
        while (!mystack.empty() && t < mystack.top()){
            mystack.pop();
        }
        if (mystack.empty()){ 
            myvec.push_back(-1);
        }
        else{
            myvec.push_back(mystack.top());
        } 
        mystack.push(t);
    }

    for (int i = 0; i < n; i++){
        cout << myvec[i] << " ";
    }
    return 0;
}