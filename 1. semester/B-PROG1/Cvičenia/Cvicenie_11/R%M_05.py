def F(ret):
    s1 = set()
    for i in range(len(ret)-1):
        s1.add((ret[i],ret[i+1]))
    return len(s1)
print(F('akuku'))