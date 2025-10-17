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
        return (i - 1) / 2;
    }

    int left(int i){
        return i * 2 +1;
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
        if(sz == 0) return -1;
        return arr[0];
    }

    void heapify(int i){
        int largest = i;

        if(left(i) < sz && arr[left(i)] > arr[largest]){
            largest = left(i);
        }

        if(right(i) < sz && arr[right(i)] > arr[largest]){
            largest = right(i);
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void extractMax(){
        swap(arr[0], arr[sz - 1]);
        sz--;
        arr.pop_back();
        heapify(0);
    }
};


int main(){
    MaxHeap maxHeap;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        maxHeap.insert(val);
    }

    while (maxHeap.sz > 1)
    {
        int x = maxHeap.getMax();
        maxHeap.extractMax();
        int y = maxHeap.getMax();
        maxHeap.extractMax();
        if(x > y){
            maxHeap.insert(x - y);
        }
    }
    
    if(maxHeap.sz == 0){
        cout << 0 << endl;
    } else {
        cout << maxHeap.getMax() << endl;
    }
}