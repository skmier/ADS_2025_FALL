#include <iostream>
#include <string>

using namespace std;

int main(){
    string a,b; cin >> a >> b;
    int count = 0;
    int t = a.length();
    if(a == b){ 
        cout << 0 << endl;
        return 0;
    }
   
    while (t--){
        char temp = a.back();
        a.pop_back();
        a = temp + a;
        count++;
        if(a == b){
            cout << count;
            return 0;
        }            
    }
    cout << -1;
}