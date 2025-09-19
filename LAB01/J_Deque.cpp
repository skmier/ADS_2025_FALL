#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    string command;
    deque<int> mydeq;
    vector<string> output;
    while (cin >> command){
        if (command == "+"){
            int n ; cin >> n;
            mydeq.push_front(n);
        }
        else if(command == "-"){
            int n ; cin >> n;
            mydeq.push_back(n);
        }
        else if(command == "*"){
            if(mydeq.empty()){
                output.push_back("error");
            }
            else if(mydeq.size() == 1){
                output.push_back(to_string(mydeq.front()*2));
                mydeq.pop_front();
            }
            else{
                output.push_back(to_string(mydeq.front() + mydeq.back()));
                mydeq.pop_front();
                mydeq.pop_back();
            }
        }
        else if (command == "!"){
            break;
        }
    }
    
    for(string i : output){
        cout << i << endl;
    }

}