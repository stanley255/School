def f(lst):
    result = [0]*len(lst)
    print(result)
    for i in range(len(lst)):
        for char in lst[i]:
            if char == 'a':
                result[i] += 1
    mx = 0
    for i in range(1, len(result)):
        if result[mx] < result[i]:
            mx = i
    if result.count(result[mx]) == 1:
        return lst[mx]
    else:
        all_max = []
        for i in range(len(result)):
            if result[i] == max:
                all_max.append(lst[i])
        return all_max


skup_ret = ['cbd', 'acd', 'aaew', 'bvfcaa', 'aa']
print(f(skup_ret))
