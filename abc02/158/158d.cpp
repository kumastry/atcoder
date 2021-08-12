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
#include <unordered_map>

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
    string s; cin >> s;
    list<char> ans;
    rep(i, s.size()) {
        ans.push_back(s[i]);
    }
    int q; cin >> q;

    bool f = true;
    rep(i, q) {
        int t; cin >> t;
        if(t == 1) {
            f = f?false:true;
        } else {
            int r; char c; cin >> r >> c;
            if(f == false) {
                r = (r==1)?2:1;
            }
            if(r == 1) {
                ans.push_front(c);
            } else {
                ans.push_back(c);
            }
        }
        
    }

    if(f) {
    for(auto itr = ans.begin(); itr != ans.end(); itr++) {
        cout << *itr;
    }
    } else {
    for(auto itr = ans.rbegin(); itr != ans.rend(); itr++) {
        cout << *itr;
    }    
    }

    cout << endl;
}


int main()
{
    solve1();
}
