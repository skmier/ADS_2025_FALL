#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<string,string>> arr;
    
    for(int i = 0; i < n; i++){
        string first_name; cin >> first_name;
        string new_name; cin >> new_name;
        bool flag = false;
        for(int j = 0; j < arr.size();j++){
            if(first_name == arr[j].second){
                arr[j].second = new_name;
                flag = true;
                break;
            }
        }
        if(!flag){
            arr.push_back({first_name,new_name});
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << endl;
    for(auto pair:arr){
        cout << pair.first << " " << pair.second << " " << endl;
    }
    
}