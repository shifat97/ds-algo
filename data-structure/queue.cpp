#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyQueue {
   public:
    Node* head = NULL;
    Node* tail = NULL;
    int count = 0;

    void push(int val) {
        count++;
        Node* newnode = new Node(val);

        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;
    }

    void pop() {
        count--;
        Node* tmp = head;
        head = head->next;
        delete tmp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    int front() { return head->val; }
    int back() { return tail->val; }
    int size() { return count; }
    int empty() { return head == NULL; }
};

int main() {
    MyQueue q;
    int n;
    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        q.push(val);
    }
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    return 0;
}