
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

typedef long long ll;
#define MOD 1000000007

using namespace std;

int dim;

void multiply(vector<vector<int>> &A, vector<vector<int>> &B)
{

    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

int power(vector<vector<int>> &arr, int n)
{
    int dim = arr.size();
    vector<vector<int>> I(dim, vector<int>(dim));

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    while (n)
    {
        if (n % 2)
            multiply(I, arr), n--;
        else
            multiply(arr, arr), n /= 2;
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << I[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int dim, n;
    cin >> dim >> n;

    vector<vector<int>> arr(dim, vector<int>(dim));

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cin >> arr[i][j];
        }
    }

    power(arr, n);
    return 0;
}
