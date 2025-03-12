#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void insert(list<int>& lst, int x, int p) {
    auto it = lst.begin();
    advance(it, p);
    lst.insert(it, x);
}

void remove(list<int>& lst, int p) {
    auto it = lst.begin();
    advance(it, p);
    lst.erase(it);
}

void print(const list<int>& lst) {
    if (lst.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto& val : lst) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void replace(list<int>& lst, int p1, int p2) {
    auto it1 = lst.begin();
    advance(it1, p1);
    int value = *it1;
    lst.erase(it1);
    auto it2 = lst.begin();
    advance(it2, p2);
    lst.insert(it2, value);
}

void reverse(list<int>& lst) {
    lst.reverse();
}

void cyclic_left(list<int>& lst, int x) {
    for (int i = 0; i < x; ++i) {
        lst.push_back(lst.front());
        lst.pop_front();
    }
}

void cyclic_right(list<int>& lst, int x) {
    for (int i = 0; i < x; ++i) {
        lst.push_front(lst.back());
        lst.pop_back();
    }
}

int main() {
    list<int> lst;
    int command;
    while (cin >> command) {
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p;
            cin >> x >> p;
            insert(lst, x, p);
        } else if (command == 2) {
            int p;
            cin >> p;
            remove(lst, p);
        } else if (command == 3) {
            print(lst);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            replace(lst, p1, p2);
        } else if (command == 5) {
            reverse(lst);
        } else if (command == 6) {
            int x;
            cin >> x;
            cyclic_left(lst, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            cyclic_right(lst, x);
        }
    }
    return 0;
}