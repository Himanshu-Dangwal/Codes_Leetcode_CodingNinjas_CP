/*
You are given an array A of length N. You are required to count the number of pairs (i, j) where 1 &le; i < j &le; N such that A[j] - A[i] = i<sup>2</sup> + j<sup>2</sup>.
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

int countPairs(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, vector<int>> mp;

    // Since we need to calculate the number of pairs such that A[j] - A[i] = i^2+j^2;
    // I can simply change the quation to A[i]+i^2 = A[j]-j^2;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i] + ((i + 1) * (i + 1));
        if (mp.find(val) != mp.end())
        {
            auto array = mp[val];
            array.push_back(i);
            mp[val] = array;
        }
        else
        {
            vector<int> array;
            array.push_back(i);
            mp[val] = array;
        }
    }
    int ans = 0;
    for (int j = 1; j < n; j++)
    {
        int val = arr[j] - (j + 1) * (j + 1);
        if (mp.find(val) != mp.end())
        {
            ans += mp[val].size();
        }
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; cin >> arr[i++])
        ;

    cout << countPairs(arr);
}