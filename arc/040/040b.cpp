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
#include <deque>

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
    int n, r; cin >> n >> r;
    string s; cin >> s;

    int rs = -1;
    for(int i = (int)s.size()-1; i >= 0; i--) {
        if(s[i] == '.') {
            rs = i+1;
            break;
        }
    }
    int walk = max(0, rs-r);

    vector<int> range;
    int cnt = 0;
    int paint = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            for(int j = 0; j < r; j++) {
                int range = min(i+j, n-1);
                s[range] = 'o';
            }

            paint ++;
        }
    }

    
   
    cout << walk + paint << endl;
}

int main()
{
    solve1();
}
