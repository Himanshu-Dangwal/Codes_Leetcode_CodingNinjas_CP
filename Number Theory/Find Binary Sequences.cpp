/*

Find binary sequences
Time Limit: 2, Memory Limit: 128000
You're given an integer n. Find out the number of all binary sequences of length 2*n such that sum of first n bits is same as sum of last n bits.
The anwer can be very large. So, you have to return answer modulo 109+7.
Input
An integer: n ( 1<= n <= 104)
Output
Return the number of binary sequences.
Example
Input:
2
Output:
6
Explanation:
There are 6 sequences of length 2*n, the sequences are 0101, 0110, 1010, 1001, 0000 and 1111.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcdextended(ll a, ll b, ll &x, ll &y)
{

    if (a == 0)
    {

        x = 0;

        y = 1;

        return b;
    }

    ll x1, y1;

    ll g = gcdextended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;

    y = x1;

    return g;
}

ll modinverse(ll b, ll m)

{

    ll int x, y;

    ll int g = gcdextended(b, m, x, y);

    if (g != 1)

        return 1;

    return (x % m + m) % m;
}

ll compute_value(int n)

{

    // total no.of count = (nC0)^2 + (nC1)^2 + (nC2)^2 +...+(nCn)^2 i.e (2nCn)

    // 2nCn = 2n!/n!n! = 2n!/(n!)^2

    // or nCr = nC(r-1) * (n-(r-1))/r

    ll mod = 1e9 + 7;

    ll nCr = 1, ans = 1;

    for (int i = 1; i <= n; i++)
    {

        nCr = (((nCr * (n + 1 - i)) % mod) * modinverse(i, mod)) % mod;

        ans = (ans % mod + (nCr * nCr) % mod) % mod;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << compute_value(n) << endl;
    return 0;
}
