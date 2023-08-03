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

using namespace std;

vector<int> primes;
bool sievePrimes[100000000];

void sieve()
{

    for (int i = 2; i < 100000000; i++)
    {
        sievePrimes[i] = true;
    }

    for (int i = 2; i * i < 100000000; i++)
    {
        if (sievePrimes[i] == true)
        {
            for (int j = i * i; j * j < 100000000; j += i)
            {
                sievePrimes[j] = false;
            }
        }
    }

    for (int i = 2; i < 100000000; i++)
    {
        if (sievePrimes[i])
            primes.push_back(i);
    }
}

long long divisorsOfFactorial(int n)
{

    long long ans = 1;

    for (int i = 0; primes[i] <= n; i++)
    {

        int curr = primes[i];
        int cnt = 0;
        while (curr <= n)
        {
            cnt += n / curr;
            curr *= curr;
        }
        cout << cnt << " ";
        ans = ans * (cnt + 1);
    }
    cout << endl;
    return ans;
}

int main()
{

    sieve();
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << divisorsOfFactorial(n);
    }
}