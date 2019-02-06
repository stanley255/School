text = 'mama je domaaa'
dict = {}
text = text.split(' ')
priemer = 0
for i in range(len(text)):
    dict[i]=len(text[i])
    priemer += len(text[i])
priemer = priemer//len(text)
max = 0
for key in dict:
    if dict[max]<dict[key]:
        max = key
print('Priemerna dlzka slova je:',priemer)
print('Najdlhsie slovo ma',dict[max],'znak(y/ov)')