
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
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b);

    return 0;
}