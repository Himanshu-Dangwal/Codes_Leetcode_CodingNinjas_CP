#include "bits/stdc++.h"
using namespace std;

void heapify(vector<int> &arr, int n, int idx)
{

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int maxIdx = idx;
    if (left < n && arr[left] > arr[maxIdx])
    {
        maxIdx = left;
    }

    if (right < n && arr[right] > arr[maxIdx])
    {
        maxIdx = right;
    }

    if (maxIdx != idx)
    {
        swap(arr[idx], arr[maxIdx]);
        heapify(arr, n, maxIdx);
    }
}

void heapsort(vector<int> &arr)
{
    int n = arr.size();

    // Convert array into max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    heapsort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}