#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr,int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1),R(n2);
    for(int i = 0; i <n1; i++) {
        L[i] = arr[l+i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[m+1+i];
    }

    int uk1 = 0;
    int uk2 = 0;
    int k = l;
    while (uk1 < n1 && uk2 < n2){
        if(L[uk1] <= R[uk2]){
            arr[k] = L[uk1];
            uk1++;
        }
        else{
            arr[k] = R[uk2];
            uk2++;
        }
        k++;
    }
    while (uk1 < n1){
        arr[k] = L[uk1];
        uk1++; k++;
    }

    while (uk2 < n2){
        arr[k] = R[uk2];
        uk2++; k++;
    }   
}

void merge_sort(vector<int> &arr, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);   
    }
}

int main(){
    int n, m; cin >> n >> m;
    if(n == 0 || m == 0) return 0;
    vector<int> arr1(n),arr2(m);

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    vector<int> output;
    merge_sort(arr1,0,n-1);
    merge_sort(arr2,0,m-1);

    int i,j = 0;


    while (i < n && j < m)
    {
        if(arr1[i] == arr2[j]){
            output.push_back(arr1[i]);
            i++; j++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    for(auto t: output){
        cout << t <<" ";
    }
}