#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const long long P = 31;      
const long long MOD = 1e9 + 7; 
long long get_char_val(char c) {
    return (long long)c - 'a' + 1; 
}


vector<int> occur(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0 || m > n) return {};

    vector<long long> p_pow(n + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
    }

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        long long val_term = (get_char_val(text[i]) * p_pow[i]) % MOD;
        h[i + 1] = (h[i] + val_term) % MOD;
    }

    long long hash_pattern = 0;
    for (int i = 0; i < m; i++) {
        hash_pattern = (hash_pattern + get_char_val(pattern[i]) * p_pow[i]) % MOD;
    }

    vector<int> res;
    for (int i = 0; i <= n - m; i++) {
        long long current_hash = (h[i + m] - h[i] + MOD) % MOD;
        long long required_hash = (hash_pattern * p_pow[i]) % MOD;
        
        if (current_hash == required_hash) {
            res.push_back(i); 
        }
    }
    return res;
}

int main() {
    string str1, str2, t;
    cin >> str1 >> str2 >> t;
    
    
    vector<int> arr1 = occur(str1, t); 
    vector<int> arr2 = occur(str2, t); 

    int count = 0;
    int i = 0, j = 0;
    while (i < (int)arr1.size() && j < (int)arr2.size()) {
        if (arr1[i] == arr2[j]) {
            count++;
            i++; j++;
        } else if (arr1[i] < arr2[j]) i++;
        else j++;
    }

    cout << count;
    return 0;
}
