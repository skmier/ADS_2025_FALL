#include <iostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node* next;

    Node(string val){
        data = val;
        next = nullptr;
    }
};

struct LinkedList{
private:
    Node* head ;
    Node* tail;
public:
    LinkedList(){
        head = tail = nullptr;
    }

    void push_pack(string val){
        Node* newNode = new Node(val);
        if(!head) {
            head = tail = newNode;
            return;
        }
       tail->next = newNode;
       tail = newNode;
    }

 
    void leftToRight(int n,int k){
        if (!head || n <= 1) return;   
        k %= n;
        if (k == 0) return;            

        tail->next = head;

     
        Node* newtail = head;
        for (int i = 0; i < k - 1; ++i) {
            newtail = newtail->next;
        }

        
        Node* newhead = newtail->next;

        newtail->next = nullptr;
        head = newhead;
        tail = newtail;
    }

    void printList(){
        Node* current = head;
        while (current)
        {
            cout << current->data;
            if (current->next) cout << " ";
            current= current->next;
        }
        cout << endl;
    }

    ~LinkedList(){
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }
};


int main(){

    int n, k;
    cin >> n >> k;
    LinkedList mylist;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        mylist.push_pack(t);
    }
    mylist.leftToRight(n,k);
    mylist.printList();
}
