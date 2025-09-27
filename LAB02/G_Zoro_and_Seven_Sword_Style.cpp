#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* temp = head;
    for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;

    Node* temp = head;
    Node* prev1 = nullptr;
    for (int i = 0; i < p1; ++i) {
        prev1 = temp;
        temp = temp->next;
    }
    Node* node1 = temp;

    if (prev1) {
        prev1->next = node1->next;
    } else {
        head = node1->next;
    }

    if (p2 == 0) {
        node1->next = head;
        return node1;
    }

    temp = head;
    for (int i = 0; i < p2 - 1; ++i) {
        temp = temp->next;
    }
    node1->next = temp->next;
    temp->next = node1;

    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

string listToString(Node* head) {
    if (!head) return "-1";
    string res = "";
    Node* temp = head;
    while (temp) {
        res += to_string(temp->val) + " ";
        temp = temp->next;
    }
    return res;
}

Node* cyclic_left(Node* head, int x) {
    if (!head || x == 0) return head;

    Node* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    x = x % len;
    if (x == 0) return head;

    Node* new_tail = head;
    for (int i = 0; i < x - 1; ++i) {
        new_tail = new_tail->next;
    }

    Node* new_head = new_tail->next;
    new_tail->next = nullptr;
    tail->next = head;
    return new_head;
}

Node* cyclic_right(Node* head, int x) {
    if (!head || x == 0) return head;

    Node* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    x = x % len;
    if (x == 0) return head;

    return cyclic_left(head, len - x);
}

int main() {
    Node* head = nullptr;
    vector<string> history;

    while (true) {
        int command; cin >> command;
        if (command == 0) break;
        else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if(command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }
        else if(command == 3){
            history.push_back(listToString(head));
        }
        else if(command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if(command == 5){
            head = reverse(head);
        }
        else if(command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }
        else if(command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }

    for (string s : history) {
        cout << s << endl;
    }

    return 0;
}
