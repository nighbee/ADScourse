#include <bits/stdc++.h>
using namespace std;

struct minHeap {
    vector<long long> heap;

    long long parent(long long i) {
        return (i - 1) / 2;
    }

    long long left(long long i) {
        return (2 * i + 1);
    }

    long long right(long long i) {
        return (2 * i + 2);
    }

    void insert(long long val) {
        heap.push_back(val);
        long long i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(long long i) {
        long long l = left(i);
        long long r = right(i);
        long long smallest = i;
        if (l < heap.size() && heap[l] < heap[i]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    long long extractMin() {
        if (heap.size() == 0) return 0;
        if (heap.size() == 1) {
            long long root = heap[0];
            heap.pop_back();
            return root;
        }
        long long root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return root;
    }

    long long optimize() {
        long long cost = 0;
        while (heap.size() > 1) {
            long long min1 = extractMin();
            long long min2 = extractMin();
            long long sum = min1 + min2;
            insert(sum);
            cost += sum;
        }
        return cost;
    }

    void print() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    long long n;
    cin >> n;
    minHeap heap;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap.insert(x);
    }

    cout << heap.optimize() << endl;

    return 0;
}