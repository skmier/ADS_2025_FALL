#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

struct LinkedList{
public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    void printList(){
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void insert0fNode(int num, int pos){
        Node* number = new Node(num);
        if(pos == 0){
            number->next = head;
            head = number;
            return;
        }

        Node* current = head;
        int count = 0;
        while (current && count < pos-1)
        {
            current = current->next;
            count++;
        }

        number->next = current->next;
        current->next = number;
    }
};

int main(){
    int n ; cin >> n;
    LinkedList mylist;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        mylist.push_back(t);
    }
    int num; cin >> num;
    int pos; cin >> pos;
    mylist.insert0fNode(num, pos);
    mylist.printList();
}
