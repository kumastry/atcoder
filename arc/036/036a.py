n, k = map(int, input().split())
t = []
for i in range(n):
    inp = int(input())
    t.append(inp)
sl = t[0] + t[1] + t[2]
ans = -1
for i in range(n-3):
    if(sl < k):
        ans = i + 3
        break
    sl += t[i+3]-t[i]
print(ans)