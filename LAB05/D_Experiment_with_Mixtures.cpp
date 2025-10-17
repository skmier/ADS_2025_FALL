#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
    public:
    int sz;
    vector<int> arr;

    MinHeap(){
        sz = 0;
    }

    int parent(int i){
        return (i - 1) / 2;
    }

    int left(int i ){
        return i * 2 + 1;
    }

    int right(int i){
        return i * 2 + 2;
    }

    void insert(int val){
        sz++;
        arr.push_back(val);
        int i = sz - 1;
        while (i > 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void heapify(int i){
       int smallest = i;
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

    int getMin(){
        return arr[0];
    }

    void extractMin(){
        swap(arr[0], arr[sz - 1]);
        sz--;
        arr.pop_back();
        if(sz > 0){
            heapify(0);
        }
    }


    void printHeap(){
        for(int i = 0; i < sz; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    int n, m; cin >> n >> m;
    MinHeap minHeap;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        minHeap.insert(val);
    }

    int count = 0;
    while (minHeap.sz > 1 && minHeap.getMin() < m){
        int first = minHeap.getMin();
        minHeap.extractMin();
        int second = minHeap.getMin();
        minHeap.extractMin();
        int mixture = first + 2 * second;
        minHeap.insert(mixture);
        count++;
    }
    
    if(minHeap.getMin() < m){
        cout << -1 << endl;
    } else {
        cout << count << endl;
    }
}