 #include <iostream>
 #include <vector>
 #include <algorithm>

using namespace std;

int countInRange(vector<int>& arr,int l, int r){
    auto left = lower_bound(arr.begin(), arr.end(),l);
    auto right = upper_bound(arr.begin(), arr.end(),r);
    return right - left;
}


int main(){
    int n; cin >> n;
    int t; cin >> t;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> output;
    
   sort(arr.begin(), arr.end());

   for(int i = 0; i < t; i++){
        int l1,l2,r1,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt1 = countInRange(arr,l1,r1);
        int cnt2 = countInRange(arr,l2,r2);

        int overlap = 0;
        int L = max(l1,l2);
        int R = min(r1,r2);
        if(L <= R){
            overlap = countInRange(arr,L,R);
        }
        output.push_back(cnt1 + cnt2 - overlap);
   }
   

    for(auto t: output){
        cout << t << endl;
    }
}