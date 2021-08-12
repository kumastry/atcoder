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
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second



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

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

void solve1() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    BinaryIndexedTree<ll> bit(n+1);
    bit.add(0, 0);
    rep(i, n) {
        cin >> a[i];
        bit.add(i+1, a[i]);
    }

     cout << "$$$ " << (bit.sum(1)^bit.sum(0)) << endl; 
    cout << "$$$ " << (bit.sum(2)^bit.sum(1)) << endl; 
    cout << "$$$ " << (bit.sum(3)^bit.sum(2)) << endl; 

    vector<ll> ans;
    rep(i, q) {
        ll t, x, y; cin >> t >> x >> y;
        if(t == 2) {
            ans.push_back(bit.sum(y)-bit.sum(x-1));
            cout << bit.sum(x-1) << " " << bit.sum(y) << endl;
        } else {
           
            bit.add(x,y);

             cout << "$$$ " << (bit.sum(1)-bit.sum(0)) << endl; 
    cout << "$$$ " << (bit.sum(2)-bit.sum(1)) << endl; 
    cout << "$$$ " << (bit.sum(3)-bit.sum(2)) << endl; 

        }
    }

    cout << "$$$ " << (bit.sum(1)^bit.sum(0)) << endl; 
    cout << "$$$ " << (bit.sum(2)^bit.sum(1)) << endl; 
    cout << "$$$ " << (bit.sum(3)^bit.sum(2)) << endl; 
    rep(i, (int)ans.size()) {
        cout << ans[i] << endl;
    }
}

int main()
{
    solve1();
}





