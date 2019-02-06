def F(ret1,ret2):
    ret1 = set(ret1)
    ret2 = set(ret2)
    if ret1==ret2:
        return True
    return False
print(F('mama','amamd'))