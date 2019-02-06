def oddelenie(ziak):
    ziak = ziak.split(' ')
    return ziak[0], ziak[1]


f = open('data.txt', 'r')
text = f.read()
text = text.split('\n')
for item in text:
    print(oddelenie(item)[0], ':', '*'*int(oddelenie(item)[1]))
