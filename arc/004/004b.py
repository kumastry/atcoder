n = int(input())
d = n*[]
ans1=0
for i in range(n):
    inp = int(input())
    d[i] = inp
    ans1 += inp
mv = max(d)
sumv = sum(d)-mv

print(ans1)
print(max(0, mv-sumv))