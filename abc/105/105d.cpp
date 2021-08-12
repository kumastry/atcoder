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
#include<unordered_map>

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

ll d, g; 
vector<ll> p, c;

void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i = 0; i < n;i ++) {
        sum[i+1] = sum[i]+a[i];
    }

    unordered_map<ll, ll> mp;
    for(int i = 0; i <= n; i++) {
        mp[sum[i]%m]++;
    }

    ll ans = 0;
    for(auto itr = mp.begin(); itr != mp.end(); itr++) {
        ans += (itr->second)*(itr->second-1)/2;
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}
