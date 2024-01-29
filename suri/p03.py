INF = float('inf')  # 巨大数を定義

# 入力
N = 3
S = int(input())
s = [0] * N
n = [0] * N
for i in range(N):
    s[i], n[i] = map(int, input().split())

# 初期化
B = [[[0 for _ in range(n[2] + 1)] for _ in range(n[1] + 1)] for _ in range(n[0] + 1)]
minus = []
rest = []

for i in range(n[0] + 1):
    for j in range(n[1] + 1):
        for k in range(n[2] + 1):
            if i == 0 and j == 0 and k == 0:
                B[0][0][0] = 0
            elif s[0]*i + s[1]*j + s[2]*k <= S:
                minus.append((i, j, k))
                B[i][j][k] = 1
            else:
                rest.append((i, j, k))
                B[i][j][k] = INF

# dpテーブルを更新
for idx in range(len(rest)):
    i, j, k = rest[idx]
    min_val = INF
    for m_i in range(len(minus)):
        ix = i - minus[m_i][0]
        jx = j - minus[m_i][1]
        kx = k - minus[m_i][2]
        if ix < 0 or jx < 0 or kx < 0:
            continue
        if ix == 0 and jx == 0 and kx == 0:
            continue
        min_val = min(min_val, B[ix][jx][kx] + 1)
    B[i][j][k] = min(B[i][j][k], min_val)

print("最適値：", B[1][3][1])
