#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> executemyhardtask(int n){
    deque<int> mydeq;
    for(int i = n; i >= 1; i--){
        mydeq.push_front(i);
        for(int j = 0; j < i; j++){
            mydeq.push_front(mydeq.back());
            mydeq.pop_back();
        }
    }
    return vector<int>(mydeq.begin(), mydeq.end());
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> output;
    
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        output.push_back( executemyhardtask(n));
    }

    for (int i = 0; i < t; i++){
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    
}