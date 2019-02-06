def f(rt1, rt2):
    s1 = set(rt1)
    s2 = set(rt2)
    s3 = set()
    for item in s1:
        if item in s2:
            s3.add(item)
    return len(s3)


ret1 = 'ahoj'
ret2 = 'ako'
print(f(ret1, ret2))
