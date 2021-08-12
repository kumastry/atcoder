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

int dx[4] = {-1, 0, 1,0};
int dy[4] = {0, 1, 0, -1};
vector<vector<bool>> seen(10, vector<bool>(10));

void dfs(vector<vector<char>> &gc, P s) {
    gc[s.first][s.second] = 'x';

    for(int i = 0;i < 4; i++) {
        int x = s.second + dx[i];
        int y = s.first + dy[i];
        
        if(x >= 0 && x < 10 && y >= 0 && y < 10 && gc[y][x] != 'x') {
            dfs(gc, (P)make_pair(y, x));
        }

    }
}

bool is_allcrear(vector<vector<char>> &gc) {
    rep(i, 10) {
        rep(j, 10) {
            if(gc[i][j] == 'o') {
                return false;
            }
        }
    }

    return true;
}

void show(vector<vector<char>> &gc) {
    rep(i, 10) {
        rep(j, 10) {
            cout << gc[i][j];
        }
        cout << endl;
    } 
}

void solve1() {
    vector<vector<char>> g(10, vector<char>(10));
    rep(i, 10) {
        rep(j, 10) {
            cin >> g[i][j];
        }
    }

    string ans = "NO";
    rep(i, 10) {
        rep(j, 10) {
            vector<vector<char>> gc(g);

            if(gc[i][j] == 'x') {
                gc[i][j] = 'o';
                dfs(gc, (P)make_pair(i, j));
            }

            

            if(is_allcrear(gc)) {
                ans = "YES";
                goto la;
            }
        }
    }

    la:

    cout << ans << endl;
}

int main()
{
    solve1();
}
