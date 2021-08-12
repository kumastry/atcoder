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
    int n, q; cin >> n >> q;
    vector<int> l(q), r(q);

    rep(i, q) {
        cin >> l[i] >> r[i];
    }

    vector<int> imos(n+1, 0);

    for(int i = 0; i < q; i++) {
        imos[l[i]]++;
        imos[r[i]+1]--;
        //cout << l[i] << " " << r[i] << endl;
    }

   /* for(int i = 1; i <= n; i++) {
        cout << imos[i] << " ";
    }

    cout << endl;*/

    for(int i = 0; i < n+1; i++) {
        if(i > 0) {
            imos[i] += imos[i-1];
        }
    }

    /*for(int i = 1; i <= n; i++) {
        cout << imos[i] << " ";
    }

    cout << endl;
*/

    for(int i = 1; i <= n; i++) {
        if(imos[i]%2) {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    cout << endl;
}

int main()
{
    solve1();
}
