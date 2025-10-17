#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{
    public:
    int sz;
    vector<int> arr;

    MaxHeap(){
        sz = 0;
    }

    int parent(int i){
        return (i - 1 )/ 2;
    }

    int left(int i){
        return i * 2 + 1;
    }

    int right(int i){
        return i * 2 + 2;
    }

    void insert(int val){
        sz++;
        arr.push_back(val);
        int i = sz - 1;
        while(i > 0 && arr[parent(i)] < arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    int getMax(){
        return arr[0];
    }

    void deacreaseMax(){
        arr[0]--;
        heapify(0);
    }

    void heapify(int i){
        int largest = i;
        if(left(i) < sz && arr[left(i)] > arr[largest]){
            largest = left(i);
        }

        if (right(i) < sz && arr[largest] < arr[right(i)])
        {
            largest = right(i);
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }   

};


int main(){
    MaxHeap maxHeap;
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        maxHeap.insert(val);
    }
    long long sum = 0;
    while (x--)
    {
        sum += maxHeap.getMax();
        maxHeap.deacreaseMax();
    }
    cout << sum << endl;
    return 0;
}