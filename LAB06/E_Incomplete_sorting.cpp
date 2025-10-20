#include <iostream>

using namespace std;  

void quick_sort(int arr[],int left, int right){
    int i = left; int j = right;
    int pivot = arr[(left + right)/2];
    while ( i <= j){
        while(arr[i] > pivot) i++;
        while(arr[j] < pivot) j--;
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
    int n,m; cin >> n >> m;
    int arr[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[j][i];
        }
    }   

    for(int i = 0; i <m; i++){
        quick_sort(arr[i],0,n-1);
    }   

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}