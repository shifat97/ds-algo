#include <bits/stdc++.h>
using namespace std;

class MyStack {
   public:
    vector<int> v;

    void push(int val) { v.push_back(val); }

    void pop() { v.pop_back(); }

    int top() { return v.back(); }

    int size() { return v.size(); }

    bool empty() {
        if (v.empty())
            return true;
        else
            return false;
    }

    void print() {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
};

void solve() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.print();

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;
}

int main() {
    solve();
    return 0;
}