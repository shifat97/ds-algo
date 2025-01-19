#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(h) where h is the height of the tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        Node *myLeft, *myRight;
        cin >> l >> r;

        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        f->left = myLeft;
        f->right = myRight;

        if (myLeft)
            q.push(myLeft);
        if (myRight)
            q.push(myRight);
    }

    return root;
}

// Function to search a value in a binary search tree
bool search(Node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

// Insert in a binary search tree
void insert(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }

    if (val < root->data)
    {
        insert(root->left, val);
    }
    else if (val > root->data)
    {
        insert(root->right, val);
    }
}

// Sorted array to BST
Node *sortedArrayToBST(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    Node *root = new Node(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

void print(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->data << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{
    Node *root = input_tree();
    int val;
    cin >> val;
    bool ans = search(root, val);
    if (ans)
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;

    insert(root, val);
    print(root);

    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // Node *root = sortedArrayToBST(a, 0, n - 1);
    // print(root);
    return 0;
}