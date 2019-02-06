text = 'mama'
s1 = set()
for i in range(len(text)-1):
    s1.add((text[i],text[i+1]))
print(s1)
print(len(s1))