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
    string s; cin >> s;
    int n = (int)s.size();

    map<char, int> m;
    set<char> st;
    rep(i, n) {
        m[s[i]]++;
        st.insert(s[i]);
    }

    vector<vector<int>> vec((int)st.size(), vector<int>(n+1));
    int idx = 0; 
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        vec[idx][0] = 0;
        rep(i, n) {   
            if(s[i] == *itr) {
                vec[idx][i+1] = vec[idx][i] + 1;
            } else {
                vec[idx][i+1] = vec[idx][i];
            }
        }
        idx ++;
    }

    rep(i, idx) {
        rep(j, n+1) {
            int tail = vec[idx][j];
            
        }
    }
}

int main()
{
    solve1();
}
