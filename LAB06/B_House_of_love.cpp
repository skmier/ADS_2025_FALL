#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& arr, int left, int right){
    if(arr.empty()) return;
    int i = left; int j = right;
    int pivot = arr[(left+right)/2];
    while(i <= j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(left < j){
        quick_sort(arr,left,j);
    }   
    if(i < right){
        quick_sort(arr,i,right);
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for(int i = 0; i < n ;i++)
        cin >> arr1[i];

    for(int i = 0; i < m ;i++)
        cin >> arr2[i];
    ;
    quick_sort(arr1,0,n-1);
    quick_sort(arr2,0,m-1);

    int i,j =0;
    if(arr1.empty() || arr2.empty()){
        return 0;
    }
    vector<int> output;
    while(i < n && j < m){
        if(arr1[i] > arr2[j]){
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            output.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
}