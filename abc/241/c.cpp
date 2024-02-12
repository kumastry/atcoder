#include <bits/stdc++.h>

//反省点
//左斜めを考慮していなかった
//考慮漏れ

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
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int connect = 6;
    // 横探索
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - connect + 1; j++) {
            int cnt = 0;
            for(int k = 0; k < connect; k++){

                if(grid[i][j + k] == '.') {
                    cnt ++;
                }
            }
            if(cnt <= 2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }



    // 縦探索
    for(int i = 0; i < n - connect + 1; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int k = 0; k < connect; k++){
                if(grid[i + k][j] == '.') {
                    cnt ++;
                }
            }
            if(cnt <= 2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    // 斜探索
    for(int i = 0; i < n - connect + 1; i++) {
        for(int j = 0; j < n - connect + 1; j++) {
            int cnt = 0;
            for(int k = 0; k < connect; k++){
                if(grid[i + k][j + k] == '.') {
                    cnt ++;
                }
            }
            if(cnt <= 2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }


    for(int i = n - 1; i >= connect-1; i--) {
        for(int j = 0; j < n - connect + 1; j++) {
            int cnt = 0;
            for(int k = 0; k < connect; k++){
                if(grid[i - k][j + k] == '.') {
                    cnt ++;
                }
            }
            if(cnt <= 2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;

}

int main()
{
    solve1();
}
