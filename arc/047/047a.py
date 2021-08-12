
n, l = map(int, input().split())
s = input()
ans = 0
cnt = 1
for i in range(len(s)):
    if(cnt >= l):
        ans += 1
        cnt = 0

    if(s[i] == '+'):
        cnt += 1
    else:
        cnt -= 1
    
if(cnt >= l):
    ans += 1
    cnt = 0    
print(ans)    