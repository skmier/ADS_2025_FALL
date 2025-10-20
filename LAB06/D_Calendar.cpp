#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n; cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int day1 = stoi(arr[i].substr(0,2));
            int day2 = stoi(arr[j].substr(0,2));

            int month1 = stoi(arr[i].substr(3,2));
            int month2 = stoi(arr[j].substr(3,2));

            int year1 = stoi(arr[i].substr(6,4));
            int year2 = stoi(arr[j].substr(6,4));

            if(year1 > year2 || (year1 == year2 && month1 > month2 ) ||(year1 == year2 && month1 == month2 && day1 > day2)){
                swap(arr[i],arr[j]);
            }
        }
    }

    for(auto t:arr){
        cout << t << endl;
    }
}
