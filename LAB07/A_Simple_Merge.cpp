#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void merge(vector<string> &arr,int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<string> L(n1),R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[m + 1 + i];
    }
    
    int uk1 = 0;
    int uk2 = 0;
    int k = l;
    while (uk1 < n1 && uk2 < n2){
        if(L[uk1].length() <= R[uk2].length()){
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

void merge_sort(vector<string> &arr, int l, int r){
    if(l < r){
        int m = (l+r) /2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n; cin >> n;
    cin.ignore();
    

    for(int i = 0; i < n; i++){
        string lines;
        getline(cin, lines);
        
        vector<string> words;
        string word;
        stringstream ss(lines);
        while (ss >> word)
        {
            words.push_back(word);
        }
        merge_sort(words,0,words.size() -1);
        for(int s = 0; s < words.size(); s++){
            cout << words[s] << " ";
        }
        cout <<endl;
    }
}