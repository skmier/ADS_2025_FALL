#include <iostream>
#include <vector>

using namespace std;

void problemG(string pattern, vector<string> arr){
    int max = -1;
    vector<int> res;
    for(int i = 0; i < arr.size() - 1; i++){
        string s = arr[i] + "#" + pattern;
        int length_word = arr[i].size();
        int start = length_word + 1;
        int coincidence = 0;
        
    }
}
int main(){
    string str; cin >> str;
    vector<int> p = prefix_fun(str);
    cout << str.size() - p[str.size() - 1];
}