import datetime

def solve():
    n = input()
    li = n.split('/')
    d = datetime.date(int(li[0]), int(li[1]), int(li[2]))
    for i in range(1000000):
        if(d.year%(d.month*d.day)==0):
            print(d.strftime("%Y/%m/%d"))
            return
        d += datetime.timedelta(days=1)
solve()