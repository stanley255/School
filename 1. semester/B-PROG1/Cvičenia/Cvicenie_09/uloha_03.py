text = 'mamade'
mnozina = set()
for i in range(len(text)-1):
    mnozina.add((text[i],text[i+1]))
print(mnozina)
print(len(mnozina))