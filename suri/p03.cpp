#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 // 巨大数を定義

int main() {
    // 入力
    int N = 3;
    int S; cin >> S;
    vector<int> s(N), n(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i] >> n[i];
    }

    // 初期化
    int B[n[0]][n[1]][n[2]];
    vector<tuple<int, int, int>> minus;
    vector<tuple<int, int, int>> rest;
    for(int i = 0; i <= n[0]; i++) {
        for(int j = 0; j <= n[1]; j++) {
            for(int k = 0; k <= n[2]; k++) {
                if(i == 0 && j == 0 && k == 0) {
                    B[0][0][0] = 0;
                } else if(s[0]*i + s[1]*j + s[2]*k <= S ) {
                    minus.push_back(make_tuple(i, j, k));
                    B[i][j][k] = 1;
                } else {
                    rest.push_back(make_tuple(i, j, k));
                    B[i][j][k] = INF;
                }
            }
        }
    }

    // dpテーブルを更新
    for(int idx = 0; idx < (int)rest.size(); idx++) {
        int i = get<0>(rest[idx]);
        int j = get<1>(rest[idx]);
        int k = get<2>(rest[idx]);
        int min_val = INF;
        for(int m_i = 0 ; m_i < (int)minus.size(); m_i ++) {
            int ix = i - get<0>(minus[m_i]);
            int jx = j - get<1>(minus[m_i]);
            int kx = k - get<2>(minus[m_i]);
            if(ix < 0 || jx < 0 || kx < 0) continue;
            if(ix == 0 && jx == 0 && kx == 0) continue;
            min_val = min(min_val, B[ix][jx][kx] + 1);
        }
        B[i][j][k] = min(B[i][j][k], min_val);
    }

    // for(int i = 0; i  <= n[0]; i++) {
    //     for(int j = 0; j <= n[1]; j++) {
    //         for(int k = 0; k <= n[2]; k++) {
    //             int min_val = INF;
    //             for(int m_i = 0 ; m_i < minus.size(); m_i ++) {
    //                 int ix = i - get<0>(minus[m_i]);
    //                 int jx = j - get<1>(minus[m_i]);
    //                 int kx = k - get<2>(minus[m_i]);
    //                 if(ix < 0 || jx < 0 || kx < 0) continue;
    //                 min_val = min(min_val, B[ix][jx][kx] + 1);
    //             }
    //             B[i][j][k] = min(B[i][j][k], min_val);
    //         }
    //     }
    // }

    for(int i = 0; i <= n[0]; i++) {
        for(int j = 0; j <= n[1]; j++) {
            for(int k = 0; k <= n[2]; k++) {
                cout << i << " " << j << " " << k  << " : " << B[i][j][k] << endl;
            }
        }
    }

    cout << "最適値：" << B[1][3][1] << endl;
}



