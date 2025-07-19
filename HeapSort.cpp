#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &heap, int size, int j) {
    while (true)
    {
        int left = 2 * j + 1;
        int right = 2 * j + 2;
        int largest = j;
        if(left < size and heap[left] > heap[j]) {
            largest = left;
        }
        if(right < size and heap[right] > heap[largest]) {
            largest = right;
        }
        if(largest != j) {
            swap(heap[largest], heap[j]);
            j = largest;
        }
        else break;
    }
}


void minHeapify(vector<int> &heap, int size, int j) {
    int k = j;
    while (true)
    {
        int left = 2 * (k - j) + 1;
        int right = 2 * (k - j) + 2;
        int largest = k - j;
        if(left < size and heap[j + left] < heap[j + k]) {
            largest = left;
        }
        if(right < size and heap[j + right] < heap[j + largest]) {
            largest = right;
        }
        if(largest != k - j) {
            swap(heap[j + largest], heap[k]);
            k = j + largest;
        }
        else break;
    }
}

void buildMinHeap(vector<int> &heap, int index) {
    int size = heap.size() - index;
    for(int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, heap.size(), index + i);
    }
}

void heapSort(vector<int> &heap) {
    int size = heap.size();
    for(int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
    for(int i = size - 1; i >= 1; i--) {
        swap(heap[0], heap[i]);
        maxHeapify(heap, i, 0);
    }
}

void heapSortUsingMinHeap(vector<int> &heap) {
    int size = heap.size();
    

    for(int i = 0; i < size; i++) {
        buildMinHeap(heap, i);
    }
}

int main() {
    vector<int> v = {1, 3, 5, 3 , 53, 63, 34, 246, 12, 24, 6};
    heapSortUsingMinHeap(v);
    for(auto it : v) cout << it << " ";
}