#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    string str; cin >> str;
    vector<char> vowels;
    vector<char> consonants;
    for(int i = 0; i < n; i++){
        char c = str[i];
        if(c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vowels.push_back(c);
        } else {
            consonants.push_back(c); 
        }
    }
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end()); 
    for(auto c: vowels){
        cout << c;
    }
    for(auto c: consonants){
        cout << c;
    }
}