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

出力
最適値：17
最適解：1 2 5
*/


int main() {

    // 品物数kとナップサック容量yの標準入力
    cout << "k , y >> ";
    int k,y; cin >> k >> y;

    // 体積の配列a, 価値配列c　サイズkで初期化
    vector<int> a(k), c(k);

    // 配列a,cの標準入力
    for(int i = 0; i < k; i++) {
        cin >> a[i] >> c[i];
    }

    // サイズk+1, y+1のdpテーブル
    vector<vector<int>> dp(k+1, vector<int>(y+1));

    // dpテーブルの初期化
    for(int i=0; i <= y;i ++) {
        dp[0][i] = 0;
    }

    for(int i = 0; i <= k; i++) {
        dp[i][0] = 0;
    }

    // 最適解復元用のペア配列
    vector<pair<int, int>> before, after;

    // テーブルdpの更新
    for(int i = 0; i < k; i++) {
        for(int j = 0; j <= y; j++) {
            if(j >= a[i]) {
                if(dp[i][j-a[i]] + c[i] > dp[i][j]) {
                    dp[i+1][j] = dp[i][j-a[i]] + c[i];

                    // ナップサックに品物が入るとき、dpテーブルの遷移を記録する
                    before.push_back(make_pair(i, j-a[i]));
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
    int start_vol = y;
    vector<int> opt_sol;
    //  最適解復元用のペア配列から最適解を算出する
    for(int i = after.size()-1; i >= 0; i--) {
        if(after[i].second == start_vol) {
            start_num = before[i].first;
            start_vol = before[i].second;
            opt_sol.push_back(after[i].first);
        }
    }

    cout << "最適値：" << dp[k][y] << endl;

    cout << "最適解：";
    for(int i = opt_sol.size()-1; i >= 0; i--) {
        cout << opt_sol[i] << " ";
    }
    cout << endl;
}



