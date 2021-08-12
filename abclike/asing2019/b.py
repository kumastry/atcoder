n = int(input())
a, b = map(int, input().split())
p = list(map(int, input().split()))

A , B, C = 0, 0, 0
for i in range(n):
    if(p[i] <= a):
        A += 1
    elif(p[i] <= b):
        B += 1
    else:
        C += 1
print(min(A, B, C))