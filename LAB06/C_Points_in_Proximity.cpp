#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void quick_sort(vector<int> &arr,int left, int right){
    int i = left;
    int j = right;
    int pivot = arr[(i+j)/2];
    while (i <= j)
    {
        while(arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if(i <= j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }        
    }
    if(left < j) quick_sort(arr,left,j);
    if(right > i) quick_sort(arr,i, right);
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quick_sort(arr,0,n-1);
    int minDifference = INT_MAX;
    for(int i = 0; i < n-1; i++){
        int difference = arr[i+1] - arr[i];
        if(minDifference > difference) minDifference = difference;
    }

    for(int i = 0; i < n-1; i++){
        if(minDifference == arr[i+1] - arr[i]){
            cout << arr[i] << " " << arr[i+1] << " ";
        }
    }
}