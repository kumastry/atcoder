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

void solve1()  {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    set<int> st;
    map<int, int> ma, mb;

    rep(i, n) {
        cin >> a[i];
        st.insert(a[i]);
        ma[a[i]]++;
    }

    rep(i, m) {
        cin >> b[i];
        st.insert(b[i]);
        mb[b[i]]++;
    }

    int And = 0;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        And += min(ma[*itr], mb[*itr]);
    }

    cout << fixed << setprecision(15) <<  1.0*And / (int)st.size() << endl;
}

int main()
{
    solve1();
}
