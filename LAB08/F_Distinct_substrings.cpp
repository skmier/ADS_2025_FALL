#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    unordered_set<unsigned long long > arr;
    for (size_t i = 0; i < str.length(); i++) {
        unsigned long long  hash = 0;
        for (size_t j = i; j < str.length(); j++) {
            hash = hash * 131 + str[j];
            arr.insert(hash);
        }
    }
    cout << arr.size() << endl;
}