def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x%y)

def lcm(x, y):
    return x*y//gcd(x, y)

a, b, c, d = map(int, input().split())

c_num = b//c - (a-1)//c
d_num = b//d - (a-1)//d
cd_num = b//lcm(c, d) - (a-1)//lcm(c, d)
total = b - a + 1
ans = total - c_num - d_num + cd_num

#print(f"total:{total}, c_num:{c_num}, d_num:{d_num}, cd_num{cd_num}")
print(ans)