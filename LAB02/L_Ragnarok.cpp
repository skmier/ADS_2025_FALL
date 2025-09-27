# include <iostream>
# include <algorithm>
#include <climits>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
	if(!head) return INT_MIN;
    int max_sum = INT_MIN;
    int current_sum = 0;
    Node* current = head;
    
    while (current)
    {
        int x = current->val;
        current_sum = max(x, current_sum + x);
        max_sum = max(max_sum, current_sum);
        current = current->next;
    }
    return max_sum;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) ;
  return 0;
}
