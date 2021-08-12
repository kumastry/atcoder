a, b = map(str, input().split())
ans = -1000
for i in range(3):
    a[i] = '9'
    for j in range(3):
        if(j == 0):
            b[j] = '1'
        else:
            b[j] = '0'
        sum = int(a)-int(b)
        ans = max(ans, max)
print(ans)