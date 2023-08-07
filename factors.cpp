
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

void factors(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";

            while (n % i == 0)
                n /= i;
        }
    }

    if (n != 1)
    {
        cout << n << " ";
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        factors(n);
    }

    return 0;
}