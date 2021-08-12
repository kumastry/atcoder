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
using Graph = vector<vector<int>>;

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

int n; 
int ans = 0;

void func(vector<int> &a, int l, int r) {
    vector<P> p;
    if(l == -1 && r == n) {
        l = 0;
        r = n-1;
        bool f = true;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                if(l == i) {
                    l ++;
                    continue;
                }

                f = false;          
                r = i-1;
                //cout << l << " " << r << endl;
                if(l <= r)
                    p.push_back(P(l, r));
                //func(a, l, r);
                l = i+1;
                r = n-1;
            }
        }
        //cout << l << " " << r << endl;
        if(l <= r)
        p.push_back(P(l, r));
    }

    
    for(int j = 0; j < (int)p.size();  j++) {
        //cout << p[j].fi << " " << p[j].se << endl;
    for(int i = p[j].fi; i <= p[j].se; i++) {
        a[i]--;
    }
    ans ++;
    }
}

bool all_zero(vector<int> a) {
    rep(i, a.size()) {
        if(a[i] != 0) {
            return false;
        }
    }

    return true;
}
void solve1() {
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    while(!all_zero(a)) {
        func(a, -1, n);
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}
