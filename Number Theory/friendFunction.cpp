
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

using namespace std;

class B;
class A
{
private:
    int a;

public:
    void setValue(int x) { a = x; }
    friend void fun(A, B);
};

class B
{
private:
    int b;

public:
    void setValue(int x) { b = x; }
    friend void fun(A, B);
};

void fun(A obj1, B obj2)
{
    cout << obj1.a << " " << obj2.b << endl;
}

// void dummy(A obj1, B obj2)
// {
//     cout << obj1.a << " " << obj2.b << endl;
// }

int main()
{
    A obj1;
    obj1.setValue(10);
    B obj2;
    obj2.setValue(15);
    fun(obj1, obj2);
    // dummy(obj1, obj2);
    return 0;
}