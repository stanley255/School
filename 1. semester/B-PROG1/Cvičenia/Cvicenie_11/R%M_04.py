def F(ret):
    s1 = set()
    for char in ret:
        s1.add(char)
    slovnik = dict.fromkeys(s1)
    for key in slovnik:
        slovnik[key] = 0
    for char in ret:
        slovnik[char]+=1
    result = []
    for key in slovnik:
        if slovnik[key]>1:
            result.append(key)
    return len(result)


print(F('mamac'))
