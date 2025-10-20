#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;  

void quick_sort(vector<char>& arr, int left, int right){
    int i = left; int j = right;
    char pivot = arr[(left + right)/2];
    while ( i <= j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j){
            swap(arr[i],arr[j]);
            i++;    
            j--;
        }
    }
    if(left < j) 
        quick_sort(arr,left,j);
    if(right > i)
        quick_sort(arr,i,right);
}


int main(){
    int n; cin >> n;
    vector<char> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quick_sort(arr,0,n - 1);
    char t ; cin >> t;
    bool found = false;
    for(int i = 0; i < n; i++){
        if(arr[i] > t){
            cout << arr[i] << endl;
            found = true;
            break;
        }
    }   

    if(!found){
        cout << arr[0] << endl;
    }
}