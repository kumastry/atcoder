a, b, k = map(int, input().split())

for i in range(k):
    if(i%2):
        tmp = a
        a = b
        b = tmp
        
    if(a%2):
         a -= 1
    b += a//2
    a //= 2

    if(i%2):
        tmp = a
        a = b
        b = tmp
print(a, b, sep=' ')