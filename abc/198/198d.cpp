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
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e18
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, j, n) for (ll i = j; i < n; i++)
#define repi(i, n) for (ll i = 0; i <= n; i++)
#define repie(i, j, n) for (ll i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second
using Graph = vector<vector<ll>>;


void dfs(int idx, char n,vector<char> ch, vector<char> num) {
    if(idx == num.size()) return;

    for(int i = 0;i < 10; i++) {
        if(num[i] == n) continue;
        d
    }
}

void solve1() {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    set<char> s;
    rep(i, s1.size()) {
        s.insert(s1[i]);
    }

    rep(i, s2.size()) {
        s.insert(s2[i]);
    }

    rep(i, s3.size()) {
        s.insert(s3[i]);
    }

    vector<char> ch;
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        ch.push_back(*itr);
    }

    int n = (int)ch.size();
    vector<char> num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    dfs(0, ch,num);


}

int main()
{
    solve1();
}
