#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_fun(string pattern){
    int n = pattern.size();
    vector<int> p(n);
    int i = 1; int j = 0;
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

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int k; cin >> k;
        int s_size = s.size();
        vector<int> pref = prefix_fun(s);
        int p = pref[s.size() - 1];
        int output = s_size + ((k - 1) * (s_size - p));
        cout << output << endl;
    }
}