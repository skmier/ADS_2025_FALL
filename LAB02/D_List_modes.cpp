#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> myvec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> myvec[i];
    }
    
    map<int,int> mymap;
    for (int x : myvec) {
        mymap[x]++;
    }

    int max = 0;
    for (auto it : mymap) {
        if (max < it.second) {
            max = it.second;
        }
    }
    vector<int> res;
    for (auto it : mymap) {
        if (max == it.second) {
            res.push_back(it.first);
        }
    }
    
    sort(res.rbegin(),res.rend());
    for(int i : res){
        cout << i<<" ";
    }

}


