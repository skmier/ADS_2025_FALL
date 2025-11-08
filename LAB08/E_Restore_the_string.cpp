#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string restore_str(vector<long long> &arr){
    string output = "";
    for(int i = 0; i < arr.size(); i++){
        long long asci = arr[i];
        if(i > 0){
                asci -= arr[i-1];
        }
        char letter = char(asci/pow(2,i) + 97);
        output += letter;
    }
    return output;
}

int main(){
    int n; cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << restore_str(arr);
}