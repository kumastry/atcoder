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

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

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

ll dp[1000][1000];

ll combi(ll n, ll r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n;
       if(dp[n][r]) return dp[n][r];
       return dp[n][r] = combi(n-1,r) + combi(n-1,r-1);
}


vector<ll> divs(ll n) {
    vector<ll> ret;
    for(ll i = 1; i *i<= n; i++) {
        if(n%i == 0) {
            ret.push_back(i);
            if(i != n/i) {
                ret.push_back(n/i);
            }
        }
    }

    sort(all(ret));
    return ret;
}

int F(ll a, ll b) {
    if(to_string(a).size() > to_string(b).size()) {
        return (ll)to_string(a).size();
    } else {
        return (ll)to_string(b).size();
    }
}

void solve1()
{
    ll n; cin >> n;
    vector<ll> div = divs(n);

    int ans = 1000;
    int len = (int)div.size();
    for(int i = 0; i <= len / 2; i++) {
        ans = min(F(div[i], div[len -1 -i]), ans);
        //cout << div[i] << " " << div[len-1-i] << endl;
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}
