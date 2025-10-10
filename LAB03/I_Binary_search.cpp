#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> arr, int n, int k ){
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (l+r) /2;
        if(arr[m] == k) return m;
        if(arr[m] < k) l = m+1;
        else r = m-1;
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k; cin >>k;
    int pos = binary_search(arr,n,k);
    if(pos != -1) cout << "Yes";
    else cout << "No";
}