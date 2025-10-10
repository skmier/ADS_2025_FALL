    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <algorithm>

    using namespace std;

    void finderofmid(const vector<int> &arr, int left, int right){
        if(left > right) return;
        int mid = left + (right - left) / 2;
        cout << arr[mid] << " ";
        finderofmid(arr, left, mid - 1);
        finderofmid(arr, mid + 1, right);
    }

    int main(){
        int n; cin >> n;
        int newN = pow(2, n) - 1;

        vector<int> arr(newN);

        for(int i = 0; i < newN; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        finderofmid(arr, 0, newN - 1);
    }