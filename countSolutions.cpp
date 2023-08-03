/*
Problem Statement :

Given two integers N and P, your task is to find the number of integral solutions to:-
 x<sup>2</sup> = 1 (mod P) such that 1 <= x <= N

 Sample Input:-
10 5

Sample Output:-
4

Explanation:-
1 4 6 9 are the required values of x.

Sample Input:-
10 2

Sample Output:-
5

*/

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

int countSolutions(int n, int p)
{

    int ans = 0;
    for (int i = 1; i < p; i++)
    {
        if ((i * i) % p == 1)
        {
            int last = i + p * (n / p);

            if (last > n)
            {
                last -= p;
            }

            int count = (last - i) / p + 1;
            ans += count;
        }
    }

    return ans;
}

int main()
{

    int n, p;
    cin >> n >> p;

    cout << countSolutions(n, p);
}