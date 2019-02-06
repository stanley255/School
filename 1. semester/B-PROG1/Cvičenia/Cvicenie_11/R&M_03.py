def F(ret1,ret2):
    v1 = set()
    v2 = set()
    for char in ret1:
        if ret1.count(char)==1:
            v1.add(char)
    for char in ret2:
        if ret2.count(char)==1:
            v2.add(char)
    return len(v1&v2)
print(F('aaccvb','aaeedvb'))