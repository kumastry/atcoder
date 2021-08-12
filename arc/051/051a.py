x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())

x = x1 - r
xx = x1 + r
y = y1 - r
yy = y1 + r

if(min(y2,y3) > r):
    if(x2 <= x and x3 >= xx and y2 <= y and y3 >= yy):
        print("NO")
        print("YES")
    else:
        print("YES")
        print("YES")
else:
    if(x2 >= x and x3 <= xx and y2 >= y and y3 <= yy):
        print("YES")
        print("NO")
    else:
        print("YES")
        print("YES")
