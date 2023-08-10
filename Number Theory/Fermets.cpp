// Fermets Little Theorem to find multiplicative modulo inverse of a number a under a modulo m.

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

int power(int a, int n, int p)
{

    int ans = 1;

    while (n)
    {
        if (n % 2)
            ans = (ans * a) % p, n--;
        else
            a = (a * a) % p, n /= 2;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, m;
        cin >> a >> m;

        cout << power(a, m - 2, m) << endl;
    }

    return 0;
}