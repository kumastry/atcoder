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
    int n; cin >> n;
    vector<ll> a(n);

    rep(i, n) {
        cin >> a[i];
    }


    list<ll> li1;
    list<ll> li2;
    sort(all(a));
    int mi = 0;
    int ma = n-1;
    for(int i = 0; i < ceil(n / 2.0); i++) {
        if(i == 0) {
            li1.push_back(a[mi++]);
        } else if(i%2 == 1) {
            li1.push_front(a[ma--]);
            li1.push_back(a[ma--]);
        } else {
            li1.push_front(a[mi++]);
            li1.push_back(a[mi++]);
        }
    }

    int mid1 = mi++;

    mi = 0;
    ma = n-1;
    for(int i = 0; i < ceil(n / 2.0); i++) {
        if(i == 0) {
            li2.push_back(a[ma--]);
        } else if(i%2 == 1) {
            li2.push_front(a[mi++]);
            li2.push_back(a[mi++]);
        } else {
            li2.push_front(a[ma--]);
            li2.push_back(a[ma--]);
        }
    }
    int mid2 = mi++;
    //cout << 23 << endl;
    if(n%2) {
        ll ans1 = 0, ans2 = 0;
        for(auto itr = li1.begin(); itr != prev(li1.end()); itr++) {
            ans1 += abs(*itr - *((next(itr))));
        }

        for(auto itr = li2.begin(); itr != prev(li2.end()); itr++) {
            ans2 += abs(*itr - *((next(itr))));
        }

        cout << max(ans1, ans2) << endl;
    } else {
        

        ll ans1 = 0, ans2 = 0;
        for(auto itr = li1.begin(); itr != prev(li1.end()); itr++) {
            ans1 += abs(*itr - *(next(itr)));
        }

        ans1 += max( abs(*li1.begin() - a[mid1]), abs(*li1.rbegin()-a[mid1]) );

        for(auto itr = li2.begin(); itr != prev(li2.end()); itr++) {
            ans2 += abs(*itr - *(next(itr)));
        }

        ans2 += max( abs(*li2.begin() - a[mid2]), abs(*li2.rbegin()-a[mid2]) );

        cout << max(ans1, ans2) << endl;
    }
}

int main()
{
    solve1();
}
