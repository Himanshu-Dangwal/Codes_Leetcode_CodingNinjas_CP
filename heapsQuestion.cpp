#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0, zr = 0;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            zr++;
        if (a[i] < 0)
        {
            neg++;
            mx = max(mx, a[i]);
        }
    }
    if (neg % 2 == 0)
    {
        cout << zr << endl;
    }
    else
    {
        cout << zr + (-1 * mx) + 1 << endl;
    }
}