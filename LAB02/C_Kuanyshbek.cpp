#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }
    
    void pushh_back(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        } 
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteEverySecond(){
        if(!head) return;
        Node* first = head;
        while (first && first->next){
            Node* temp = first->next;
            first->next = temp->next;
            delete temp;
            first = first->next;
        }

    }

    void printList(){
        Node* current = head;
        while(current){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};


int main(){
    int n;
    cin >> n;
    LinkedList mylist;
    for(int i = 0; i < n ; i++){
        int val;
        cin >> val;
        mylist.pushh_back(val);
    }
    mylist.deleteEverySecond();
    mylist.printList();
}