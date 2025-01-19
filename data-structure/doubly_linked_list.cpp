#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_at_tail(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert_at_any_pos(Node*& head, Node*& tail, int pos, int val) {
    Node* newnode = new Node(val);

    if (pos == 0) {
        insert_at_head(head, tail, val);
        return;
    }

    Node* tmp = head;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        return;
    } else if (tmp->next == NULL) {
        insert_at_tail(head, tail, val);
        return;
    }

    newnode->next = tmp->next;
    newnode->next->prev = newnode;
    tmp->next = newnode;
    newnode->prev = tmp;
}

void delete_at_head(Node*& head, Node*& tail) {
    Node* deletenode = head;

    head = head->next;

    delete deletenode;

    if (head == NULL) {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}
void delete_at_tail(Node*& head, Node*& tail) {
    Node* deletenode = tail;

    tail = tail->prev;
    delete deletenode;

    if (tail == NULL) {
        head = NULL;
        return;
    }
    tail->next = NULL;
}
void delete_at_any_pos(Node*& head, Node*& tail, int pos) {
    if (pos == 0) {
        delete_at_head(head, tail);
        return;
    }

    Node* tmp = head;
    for (int i = 1; i <= pos; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        return;
    } else if (tmp->next == NULL) {
        delete_at_tail(head, tail);
        return;
    }

    Node* deletenode = tmp;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    delete deletenode;
}

void print_forward(Node* head) {
    Node* tmp = head;

    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node* tail) {
    Node* tmp = tail;

    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    insert_at_any_pos(head, tail, 2, 100);
    insert_at_any_pos(head, tail, 3, 200);

    delete_at_head(head, tail);
    delete_at_tail(head, tail);
    delete_at_any_pos(head, tail, 2);  // 20 100 200

    print_forward(head);
    print_backward(tail);
    return 0;
}