
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    int t;
    cin >> t;

    vector<int> prefix(n), suffix(n);
    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = gcd(prefix[i - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = gcd(suffix[i + 1], arr[i]);
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int a = l == 0 ? 0 : prefix[l - 1];
        int b = r == n - 1 ? 0 : suffix[r + 1];
        cout << gcd(a, b) << endl;
    }

    return 0;
}