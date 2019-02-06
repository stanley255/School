def F4(s1,s2):
    s3 = set()
    for item in s1:
        s3.add(item)
    for item in s2:
        s3.add(item)
    return s3
print({1, 2, 3, 4, 5})
print({3, 4, 6, 7})
print(F4({1, 2, 3, 4, 5}, {3, 4, 6, 7}))