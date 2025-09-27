#include <iostream>
#include <vector>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node* prev;
    Node(string val){
        data = val;
        next = prev =  nullptr;
    }
};

struct DoubleLinkedList
{
public:
    Node* head;
    Node* tail;

    DoubleLinkedList(){
        head = tail = nullptr;
    }

    void add_front(string val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            return;
        } 
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        
    }

    void add_back(string val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            return;
        } 
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void erease_front(){
        if(!head) return;
        Node* tmp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
    }

    void erease_back(){
        if(!head) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        
        delete tmp;
    }

    string front(){
        if(!head) return "error";
        return head->data;
    }

    string back(){
        if(!head) return "error";
        return tail->data;
    }

    void clear(){
        while (head)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
    }
    bool isEmpty() {
    return head == nullptr;
    }
};


int main(){
    DoubleLinkedList list;
    string command;
    vector<string> output;
    while (true)
    {
        cin >> command;
        if (command == "add_front"){
            string t; cin >> t;
            list.add_front(t);
            output.push_back("ok");
        }
        else if(command == "add_back"){
            string t; cin >> t;
            list.add_back(t);
            output.push_back("ok");
        }
        else if(command == "erase_front"){
            output.push_back(list.front());
            list.erease_front();
        }
        else if(command == "erase_back"){
            output.push_back(list.back());
            list.erease_back();
        }
        else if(command == "front"){
            if(list.isEmpty()){
                output.push_back("error");
            } else output.push_back(list.front());
        }
        else if(command == "back"){
            if(list.isEmpty()){
                output.push_back("error");
            } else output.push_back(list.back());
        }
        else if(command == "clear"){
            list.clear();
            output.push_back("ok");
        }
        else if(command == "exit"){
            output.push_back("goodbye");
            break;
        }
    }

    for(auto x:output){
        cout << x << endl;
    }
    return 0;
}






