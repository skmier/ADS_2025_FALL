#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<char>& arr, int left, int right) {
    int i = left, j = right;
    char pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

int main() {
    string str; cin >>str;
    vector<char> arr;
    
    for(int i = 0; i < str.size(); i++){
        arr.push_back(str[i]);
    }

    quick_sort(arr, 0, arr.size() -1 );

    for (char c : arr)
        cout << c;

    return 0;
}
