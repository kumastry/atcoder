

def f(x, n):
    n += 1
    if(x*(x+1)//2 <= n):
        return True
    else:
        return False


n = int(input())
r = n + 2
l = -1

while(r-l > 1):
    mid = (r+l)//2
    if(f(mid, n)):
        l = mid
    else:
        r = mid
print(n+1-l)