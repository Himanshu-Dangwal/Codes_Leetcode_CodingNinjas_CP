#include<iostream>
using namespace std;
#define pb push_back
typedef long long ll;


vector<int> primes;
bool arr[1000000];

void sieve(){
    arr[0] = arr[1] = true;
    for(int i=2;i*i<1000000;i++){
        if(!arr[i]){
            for(int j=i*i;j<1000000;j+=i){
                arr[i] = true;
            }
        }
    }
}

int main(){
    
    sieve();
    for(int i=0;i<1000000;i++){
        if(!arr[i]) primes.pb(i);
    }

    for(int i=0;i<primes.size();i++) cout<<primes[i]<<" ";
}