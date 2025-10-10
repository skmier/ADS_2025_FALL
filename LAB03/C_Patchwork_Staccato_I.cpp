#include <iostream>
#include <vector>
using namespace std;



int main(){
    int n; cin >> n;
    int t; cin >> t;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> output;

    for(int i = 0; i < t; i++){
        int l1,l2,r1,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count = 0;
        for(int j = 0; j < n; j++){
            if ((arr[j] >= l1 && arr[j] <= r1) || (arr[j] >= l2 && arr[j] <= r2)){
                count++;
            }
        }
        output.push_back(count);
    }

    for(auto t: output){
        cout << t << endl;
    }
}