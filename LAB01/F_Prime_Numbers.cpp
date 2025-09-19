#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if(num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++ )
    {
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2; i <= 1000000; i++){
        if (isPrime(i)){
            count++;
        }
        if (count == n)
        {
            cout << i << endl;
            break;
        }
        
    }
    
    return 0;
}
