def F(lst):
    for ret in lst:
        if 'a' in ret:
            return ret
    return 0
print(F(['bsdgf', 'rea', 'cbfdaa']))