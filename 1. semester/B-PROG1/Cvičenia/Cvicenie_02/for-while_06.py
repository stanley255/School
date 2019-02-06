a = 100
sum = 0
'''
for i in range(a+1):
    sum += 1/2**i
    print(sum)
print(sum)
'''

predosle = 100
for i in range(a+1):
    sum += 1/2**i
    if predosle == sum:
        print('Opakovanie sa zacina v',i,'. iteracii')
        break
    predosle = sum
    print(sum)