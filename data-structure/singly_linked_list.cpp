#include <iostream>
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

void insert_at_head(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

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
    tail = newnode;
}

void insert_at_any_pos(Node*& head, Node*& tail, int pos, int val) {
    if (pos == 0) {
        insert_at_head(head, tail, val);
        return;
    }

    Node* newnode = new Node(val);
    Node* tmp = head;
    for (int i = 1; i < pos; i++) {
        if (tmp == NULL) return;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        return;
    } else if (tmp->next == NULL) {
        insert_at_tail(head, tail, val);
        return;
    }

    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete_at_head(Node*& head, Node*& tail) {
    if (head == NULL) return;

    Node* deletenode = head;
    head = head->next;

    delete deletenode;

    if (head == NULL) {
        tail = NULL;
    }
}

void delete_at_any_pos(Node*& head, Node*& tail, int pos) {
    if (pos == 0) {
        delete_at_head(head, tail);
        return;
    }

    Node* tmp = head;
    for (int i = 1; i < pos; i++) {
        if (tmp == NULL || tmp->next == NULL) return;
        tmp = tmp->next;
    }

    if (tmp->next == NULL) {
        return;
    }

    Node* deletenode = tmp->next;
    tmp->next = tmp->next->next;

    if (tmp->next == NULL) {
        tail = tmp;
    }

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
    delete_at_any_pos(head, tail, 2);  // 20 100 200

    print_forward(head);
    return 0;
}