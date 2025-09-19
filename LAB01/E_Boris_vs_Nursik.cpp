#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    deque<int> boris, nursik;
    for(int i = 0; i < 5; i++){
        int n; cin >> n;
        boris.push_back(n);
    }
    for(int i = 0; i < 5; i++){
        int n; cin >> n;
        nursik.push_back(n);
    }
    
    int count = 0;
    int max_count = 1000000;

    while (!boris.empty() && !nursik.empty() && count < max_count)
    {
        int first_bor_card = boris.front();
        int first_nursik_card = nursik.front();
        boris.pop_front();
        nursik.pop_front();
        count++;

        if(first_bor_card == 0 && first_nursik_card == 9  || (first_bor_card > first_nursik_card && !(first_bor_card == 9 && first_nursik_card == 0))){
            boris.push_back(first_bor_card);
            boris.push_back(first_nursik_card);
        }else if((first_bor_card == 9 && first_nursik_card == 0) ||(first_bor_card < first_nursik_card && !(first_bor_card == 0 && first_nursik_card == 9 )) ){
            nursik.push_back(first_bor_card);
            nursik.push_back(first_nursik_card);
            
        }
    }


    if(count == max_count){
        cout << "blin nichya";
    }
    else if (boris.empty()) {
        cout << "Nursik" << " " << count;
    }
    else if (nursik.empty()){
        cout << "Boris" << " " << count;
    } 
    return 0;
}