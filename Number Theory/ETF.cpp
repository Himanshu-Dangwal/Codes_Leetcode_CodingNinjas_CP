
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

int ETF(int n)
{

    int ans = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans *= (i - 1);
            ans /= i;

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        ans *= (n - 1);
        ans /= n;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << "ETF of " << n << " = " << ETF(n) << endl;
    }

    return 0;
}