#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long P = 31;      
const long long MOD = 1e9 + 7;

long long get_val(char c) {
    return (long long)c - 'a' + 1; 
}

long long get_hash(const string& s) {
    long long sum = 0;
    long long p_pow = 1;
    for(char c : s) {
        sum = (sum + get_val(c) * p_pow) % MOD; 
        p_pow = (p_pow * P) % MOD;
    }
    return sum;
}

vector<long long> h_prefix(const string& s) {
    int sz = (int)s.size();
    vector<long long> result(sz + 1, 0); 
    
    long long p_pow = 1; 
    for(int i = 0; i < sz; i++) {
        long long val_term = (get_val(s[i]) * p_pow) % MOD;
        result[i + 1] = (result[i] + val_term) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return result;
}

vector<long long> p_prefix(int sz) {
    vector<long long> result(sz + 1);
    
    result[0] = 1;
    for(int i = 1; i <= sz; i++) {
        result[i] = (result[i - 1] * P) % MOD;
    }
    return result;
}

void occurences(int sz, const string& tape, int &count, vector<bool> &covers, const vector<long long>& s_h, const vector<long long>& p_pref) {
    
    int m = (int)tape.size();
    long long tape_hash = get_hash(tape);
    if (m == 0 || m > sz) return;

    for(int i = 0; i <= sz - m; i++) {
        long long hash_i_j = (s_h[i + m] - s_h[i] + MOD) % MOD;
        long long required_hash = (tape_hash * p_pref[i]) % MOD;

        if(required_hash == hash_i_j) {
            for(int j = i; j <= i + m - 1; j++) {
                if(!covers[j]) {
                    covers[j] = true;
                    count++;
                }
            }
        }
    }
    return;
}

int main() {
    string s;
    int n, count = 0;
    if (!(cin >> s >> n)) return 0;
    
    int sz = (int)s.size();
    vector<bool> covers(sz, false);
    
    vector<long long> p_pref = p_prefix(sz);
    vector<long long> s_h = h_prefix(s);
    
    vector<string> tapes;
    for(int i = 0; i < n; i++) {
        string tape;
        cin >> tape;
        tapes.push_back(tape);
    }
    
    for(const string& x : tapes) {
        occurences(sz, x, count, covers, s_h, p_pref);
        if(count >= sz) {
            break;
        }
    }
    
    if(count >= sz) cout << "YES";
    else cout << "NO";

    return 0;
}