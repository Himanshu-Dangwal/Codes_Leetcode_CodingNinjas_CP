
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

class Triplet
{
public:
    int x, y, gcd;
};

Triplet extendedEuclid(int a, int b)
{

    if (b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet ans;
    Triplet smallAns = extendedEuclid(b, a % b);
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;

    return ans;
}

int main()
{

    int a, b;
    cin >> a >> b;

    Triplet ans = extendedEuclid(a, b);

    cout << ans.x << " " << ans.y;

    return 0;
}