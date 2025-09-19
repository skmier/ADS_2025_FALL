#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstword , secondword;
    cin >> firstword >> secondword;

    string newfirstword;

    for (char i : firstword){
        if(i == '#'){
            newfirstword.pop_back();
        }
        else{
            newfirstword.push_back(i);
        }
    }
    
    string seconnewdword;
    for (char i : secondword){
        if(i == '#'){
            seconnewdword.pop_back();
        }
        else{
            seconnewdword.push_back(i);}
    
    }
    if(newfirstword == seconnewdword){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}