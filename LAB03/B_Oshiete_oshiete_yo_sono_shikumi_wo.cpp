#include <iostream>
#include <vector>
using namespace std;


int count_block(const vector<long long>& a, long long x) {
    int cnt = 1;
    long long sum = 0;
    for (long long t : a) {
        if (sum + t > x) {
            sum = t;
            ++cnt;
        } else {
            sum += t;
        }
    }
    return cnt;
}

int main() {


    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long maxElem = 0;
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxElem) maxElem = a[i];
        total += a[i];
    }

    long long left = maxElem;
    long long right = total;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (count_block(a, mid) <= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}