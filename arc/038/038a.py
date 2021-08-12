n = int(input())
a = list(map(int, input().split()))
aa = sorted(a, reverse=True)
ans = 0
i = 0
while(i < n):
    ans += aa[i]
    i = i + 2
print(ans)