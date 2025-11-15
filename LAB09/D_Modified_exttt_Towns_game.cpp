#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<int> prefix_fun(string pattern){
    int n = pattern.size();
    vector<int> p(n);
    int i = 1; 
    int j = 0;
    while (i < n)
    {
        if(pattern[i] == pattern[j]){
            j++;
            p[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = p[j-1];
            }
            else{
                p[i] = 0;
                i++;
            }
        }
    }   
    return p;
}


int main(){
    string s;
    cin >> s;
    int n; cin >> n;
    vector<string> cities(n);
    for(int i = 0; i < n; i++){
        cin >> cities[i];
    }

    int maxx = 0;
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    vector<pair<string,int>> res;
    for(int i = 0; i < n; i++){
        string org_city = cities[i];
        string city = cities[i];
        transform(city.begin(),city.end(),city.begin(), ::tolower);
        string k = city + "#" + s;
        vector<int> p = prefix_fun(k);
        int t = p[p.size() - 1];
        res.push_back({org_city,t});
        maxx = max(maxx,t);
    }


    vector<string> output;
    for(int i = 0; i < n; i++){
        if(res[i].second == maxx && res[i].second > 0) 
            output.push_back(res[i].first);
    }

    cout << output.size() << endl;
    for(auto x:output){
        cout << x << endl;
    }
}   