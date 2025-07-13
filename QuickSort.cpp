#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int i = low - 1, j = low;
    int pivot = arr[high];
    while(j <= high)
    {
        if(j == low and arr[j] < pivot) 
        {
            i++, j++;
            continue;
        }
        if(arr[j] <= pivot)
        {
            swap(arr[++i], arr[j++]);
        }
        else j++;
    }
    return i;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if(low >= high) return;
    int i = partition(arr, low, high);
    QuickSort(arr, low, i - 1);
    QuickSort(arr, i + 1, high);
}

int main()
{
    srand(time(0));
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // for(int i = 0; i < n; i++) arr[i] = rand() % 1000;
    // for(int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;
    QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}