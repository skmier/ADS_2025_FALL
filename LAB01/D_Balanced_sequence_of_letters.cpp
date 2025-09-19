#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string word;
    cin >> word;
    stack<char> letters;
    for(int i = 0; i < word.size(); i++){
        if(!letters.empty() && letters.top() == word[i]){
            letters.pop();
        }
        else{
            letters.push(word[i]);
        }
    }

    if(letters.empty()) cout << "YES";
    else cout << "No";
} 