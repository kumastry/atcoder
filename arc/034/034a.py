n = int(input())
a = []
b = []
c = []
d = []
e = []
ans = -1
for i in range(n):
    score = 0
    a[i], b[i], c[i], d[i], e[i] = map(int, input().split())
    score += a[i] + b[i] + c[i] + d[i] + e[i]/900
    ans = max(ans, score)
print(ans)