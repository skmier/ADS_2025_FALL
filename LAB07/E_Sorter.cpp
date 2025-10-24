#include <iostream>
#include <vector>

using namespace std;

void merge(vector<vector<int>> &arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<vector<int>> L(n1),R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[m + i + 1];
    }
    int uk1 = 0;
    int uk2 = 0;
    int k = l;
    while (uk1 < n1 && uk2 < n2 )
    {
        int sum1 = 0;
        for(auto t:L[uk1]) sum1 += t;
        int sum2 = 0;
        for(auto t:R[uk2]) sum2 += t;
        if(sum1 == sum2){
            int index = 0;
            while (index < L[uk1].size() && index < R[uk2].size()){
                if(L[uk1][index] != R[uk2][index]){
                    if(L[uk1][index] < R[uk2][index]){
                        arr[k] = L[uk1];
                        uk1++;
                        break;
                    }
                    else{
                        arr[k] = R[uk2];
                        uk2++;
                        break;
                    }
                }
                index++;
            }
            if(index == L[uk1].size() ||index == R[uk2].size()){
                arr[k] = L[uk1];
                uk1++;
            }
        }
        else if(sum1 > sum2){
            arr[k] = L[uk1];
            uk1++; 
        }
        else{
            arr[k] = R[uk2];
            uk2++;
        }
        k++;
    }

    while (uk1 < n1)
    {
        arr[k] = L[uk1];
        uk1++; k++;
    }

    while (uk2 < n2)
    {
        arr[k] = R[uk2];
        uk2++; k++;
    }
}

void merge_sort(vector<vector<int>> &arr, int l,  int r){
    if(l < r){
        int m = (l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    merge_sort(arr,0,arr.size() -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j]<< " ";
        }
        cout << endl;
    }
}