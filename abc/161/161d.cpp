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


vector<ll> vec;

void rec(ll n, int pre) {
    if(n > 3234566669) {
        return;
    }

    vec.push_back(n);
    for(int i = -1; i <= 1; i++) {
        string str = to_string(n);
        int k = pre + i;
        if(k >= 0 && k <= 9) {
            char kc = k +'0';
            str += kc;
            ll num = atoll(str.c_str());
            //cout << num << endl;
            rec(num, k);
        }
    }
}

void solve1() {
    int n; cin >> n;

    
    for(int i = 1; i <= 9; i++) {
        rec(i, i);
    }

    sort(all(vec));
    //rep(i, (int)vec.size()) {
      //  cout << vec[i] << endl;
    //}

    cout << vec[n-1] << endl;
}

int main()
{
    solve1();
}
