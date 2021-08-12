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

void solve1()
{
    int q; cin >> q;
    vector<int> l(q), r(q);
    int maxnum = -1;
    rep(i, q) {
        cin >> l[i] >> r[i];
        maxnum = max(maxnum, r[i]);
    }

    sieve(maxnum);
    vector<ll> sum(maxnum+1);
    sum[0] = 0;
    for(int i = 1; i <= maxnum; i++) {
        if(is_prime[i] && is_prime[(i+1)/2]) {
            sum[i] = sum[i-1] + 1;
            //cout <<"##" <<  i << endl;
        } else {
            sum[i] = sum[i-1];
        }
    }


    rep(i, q) {
        cout << sum[r[i]] - sum[l[i]-1] << endl;
        //cout << sum[r[i]] << " " << sum[l[i]] << endl;
    }

}

int main()
{
    solve1();
}
