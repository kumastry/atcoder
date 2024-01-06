#include <bits/stdc++.h>
using namespace std;
/*
入力
5 12
3 6
4 7
6 8
1 1
5 4
v>>19

出力
最適値：15
最適解：2 3 5
*/

#define INF 1e9 // 巨大数を定義

int main() {

    // 品物数kとナップサック容量yの標準入力
    cout << "k , y >> ";
    int k,y; cin >> k >> y;

    // 体積の配列a, 価値配列c　サイズkで初期化
    vector<int> a(k), c(k);

    // 合計価値
    int sum_val = 0;

    // 配列a,cの標準入力
    for(int i = 0; i < k; i++) {
        cin >> a[i] >> c[i];
        sum_val += c[i];
    }

    cout << "v >> ";
    int v; cin >> v;


    // サイズk+1, sum_val+1のdpテーブル
    vector<vector<int>> dp(k+1, vector<int>(sum_val+1, INF));

    // 最適解復元用のペア配列
    vector<pair<int, int>> before, after;

    // dpテーブルの初期化
    for(int i = 0; i <= sum_val;i ++) {
        dp[0][i] = 0;
        if(i == c[0]) {
            dp[1][i] = a[0];
            // ナップサックに品物が入るとき、dpテーブルの遷移を記録する
            before.push_back(make_pair(0, 0));
            after.push_back(make_pair(1, i));
        } else if(i == 0) {
            dp[1][i] = 0;
        }
    }

    for(int i = 0; i <= k; i++) {
        dp[i][0] = 0;
    }




    for(int i = 1; i < k; i++) {
        for(int j = 0; j <= sum_val; j++) {
            if(j >= c[i]) {
                if(a[i] + dp[i][j - c[i]] < dp[i][j]) {
                    dp[i+1][j] = a[i] + dp[i][j - c[i]];
                    // ナップサックに品物が入るとき、dpテーブルの遷移を記録する
                    before.push_back(make_pair(i, j-c[i]));
                    after.push_back(make_pair(i+1, j));
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    int start_num = k;
    int start_vol = v;
    vector<int> opt_sol;
    //  最適解復元用のペア配列から最適解を算出する
    for(int i = after.size()-1; i >= 0; i--) {
        if(after[i].second == start_vol) {
            start_num = before[i].first;
            start_vol = before[i].second;
            opt_sol.push_back(after[i].first);
        }
    }

    cout << "最適値：" << dp[k][v] << endl;

    cout << "最適解：";
    for(int i = opt_sol.size()-1; i >= 0; i--) {
        cout << opt_sol[i] << " ";
    }
    cout << endl;
}



