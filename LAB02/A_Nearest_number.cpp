#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){  
    int n;
    cin >> n;
    vector<int> myvec;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        myvec.push_back(a);
    }
    int k;
    cin >> k;
    vector<int> result;

    for(int i = 0; i < n; i++){
        result.push_back(abs(myvec[i] - k));
    }
    int min = result[0];
    int index = 0;
    for(int i = 1; i < n; i++){
        if(result[i] < min){
            index = i;
            min = result[i];
        }
    }
    cout << index << endl;
    return 0;
}