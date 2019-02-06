def F(ret1,ret2):
    for char in ret1:
        for znak in ret2:
            if char==znak:
                return 1
    return 0

print(F('mama', 'xcvda'))