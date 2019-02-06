text = 'abkll'
text = list(text)
poc = 0
for i in range(len(text)-1):
    if ord(text[i+1])-ord(text[i])==1:
        poc += 1
print(poc)