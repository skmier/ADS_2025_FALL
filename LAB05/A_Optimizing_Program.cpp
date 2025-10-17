#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
    public:
    long long sz;
    vector<long long> arr;

    MinHeap(){
        sz = 0;
    }

    long long parent(int i){
        return (i - 1) / 2;
    }

    long long left(int i){
        return 2 * i + 1;
    }

    long long right(int i){
        return 2 * i + 2;
    }

    void insert(long long val){
        sz++;
        arr.push_back(val);
        long long i = sz -1;
        while(i > 0 && arr[parent(i)] > arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    long long getMin(){
        return arr[0];
    }

    void heapify(int i){
        long long smallest = i;

        if(left(i) < sz && arr[left(i)] < arr[smallest]){
            smallest = left(i);
        }

        if(right(i) < sz && arr[right(i)] < arr[smallest]){
            smallest = right(i);
        }   

        if(smallest != i){
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void extractMin(){
        swap(arr[0], arr[sz - 1]);
        sz--;
        arr.pop_back();
        heapify(0);
    }
};

int main(){
    MinHeap minHeap;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int val; cin >>val;
        minHeap.insert(val);
    }

    long long sum = 0;
    while(minHeap.sz > 1){
        long long first = minHeap.getMin();
        minHeap.extractMin();
        long second = minHeap.getMin();
        minHeap.extractMin();
        sum += (first + second);
        minHeap.insert(first + second);
    }

    cout << sum << endl;
    return 0;
}