#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_fun(string s){
    int n = s.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
        {
            j = p[j-1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

void kmp(string &a,string &b,int k){
    string s = a + "#" + b;
    vector<int> p = prefix_fun(s);
    int count = 0;
    for(int x:p){
        if(x == a.size()) count++;
    }
    if(count >= k) cout << "YES";
    else cout << "NO";
}

int main(){
    string s1, s2;
    int n;
    cin >> s1; 
    cin >> n ;
    cin >> s2;
    kmp(s1,s2,n);
}