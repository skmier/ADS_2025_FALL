#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bin_search(vector<long long> arr,  long long n, long long f){
    long long l = 1;
    long long r = *max_element(arr.begin(),arr.end());
    long long ans = r;
    while (l <= r){
        long long m = (l+r) / 2;
        long long total_flight = 0;
        for(int i = 0; i < n; i++){
            total_flight += (arr[i] + m -1) / m;
        }
        if(total_flight <= f){ //-> i hate this =
            ans = m;
            r = m -1;
        }
        else l = m +1;
    }
    return ans;
}


int main(){
    long long n, f; cin >> n >> f;
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long ans = bin_search(arr,n,f);
    cout << ans;
}