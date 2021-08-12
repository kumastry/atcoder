s = input()

ans = -1
for i in range(len(s)-1):
    if(s[i].isdigit()):
        if(s[i+1].isdigit()):
            ans = int(s[i]+s[i+1])
        else:
            ans = int(s[i])
        break
if(ans == -1):
    if(s[len(s)-1].isdigit()):
        ans = int(s[len(s)-1])

print(ans)

