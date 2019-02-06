def F(zn,ret):
    for i in range(len(ret)):
        if ret[i]==zn:
            return i
    return -1
print(F('x','halookj'))