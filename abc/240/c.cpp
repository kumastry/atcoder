#include <bits/stdc++.h>

// 反省点
// dpの問題ではインデックスがあいまいになる
//

using namespace std;

void solve1() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < x+1; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i <= x; i++) {
        if(i == a[0]) {
            dp[1][i] = 1;
        }

        if(i == b[0]) {
            dp[1][i] = 1;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            if(j > a[i-1] && dp[i-1][j - a[i-1]]) {
                dp[i][j] = 1;
            }

            if(j > b[i-1] && dp[i-1][j - b[i-1]]) {
                dp[i][j] = 1;
            }
        }
    }

    if(dp[n][x]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

int main()
{
    solve1();
}
