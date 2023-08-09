// Finding any solution for the equation ax+by = c;

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

int extendedEuclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int xo, yo;
    int smallAns = extendedEuclid(b, a % b, xo, yo);

    x = yo;
    y = xo - (a / b) * yo;

    return smallAns;
}

bool findAnySolution(int a, int b, int c, int &x, int &y)
{
    int xo, yo;
    int g = extendedEuclid(a, b, xo, yo);
    if (c % g)
        return false;

    x = (xo * c) / g;
    y = (yo * c) / g;

    return true;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, x, y;
        cin >> a >> b >> c;

        if (findAnySolution(a, b, c, x, y) == false)
        {
            cout << "No solution exists";
        }
        else
        {
            cout << x << " " << y << endl;
        }
    }

    return 0;
}