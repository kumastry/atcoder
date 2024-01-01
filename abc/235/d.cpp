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
#define P pair<ll, ll>
#define fi first
#define se second
typedef long long ll;
using Graph = vector<vector<ll>>;

void solve1() {
    int a, n; cin >> a >> n;
    // nから1/a倍して1になるか

    int cnt = 0;
    string st = to_string(n);

    while(1) {
    int st_size  = (int)st.size();
    string ori_st(st);

    vector<string> sts;
      for(int i = 0; i < st_size; i++) {
          string new_st = st[st.size() - 1] + st.substr(0, st.size() - 1);
          sts.push_back(st);
          st = new_st;
      }

      sort(all(sts));

      bool is_div = false;
      for(int i = 0; i < sts.size(); i++) {
        int sts_num = stoi(sts[i]);
        if(sts_num % a == 0) {
          is_div = true;
          sts_num /= a;
          st = to_string(sts_num);
          cnt ++;

          while(ori_st == st) {
            ori_st = ori_st[ori_st.size() - 1] + ori_st.substr(0, ori_st.size() - 1);
            cnt ++;
            cout << ori_st << endl;
          }
          //cout << st << endl;
          if(sts_num < 2) {
            cout << cnt << endl;
            return;
          }

          break;
        }
      }

      if(!is_div) {
        cout << -1 << endl;
        return;
      }
    }
}

int main()
{
    solve1();
}
