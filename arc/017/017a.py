n = int(input())

i = 2
while(i*i <= n):
    if(n%i==0):
        print("YES")
        exit()
print("NO")