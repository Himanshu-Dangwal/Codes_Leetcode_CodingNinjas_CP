
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

typedef long long ll;
#define MOD 1000000007
#define MAX 100000
using namespace std;

vector<int> sieve()
{
    vector<bool> arr(MAX, true);

    for (int i = 2; i * i < MAX; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j * j < MAX; j += i)
            {
                arr[j] = false;
            }
        }
    }

    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < MAX; i += 2)
    {
        if (arr[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

void printPrimes(ll l, ll r, vector<int> &primes)
{
    vector<bool> isPrimes(r - l + 1, true);

    for (int i = 0; primes[i] * (ll)primes[i] <= r; i++)
    {
        int curr = primes[i];

        int base = (l / curr) * curr;
        if (base < l)
        {
            base += curr;
        }

        for (int j = base; j <= r; j += curr)
        {
            isPrimes[j - l] = false;
        }

        if (base == curr)
        {
            isPrimes[base] = true;
        }
    }

    for (int i = 0; i < isPrimes.size(); i++)
    {
        if (isPrimes[i] == true)
        {
            cout << (i + l) << " ";
        }
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    vector<int> primes = sieve();
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        printPrimes(l, r, primes);
    }

    return 0;
}