#include <bits/stdc++.h>
using namespace std;

void merge2array(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    // int left = mid, right = high;
    while (left <= mid and right <= high)
    // while (left >= low and right >= mid + 1)
    {
        if (arr[left] < arr[right]) // just replace '<' by '>' to have a descending array
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    if (left > mid)
        for (int i = right; i <= high; i++)
            temp.push_back(arr[i]);
    else
        for (int i = left; i <= mid; i++)
            temp.push_back(arr[i]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergesort(vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    if (low == high) return;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    vector<int> temp(high - low + 1);
    merge2array(arr, low, mid, high);
    // merge(arr.begin() + low, arr.begin() + mid + 1, arr.begin() + mid + 1, arr.begin() + high + 1, temp.begin(), greater<>());
    // copy(temp.begin(), temp.end(), arr.begin() + low);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergesort(arr, 0, n - 1);
    for (auto it : arr)
        cout << it << " ";
}