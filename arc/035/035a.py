s = input()
n = len(s)
f = True
for i in range(n):
    if(s[i] != s[n - i - 1]):
        if(s[i] != '*' and s[n-1-i] != '*'):
            f = False
if(f):
    print("YES")
else:
    print("NO")
            