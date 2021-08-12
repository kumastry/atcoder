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



void solve1() {
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
    }

    int ans = 1;

    if(m == 0) {
        cout << 1 << endl;
    } else {
        for(int i = 0; i < (1 << n); i++) {
            set<int> st;
            vector<int> cnt(n, 0);
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    st.insert(j+1);
                }
            }



            for(int j = 0; j < m; j++) {
                if(st.find(a[j]) != st.end() && st.find(b[j]) != st.end()) {
                    cnt[a[j]-1]++;
                    cnt[b[j]-1]++;
                }
            }

            int size = (int)st.size();
            bool f = true;
            for(auto itr = st.begin(); itr != st.end(); itr++) {
                if(cnt[(*itr)-1] != size - 1) {
                    f = false;
                }
            }

            if(f) {
                ans = max(ans, size);
            }
        }

        cout << ans << endl;
    }

    

}

int main()
{
    solve1();
}
