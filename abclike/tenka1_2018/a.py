s = input()
if(len(s) == 2):
    print(s)
else:
    for i in range(3):
        print(s[2-i], end='')
    print('')
