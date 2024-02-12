
# 良かった点
# エッジケースをあらかじめテストした

# 改善点
# コードが汚い
# 解説には数学的な解放があるから確認する

n = int(input())
MOD = 998244353
n_digit = len(str(n))

ans = 0
end = ''
end_str = ''

for i in range(n_digit):
    if i == n_digit - 1:
        if(end):
            n -= int(end)
        ans += n * (n + 1) // 2
        ans %= MOD
        break

    end += '9'
    if(i == 0):
        end_str += '9'
    else:
        end_str += '0'
    end_number = int(end_str)
    ans += end_number * (end_number + 1) // 2
    ans %= MOD
print(ans)
