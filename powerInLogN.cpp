
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

typedef long long ll;
#define MOD 1000000007

using namespace std;
#define MAX 1000000

typedef long long ll;
#define MOD 1000000007

using namespace std;

int power(int a, int n)
{
    int ans = 1;

    while (n)
    {
        if (n % 2)
            ans = ans * a, n--;
        else
            a = a * a, n /= 2;
    }

    return ans;
}

int main()
{

    int a, n;
    cin >> a >> n;

    cout << power(a, n);

    return 0;
}
