#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    queue<int> sakay, katsu;

    for(int i = 0; i < n; i++){
        if(s[i] == 'S') sakay.push(i);
        else katsu.push(i);
    }

    while (!sakay.empty() && !katsu.empty())
    {
        int iS = sakay.front(); sakay.pop();
        int iK = katsu.front(); katsu.pop();

        if(iS < iK) sakay.push(iS + n);
        else katsu.push(iK + n);
    }

    if(sakay.empty()) cout << "KATSURAGI" << endl;
    else cout << "SAKAYANAGI" << endl;
    
}