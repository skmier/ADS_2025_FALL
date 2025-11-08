#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int base = 31, MOD = 1e9 + 7;

unsigned long long get_hash(string s)
{
    unsigned long long h = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h = (h * base + (s[i] - 'a' + 1));
    }
    return h;
}

bool occur(string s, string t)
{
    unsigned long long hs = get_hash(s.substr(0, t.size()));
    unsigned long long ht = get_hash(t);
    unsigned long long pm = 1;
    for (int i = 0; i < t.size() - 1; i++)
    {
        pm *= base;
    }
    for (int i = 0; i + t.size() <= s.size(); i++)
    {
        if (hs == ht)
            return true;
        if (i + t.size() < s.size())
            hs = (hs - pm * (s[i] - 'a' + 1)) * base + (s[i + t.size()] - 'a' + 1);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    int min_size = 5001, max_size = 0;
    string min_str, res;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (min_size > s.size())
        {
            min_size = s.size();
            min_str = s;
        }
        a[i] = s;
    }
    for (int i = 0; i < min_size; i++)
    {
        for (int j = i; j < min_size; j++)
        {
            string sub = min_str.substr(i, min_size - j);
            bool flag = true;
            for (int l = 0; l < n; l++)
            {
                if (!occur(a[l], sub))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                if (max_size < sub.size())
                {
                    max_size = sub.size();
                    res = sub;
                }
            }
        }
    }
    cout << res;
}