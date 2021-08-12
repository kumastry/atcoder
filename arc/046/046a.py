n = int(input())
a = []
for i in range(1, 555555+1):
    if(i < 10):
        a.append(i)
    elif(i < 100):
        if(i%11 == 0):
            a.append(i)
    elif(i < 1000):
        if(i%111 == 0):
            a.append(i)
    elif(i < 10000):
        if(i%1111 == 0):
            a.append(i)
    elif(i < 100000):
        if(i%11111 == 0):
            a.append(i)
    else:
        if(i%111111 == 0):
            a.append(i)
print(a[n-1])