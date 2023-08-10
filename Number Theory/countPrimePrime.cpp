
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
vector<int> ans(MAX, 0);

void sieve()
{
    vector<bool> arr(MAX, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i * i < MAX; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                arr[j] = false;
            }
        }
    }

    unordered_set<int> primes;
    primes.insert(2);
    for (int i = 3; i < MAX; i += 2)
    {
        if (arr[i])
            primes.insert(i);
    }

    int cnt = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (primes.find(i) != primes.end())
        {
            cnt++;
            if (arr[cnt])
            { // if cnt is a primes number
                ans[i] = ans[i - 1] + 1;
            }
            else
            {
                ans[i] = ans[i - 1];
            }
        }
        else
        {
            if (arr[cnt])
            {
                ans[i] = ans[i - 1] + 1;
            }
            else
            {
                ans[i] = ans[i - 1];
            }
        }
    }
}

int main()
{

    sieve();
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        cout << (ans[r] - ans[l - 1]) << endl;
    }

    return 0;
}