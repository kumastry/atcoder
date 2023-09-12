#include <bits/stdc++.h>

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
using Graph = vector<vector<ll>>;

void solve1() {
    string n; cin >> n;
    ll ans = -1;

    vector<int> n_idx(n.length());
    iota(all(n_idx), 0);

    do {

        string nt;
        rep(i, n.length()) {
            nt += n[n_idx[i]];
        }
        for(int i = 1; i < n.length(); i++) {
            string st = nt.substr(0, i);
            string ed = nt.substr(i);

            if(st[0] == '0' || ed[0] == '0') {
                continue;
            }

            //cout << n << " " << st << " " << ed << " " << stoll(st)*stoll(ed) << endl;
            ans = max(ans, stoll(st)*stoll(ed));
        }
    } while (next_permutation(n_idx.begin(),n_idx.end()));

    cout << ans << endl;
}

int main()
{
    solve1();
}
