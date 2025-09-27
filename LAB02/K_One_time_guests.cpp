#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t; 
    cin >> t;

    vector<vector<string>> res(t); 

    for (int test = 0; test < t; test++) {
        int n; 
        cin >> n; 

        unordered_map<char, int> mymap; 
        queue<char> myque; 

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;

            mymap[c]++;
            myque.push(c);

            while (!myque.empty() && mymap[myque.front()] > 1) {
                myque.pop();
            }

            if (myque.empty()) res[test].push_back("-1");
            else res[test].push_back(string(1, myque.front()));
        }
    }

    for (auto &vec : res) {
        for (auto &s : vec) cout << s << " ";
        cout << endl;
    }

    return 0;
}

