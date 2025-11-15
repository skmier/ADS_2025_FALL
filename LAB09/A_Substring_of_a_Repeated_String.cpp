#include <iostream>
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
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

bool kmp(const string &a, const string &b){
    string s = b + "#" + a;
    vector<int> p = prefix_fun(s);
    for(int x:p){
        if(x == b.size()) return true;
    }
    return false;
}

int main(){
    string A,B; cin >> A >> B;
    long long count = 1;
    string org_A = A; 
    long long limit = B.size()/org_A.size() + 2;

    while (A.size() < B.size())
    {
        count++;
        A += org_A;
    }
    
    if(kmp(A,B)) cout << count;
    else if (kmp(A+A,B)) cout << count + 1;
    else cout << -1;
}