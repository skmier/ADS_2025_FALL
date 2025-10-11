#include <iostream>

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
public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void push_back(string val){
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
        int count = 0;
        while (current)
        {
            count++;
            current = current->next;
        }

        cout << "All in all: " << count << endl; 
        cout << "Students:" << endl; 
        current = head;
        while (current)
        {
            cout << current->data << endl;
            current = current->next;
        }
        
    }
};


int main(){
    int n; cin >> n;
    LinkedList mylist;
    string emp = "";
    for(int i = 0; i < n; ++i){
        string t; cin >> t;
        if(t !=emp){
            mylist.push_back(t);
        }
        emp = t;
    }
    mylist.printList();
}
