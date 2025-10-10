#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bin_search(const vector<int>& arr, int k){
    int l = 0;
    int r = arr.size() - 1;
    int ans = arr.size(); 
    while (l <= r){
        int m = (l + r) / 2;
        if (arr[m] > k){       
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int p; cin >> p;
    vector<vector<int>> output(p, vector<int>(2)); 
    sort(arr.begin(), arr.end());
    for(int i = 0; i < p; i++){
        int sum = 0;
        int x; cin >> x;
        int c = bin_search(arr, x); 
        for(int i = 0; i < c; i++){
            sum += arr[i];
        }
        output[i][0] = c;
        output[i][1] = sum;
   }

    for(int i = 0; i < p; i++) {
        cout << output[i][0] << " " << output[i][1] << endl;
    }
}
