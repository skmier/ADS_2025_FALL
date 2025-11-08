#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const unsigned long long MOD = 1e9 + 7;
const int base = 11;

string hashing(string str){
    unsigned long long hash_val = 0;
    unsigned long long pow = 1;

    for(int i = 0; i < str.size(); i++){
        unsigned long long char_value = (long long)str[i] - 47;
        hash_val = (hash_val + (char_value * pow)% MOD) % MOD;
        pow = (pow * base) % MOD;
    }
    return to_string(hash_val);
}


int main(){
    int n; cin >> n;
    vector<string> arr(2*n);
    unordered_map<string,bool> myMap;
    for(int i = 0; i <2 * n; i++){
        cin >> arr[i];
        myMap[arr[i]] = true;
    }
    
    int count = 0;

    for(int i = 0; i <2 * n; i++){
        if(count == n) break;
        string hash = hashing(arr[i]);
        if(myMap[hash]){
            cout << "Hash of string " << '"' <<  arr[i]  <<'"' << " is " << hash << endl;
            count++;
        }
    }
}