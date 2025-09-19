#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool isprime = true;
    for (int i = 2; i < sqrt(n); i++ )
    {
        if (n % i == 0){
            isprime = false;
            break;
        }
    }

    if(n <=1) isprime = false;
    if (isprime) cout << "YES";
    else cout << "NO";
    
}