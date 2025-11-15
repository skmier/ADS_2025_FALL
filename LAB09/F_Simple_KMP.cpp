#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_fun(string pattern){
    int n = pattern.size();
    vector<int> p(n);
    int j = 0;
    int i = 1;
    while (i < n)
    {
        if(pattern[i] == pattern[j]){
            j++;
            p[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = p[j-1];
            }
            else{
                p[i] = 0;
                i++;
            }
        }
    }
    return p;
}

vector<int> kmp(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int> index;
    vector<int> p = prefix_fun(pattern);
    int i, j;  i = j = 0;
    while (i < n)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = p[j-1];
        }
        if(pattern[j] == text[i]){
            j++;
        }       
        i++;
        if(j == m){
            index.push_back(i-j +1);
            j = p[j-1];
        } 
    }
    return index;
}


int main(){
    string s,t; cin >> s >> t;
    vector<int> p = kmp(s,t);
    cout << p.size() << endl;
    for(int x:p){
        cout << x <<" ";
    }
}
