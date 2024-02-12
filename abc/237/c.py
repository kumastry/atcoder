# 反省点
# sの先頭aの考慮が足りなかった

# 改善学び

def main():
    s = input()

    if(s == s[::-1]):
        print('Yes')
        return

    a_cnt = 0
    for i in s[::-1]:
        if(i == 'a'):
            a_cnt += 1
        else:
            break

    for i in s:
        if(i == 'a'):
            a_cnt -= 1
        else:
            break

    a_strs = ''
    for i in range(a_cnt):
        a_strs += 'a'

    s = a_strs + s
    if(s == s[::-1]):
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    main()
