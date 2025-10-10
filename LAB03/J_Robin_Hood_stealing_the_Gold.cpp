#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int taskJ(vector<int>& vec, int h){
    int low = 1;
    int high = *max_element(vec.begin(), vec.end());

    while (low < high)
    {
        int mid = (low + high) / 2;
        
        int time = 0;
        for(int x: vec){
            time += (x + mid - 1) / mid;
        }

        if(time <= h) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main(){
    int n, h; cin >> n >> h;
    vector<int> myvec(n);

    for(int i = 0; i < n; i++){
        cin >> myvec[i];
    }

    int res = taskJ(myvec,h);
    cout << res;

}