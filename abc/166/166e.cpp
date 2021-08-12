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

void solve1() {
    ll n; cin >> n;
    vector<ll> a(n);

    rep(i, n) {
        cin >> a[i];
    }

    multiset<ll> s;
    vector<ll> st(n-2);
    for(ll i = 2; i < n; i++) {
        s.insert(i-a[i]);
        st[i-2] = i-a[i];
    }

    //rep(i, n-2) {
      //  cout << st[i] << endl;
    //}
    sort(all(st));
    ll ans = 0;
    for(ll i = 0; i < n-2; i++) {
        //cerr << "### " <<i << endl;
       // if(s.find(a[i]+i) != s.end()) {
       //   ans += s.count(a[i]+i);
       // } 

        ans += upper_bound(st.begin()+i, st.end(), a[i]+i) - lower_bound(st.begin()+i, st.end(), a[i]+i);

        //cerr << a[i] +i;
        //s.erase(s.find(st[i]-i));
        //cerr << " " << st[i]-i << endl;
       // cerr << i+1 << " " <<ans << endl;
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}
