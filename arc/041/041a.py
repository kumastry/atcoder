x, y = map(int, input().split())
k = int(input())
if(k <= y):
    print(x+k)
else:
    print(y + x - (k-y))