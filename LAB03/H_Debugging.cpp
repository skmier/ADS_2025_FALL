#include <iostream>
#include <vector>

using namespace std;

void bin_search(const vector<int>& arr, int t){ // i hate this const
    int l = 0;
    int r = arr.size();
    while (l < r)
    {
        long long m = (r+l)/2;
        if (arr[m] < t) l = m + 1 ;
        else r = m;
    }
    cout << l+1 << endl;
}

int main(){
    int n,m; cin >>n >> m;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        arr[i] = sum;
    }
    vector<int> output;
    for(int i = 0 ;i < m; i++){
        int t; cin >>t;
        bin_search(arr,t); // aaaaaaaaaa a так можно оказ
    }
}