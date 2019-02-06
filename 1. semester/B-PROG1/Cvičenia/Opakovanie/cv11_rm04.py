def f(ret):
    s = set(ret)
    slovnik = dict.fromkeys(s)
    for key in slovnik:
        slovnik[key] = 0
    for char in ret:
        slovnik[char] += 1
    result = 0
    for item in slovnik:
        if slovnik[item] > 1:
            result += 1
    return result


print(f('mama'))
