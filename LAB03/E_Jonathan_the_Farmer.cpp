#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int can_catch(vector<int> &arr, int mid){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= mid){
            count++;
        }
    }
    return count;
}

void bin_search(vector<int> &arr, int k){
    int left = 0;
    int right = *max_element(arr.begin(), arr.end());
    while(left <= right){
        int mid = (left + right) / 2;
        if(can_catch(arr, mid) >= k){
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int maxi = max(x2, y2);
        arr[i] = maxi;
    }
    bin_search(arr, k);
    return 0;
}