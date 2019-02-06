koeficient = [1,0,0,2]
x = int(input('Zadaj x: '))
sum = 0
for i in range(len(koeficient)):
    sum += koeficient[i]*x**i
print(sum)