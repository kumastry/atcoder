L, R = map(int, input().split())
l = list(map(int, input().split()))
r = list(map(int, input().split()))
ans = 0
for i in range(L):
    for j in range(R):
        if(l[i] == r[j] and (r[j] != -1 or l[i] != -1)):
            ans = ans + 1
            l[i] = -1
            r[j] = -1
            break
print(ans)