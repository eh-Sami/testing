#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
    int l = -1, r = 16, m; 
    int t;
    cin >> t;
    while (l < r - 1)
    {
        m = (l + r) / 2;
        if (t < a[m])
        {
            r = m;
            // cout << a[r] << endl;
        }
        else
        {
            l = m;
            // cout << a[r] << endl;
        }
    }
    // cout << m << endl;
    cout << a[l];
    cout << endl << l;
    // if (a[l] == t)
    //     cout << "YES(" << l + 1 << ")" << endl;k
    // else if (a[r] == t)
    //     cout << "YES(" << r + 1 << ")" << endl;
    // else
    //     cout << "NO" << endl;
    // vector<int> a = {21, 42, 134, 52, 123, 52};
    // sort(a.begin(), a.end());
    // cout << find(a.begin(), a.end(), 42) - a.begin();
}