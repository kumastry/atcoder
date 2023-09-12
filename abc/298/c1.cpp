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
    int n; cin >> n;
    int q; cin >> q;

    map<int, vector<int>> box;
    map<int, set<int>> num;
    vector<vector<int> > ans;
    rep(i, q) {
        vector<int> line_ans;

        int q1; cin >> q1;

        if(q1 == 1) {
            int i, j; cin >> i >> j;
            box[j].push_back(i);
            num[i].insert(j);
            continue;
        } else if(q1 == 2) {
            int i; cin >> i;

            sort(box[i].begin(), box[i].end());
            for(int idx = 0; idx < box[i].size(); idx++) {
                line_ans.push_back(box[i][idx]);
            }
        } else {
            int i; cin >> i;
            for(auto itr = num[i].begin(); itr != num[i].end(); itr ++) {
                line_ans.push_back(*itr);
            }
        }

        ans.push_back(line_ans);
    }

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    solve1();
}
