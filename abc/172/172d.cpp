#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;


int prime[10000000];
bool is_prime[100000000 + 1];
 
int sieve(int n) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
 
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
 
    return pcnt;
}
 
ll divs(ll n) {
    ll res = 0;
    for(ll i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            res ++;

            if(i != n/i) {
                res ++;
            }
        }
    }

  
    return res;
}

void solve1() {
    ll n; cin >> n;

    sieve(n);
    ll ans = 1;
    vector<ll> no;
    for(ll i = 1; i < n; i++) {
        ll p = i+1;

        if(is_prime[p]) {
            ans += p*2;
        } else {
            no.push_back(p);
        }
       // cout << p << " " <<ans << endl;
    }

    

    cout << ans << endl;
}

int main()
{
    solve1();
}
