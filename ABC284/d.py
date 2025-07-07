t = int(input())
for i in range(t):
    n = int(input())

    cube_root_n = int(n**(1/3))+1
    prime_table = [True]*cube_root_n
    prime_table[0] = False
    prime_table[1] = False
    for j in range(len(prime_table)):
        if prime_table[j]:
            k = 2
            while j*k < len(prime_table):
                prime_table[j*k] = False
                k += 1

    for j in range(len(prime_table)):
        if prime_table[j]:
            if n%(j*j) == 0:
                print(j, n//(j*j))
                break
            if n%j == 0:
                print(int((n//j)**(1/2)), j)
                break