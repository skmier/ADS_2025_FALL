#include <iostream>
using namespace std;

int binary_search_left(int *arr, int mynum, int n) {
    int l = 0, 
    r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == mynum) return mid;
        if (arr[mid] < mynum) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int binary_search_right(int *arr, int mynum, int n) {
    int l = 0,
    r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == mynum) return mid;
        if (arr[mid] > mynum) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int t; 
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    int n, m; 
    cin >> n >> m;
    int taskarr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> taskarr[i][j];
        }
    }

    for (int x = 0; x < t; x++) {
        int a = arr[x];
        bool found = false;

        for (int i = 0; i < n; i++) {
            int pos;
            if (i % 2 == 0) { 
                pos = binary_search_right(taskarr[i], a, m);
            } else {          
                pos = binary_search_left(taskarr[i], a, m);
            }

            if (pos != -1) {
                cout << i << " " << pos << endl;
                found = true;
                break;
            }
        }

        if (found == false) cout << -1 << endl;
    }

    return 0;
}
