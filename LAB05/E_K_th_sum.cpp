#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
    public:
    long long  sz;
    vector<long long> arr;
    MinHeap(){
        sz = 0;
    }

    long long  parent(long long  i){
        return (i - 1) / 2;
    }

    long long  left(long long  i ){
        return i * 2 + 1;
    }

    long long  right(long long  i){
        return i * 2 + 2;
    }

    void insert(long long  val){
        sz++;
        arr.push_back(val);
        int i = sz - 1;
        while(i > 0 && arr[parent(i)] > arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void heapify(long long i){
        if(left(i) > sz - 1) return;
        long long j = left(i);

        if(right(i) < sz && arr[right(i)] < arr[j] ){
            j = right(i);
        }
        if(arr[i] > arr[j]){
            swap(arr[i], arr[j]);
            heapify(j);
        }
    }

    long long  getMin(){
        return arr[0];
    }

    void extractMin(){
        swap(arr[0], arr[sz - 1]);
        sz--;
        arr.pop_back();
        heapify(0);
    }


    void printHeap(){
        for(long long  i = 0; i < sz; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    long long  sum(){
        long long total = 0;
        for(long long  i = 0; i < sz; i++){
            total += arr[i];
        }
        return total;
    }
};


int main(){
    long long q,k; cin >> q >> k;
    MinHeap mh;

    while (q--)
    {
        string command; cin >> command;
        
        if(command == "print" ){
            cout << mh.sum() << endl;
        }
        else if(command == "insert"){
            int val; cin >> val;
            if(mh.sz < k){
                mh.insert(val);
            }
            else if(mh.sz == k){
                if(val > mh.getMin()){
                    mh.extractMin();
                    mh.insert(val);
                }
        }
        }  
    }  
    return 0;

}