#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_fun(string pattern){
    int n = pattern.size();
    vector<int> p(n);
    int j = 0; int i = 1;
    while (i < n)
    {
        if(pattern[i] == pattern[j]){
            j++;
            p[i] = j;
            i++;
        }
        
        else{
            if(j > 0){
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
    string s; cin >> s;
    vector<int> p = prefix_fun(s);
    int count = 0;
    for(int i = 1; i < p.size(); i++){
        if(i % 2 == 0){
            if((i/(i-p[i-1])) % 2 == 0){
                count++;    
            }
        }
    }
    cout << count;
}
