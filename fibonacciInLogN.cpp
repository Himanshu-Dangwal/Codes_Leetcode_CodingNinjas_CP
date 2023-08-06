
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
#define MAX 1000000

typedef long long ll;
#define MOD 1000000007

using namespace std;

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

void multiply2(vector<int> &A, vector<vector<int>> &B)
{

    vector<int> res(2, 0);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i] += A[j] * B[i][j];
        }
    }

    A[0] = res[0];
    A[1] = res[1];
}

int fib(int n)
{

    int f1 = 1;
    int f2 = 1;

    // [f1 f2][A B]   = [f2 f3]
    //        [C D]

    // A*F1 + C*F2 = F2  =>  A=0,C=1
    // B*F1 + D*F2 = F3  => We know that F3 = f2+f1
    //                   => B=D=1

    vector<vector<int>> I(2, vector<int>(2, 0));
    I[0][0] = I[1][1] = 1;

    vector<vector<int>> mat(2, vector<int>(2));
    mat[0][0] = 0;
    mat[0][1] = 1;
    mat[1][0] = mat[1][1] = 1;

    n = n - 2;

    while (n)
    {
        if (n % 2)
            multiply(I, mat), n--;
        else
            multiply(mat, mat), n /= 2;
    }

    vector<int> f(2);
    f[0] = f[1] = 1;

    multiply2(f, I);
    return f[1];
}

int main()
{

    int n;
    cin >> n;

    cout << fib(n);

    return 0;
}