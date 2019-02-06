"""
Projekt - Clovece
Naprogramoval Stanislav Pekarovič

Simulacia hry prebieha nasledovne:
  - kvôli rychlosti, som ponechal zvolenie cisla n iba v uvode celeho kodu
  - nasledne zacina simulacia hry, ktoru program vykonava sam az do momentu, kedy bude mat dany hrac na vyber
    (napr. hra sa nebude pytat hraca, ktorou figurkou chce pohnut,
    ak bude mat na vyber iba z jednej moznosti, to iste i pri vyberania figurok z domceku)
  - co sa tyka poctu figurok, ten je meneny sirkou hracieho pola, tjst. ak je pole 9x9,
    pocet panacikov pre kazdeho hraca je 3 == poctu domcekov, pre 11x11 je to 4, ...
  - hra si overuje kazdy vstup hraca, aby neprislo ku chybam v pripade, ze hrac zada iny znak ako v dany moment pristupnu cislicu, etc.
  - kazdy hrac ma farebnych panacikov, ktorych cisla su nasledne vypisovane v prislusnej farbe z dovodu prehladnosti

Importoval som 3 moduly: copy z dovodu kopirovania polí
                         random pre funkciu hodu kocky
                         sys pre farebny vypis panacikov
"""
n = 21
import copy
import random
import sys
'''Funkcia tlac zabezpecuje vypis hracieho pola, pricom zaroven overuje, ktore "casti", resp. figurky maju byt vykreslene farebne'''
def tlac():
    for i in range(n + 1):
        for j in range(n + 1 +c):
            if pole[i][j]=='A':
                for r in range(len(suradnice_A)):
                    if [i, j] == [suradnice_A[r][0], suradnice_A[r][1]]:
                        sys.stdout.write(farba[A.index(r)])
                        break
            elif pole[i][j]=='B':
                for r in range(len(suradnice_B)):
                    if [i, j] == [suradnice_B[r][0], suradnice_B[r][1]]:
                        sys.stdout.write(farba[B.index(r)])
                        break
            else:
                sys.stdout.write("\033[1;29m")
            print(pole[i][j], end='')
        print()
    print()
'''
Funkcia genclovece ma na starosti generovanie hracej plochy, pricom je rozdelena na dve casti, jedna prebieha pri jednocifernych cislach a druha pri cislach, ktore presahuju cislo 10.
Generovanie prebieha po riadkoch(co na dlzku kodu asi nebola zrovna najvhodnejsia metoda), ktore su pripadne zoskupene do celkov, oznacene komentarom:
    - zaciatok - prvy riadok hracej plochy
    - kraj(vrchna cast) - cast plochy, po najsirsiu cast kriza
    - core - cast plochy, ktora je najsirsia
    - kraj(spodna cast) - cast plochy, az po posledny riadok
    - posledny riadok
'''
def genclovece(n):
    pole = [[] for j in range(n+1)]
    if n<10:
        pole[0].append(' ')
        for i in range(n):
            pole[0].append(i)
# zaciatok pola
        pole[1].append(0)
        for i in range(koeficient):
            pole[1].append(' ')
        for i in range(3):
            pole[1].append('*')
        for i in range(koeficient):
            pole[1].append(' ')
# kraj - vrchna cast
        for i in range(koeficient - 1):
            pole[i + 2].append(1 + i)
            for j in range(koeficient):
                pole[2 + i].append(' ')
            pole[2 + i].append('*')
            pole[2 + i].append('D')
            pole[2 + i].append('*')
            for j in range(koeficient):
                pole[2 + i].append(' ')
# core
        pole[koeficient + 1].append(koeficient)
        for i in range(koeficient):
            pole[koeficient + 1].append('*')
        pole[koeficient + 1].append('*')
        pole[koeficient + 1].append('D')
        pole[koeficient + 1].append('*')
        for i in range(koeficient):
            pole[koeficient + 1].append('*')

        pole[koeficient + 2].append(koeficient + 1)
        pole[koeficient + 2].append('*')
        for i in range(koeficient):
            pole[koeficient + 2].append('D')
        pole[koeficient + 2].append('X')
        for i in range(koeficient):
            pole[koeficient + 2].append('D')
        pole[koeficient + 2].append('*')

        pole[koeficient + 3].append(koeficient + 2)
        for i in range(koeficient):
            pole[koeficient + 3].append('*')
        pole[koeficient + 3].append('*')
        pole[koeficient + 3].append('D')
        pole[koeficient + 3].append('*')
        for i in range(koeficient):
            pole[koeficient + 3].append('*')
# kraj - spodna cast
        for i in range(koeficient - 1):
            pole[n - koeficient + 1 + i].append(n - koeficient + i)
            for j in range(koeficient):
                pole[n - koeficient + 1 + i].append(' ')
            pole[n - koeficient + 1 + i].append('*')
            pole[n - koeficient + 1 + i].append('D')
            pole[n - koeficient + 1 + i].append('*')
            for j in range(koeficient):
                pole[n - koeficient + 1 + i].append(' ')
#posledny riadok
        pole[n].append(n-1)
        for i in range(koeficient):
            pole[n].append(' ')
        for i in range(3):
            pole[n].append('*')
        for i in range(koeficient):
            pole[n].append(' ')
    else:
        pole[0].append(' ')
        pole[0].append(' ')
        for i in range(n):
            if i<10:
                pole[0].append(i)
            else:
                pole[0].append(i%10)
# zaciatok pola
        pole[1].append(0)
        pole[1].append(' ')
        for i in range(koeficient):
            pole[1].append(' ')
        for i in range(3):
            pole[1].append('*')
        for i in range(koeficient):
            pole[1].append(' ')
# kraj - vrchna cast
        for i in range(koeficient - 1):
            if (1+i)<10:
                pole[i + 2].append(1 + i)
                pole[i + 2].append(' ')
            else:
                pole[i + 2].append((1 + i)//10)
                pole[i + 2].append((1 + i)%10)
            for j in range(koeficient):
                pole[2 + i].append(' ')
            pole[2 + i].append('*')
            pole[2 + i].append('D')
            pole[2 + i].append('*')
            for j in range(koeficient):
                pole[2 + i].append(' ')

# core
        if koeficient<10:
            pole[koeficient + 1].append(koeficient)
            pole[koeficient + 1].append(' ')
        else:
            pole[koeficient + 1].append(koeficient//10)
            pole[koeficient + 1].append(koeficient%10)
        for i in range(koeficient):
            pole[koeficient + 1].append('*')
        pole[koeficient + 1].append('*')
        pole[koeficient + 1].append('D')
        pole[koeficient + 1].append('*')
        for i in range(koeficient):
            pole[koeficient + 1].append('*')

        if (koeficient + 1)<10:
            pole[koeficient + 2].append(koeficient + 1)
            pole[koeficient + 2].append(' ')
        else:
            pole[koeficient + 2].append((koeficient + 1)//10)
            pole[koeficient + 2].append((koeficient + 1)%10)
        pole[koeficient + 2].append('*')
        for i in range(koeficient):
            pole[koeficient + 2].append('D')
        pole[koeficient + 2].append('X')
        for i in range(koeficient):
            pole[koeficient + 2].append('D')
        pole[koeficient + 2].append('*')

        if (koeficient+2)<10:
            pole[koeficient + 3].append(koeficient + 2)
            pole[koeficient + 3].append(' ')
        else:
            pole[koeficient + 3].append((koeficient + 2)//10)
            pole[koeficient + 3].append((koeficient + 2)%10)
        for i in range(koeficient):
            pole[koeficient + 3].append('*')
        pole[koeficient + 3].append('*')
        pole[koeficient + 3].append('D')
        pole[koeficient + 3].append('*')
        for i in range(koeficient):
            pole[koeficient + 3].append('*')

# kraj - spodna cast
        for i in range(koeficient - 1):
            if (n - koeficient + i)<10:
                pole[n - koeficient + 1 + i].append(n - koeficient + i)
                pole[n - koeficient + 1 + i].append(' ')
            else:
                pole[n - koeficient + 1 + i].append((n - koeficient + i)//10)
                pole[n - koeficient + 1 + i].append((n - koeficient + i)%10)
            for j in range(koeficient):
                pole[n - koeficient + 1 + i].append(' ')
            pole[n - koeficient + 1 + i].append('*')
            pole[n - koeficient + 1 + i].append('D')
            pole[n - koeficient + 1 + i].append('*')
            for j in range(koeficient):
                pole[n - koeficient + 1 + i].append(' ')
#posledny riadok
        pole[n].append((n-1)//10)
        pole[n].append((n-1)%10)
        for i in range(koeficient):
            pole[n].append(' ')
        for i in range(3):
            pole[n].append('*')
        for i in range(koeficient):
            pole[n].append(' ')
    return pole
'''
Funkcia hladaj sa stara o vyhladanie vsetkych hviezdiciek v hracej ploche pomocou 4 vnorenych for cyklov, pricom vracia
list listov, ktory obsahuje vsetkych X-ove a Y-ove suradnice kazdej z *
'''
def hladaj(n):
    suradnice = []
    for i in range(koeficient+3):
        for j in range(koeficient+2+c,n+1+c):
            if pole[i][j]=='*':
                suradnice.append([i,j])
    for i in range(koeficient+3,n+1):
        for j in range(n+c,koeficient+1+c,-1):
            if pole[i][j]=='*':
                suradnice.append([i,j])
    for i in range(n,koeficient+1,-1):
        for j in range(koeficient+1+c,-1,-1):
            if pole[i][j]=='*':
                suradnice.append([i,j])
    for i in range(koeficient+1,-1,-1):
        for j in range(koeficient+2+c):
            if pole[i][j]=='*':
                suradnice.append([i,j])
    return suradnice
'''
Nasledujuce 2 funkcie vracaju list, ktoreho kazda polozka je dvojicou suradnic, po ktorych sa budu presuvat panacikovia 
kazdeho hraca. List obsahuje suradnice hviezdiciek + suradnice domcekov
'''
def sur_A():
    suradnice_A = copy.deepcopy(suradnice)
    suradnice_A.append(suradnice_A.pop(0))
    for i in range(koeficient):
        suradnice_A.append([2+i,koeficient+2+c])
    return suradnice_A
def sur_B():
    B = []
    suradnice_B = copy.deepcopy(suradnice)
    for i in range(2*n-1,len(suradnice_B)):
        B.append(suradnice_B[i])
    for i in range(2*n-1):
        B.append(suradnice_B[i])
    for i in range(koeficient):
        B.append([n-1-i, koeficient + 2 + c])
    return B
'''
Funkcia hod vracia integer z intervalu <1;6>
'''
def hod():
    cislo = random.randint(1,6)
    return cislo
'''
Funkcie pohyb zabezpecuju samotny presun figurok danych hracov v hracej ploche (podmieka sa stara o swapnutie * v pripade posunu hraca po cesticke a D v pripade posunu v domceku)
A taktiez sa stara o inkrementovanie hodnoty prislusneho panacika, ktora ponasa udaj o tom, na ktorej pozicii vramci suradnic_A/suradnic_B sa nachadza
'''
def pohyb_A(panacik,posun):
    if A[panacik]<len(suradnice_A)-koeficient:
        pole[suradnice_A[A[panacik]][0]][suradnice_A[A[panacik]][1]],pole[suradnice_A[A[panacik]+posun][0]][suradnice_A[A[panacik]+posun][1]] = '*','A'
    else:
        pole[suradnice_A[A[panacik]][0]][suradnice_A[A[panacik]][1]], pole[suradnice_A[A[panacik] + posun][0]][
            suradnice_A[A[panacik] + posun][1]] = 'D', 'A'
    A[panacik]=A[panacik]+posun
def pohyb_B(panacik,posun):
    if B[panacik]<len(suradnice_B):
        pole[suradnice_B[B[panacik]][0]][suradnice_B[B[panacik]][1]],pole[suradnice_B[B[panacik]+posun][0]][suradnice_B[B[panacik]+posun][1]] = '*','B'
    else:
        pole[suradnice_B[B[panacik]][0]][suradnice_B[B[panacik]][1]], pole[suradnice_B[B[panacik] + posun][0]][
            suradnice_B[B[panacik] + posun][1]] = 'D', 'B'
    B[panacik]=B[panacik]+posun
'''
Funkcia panacikovia vracia list, ktory ma v sebe cisla panacikov z daneho list A/B, ktorymi je mozno pri danom hode kockou pohnut.
Funkcia nevrati cisla panacikov, ktory su na konci domceka, cisla panacikov, ktory by zastupili svojim posunom vlastneho panacika
a ani cisla panacikov, ktory este neboli vytiahnuti.
Funkcia vypis_panacikov ma na starosti farebny vypis panacikov, s ktorymi moze hrac hybat (je pouzita iba za predpokladu, ze hrac ma na vyber
resp. ze moze hybat s dvoma alebo viacerymi panacikmi, inak ani nie je volana)
'''
def panacikovia(X,hod_X):
    lst = []
    for i in range(len(X)):
        if X[i]!=-1 and X[i]+hod_X<len(suradnice_A) and not((X[i]+hod_X) in X):
            lst.append(i)
    return lst
def vypis_panacikov(X,hod_X):
    for e in range(len(panacikovia(X, hod_X))):
        sys.stdout.write(farba[panacikovia(X, hod_X)[e]])
        print(panacikovia(X, hod_X)[e],end=' ')
        sys.stdout.write("\033[1;29m")
    print()
'''
Funkcie zaciatok_A/B su volane v pripade, ze hrac nema na hracej ploche ziadneho panacika a tym padom musi hadzat kockou najviac 3 krat
za predpokladu, ze mu nepadne 6-tka
'''
def zaciatok_A():
    print('A: Hádžeš kockou...')
    for i in range(3):
        hod_A = hod()
        print('A: Padlo cislo:', hod_A)
        if hod_A == 6:
            A[A.index(-1)] = 0
            skok_A(A, 0, A.index(0))
            pole[suradnice_A[0][0]][suradnice_A[0][1]] = 'A'
            tlac()
            tah_A()
            break
def zaciatok_B():
    print('B: Hádžeš kockou...')
    for j in range(3):
        hod_B = hod()
        print('B: Padlo cislo:', hod_B)
        if hod_B == 6:
            B[B.index(-1)] = 0
            skok_B(B, 0, B.index(0))
            pole[suradnice_B[0][0]][suradnice_B[0][1]] = 'B'
            tlac()
            tah_B()
            break
'''
Funkcie tah maju na starosti samotne tahanie panacikov, pricom zabezpecuju, ze hrac sa nemusi zaoberat vyberanim cisla panacika, ak je to jeho jedina volba.
Vo svojom tele maju implementovane i overovanie vstupu, aby hrac omylom/umyselne nevyvolal chybu v programe.
Logika funkcie tah:
    ak hracovi padla 6:
        ak moze vytiahnut panacika z domceka a je to jeho jedina moznost:
            vytiahni panacika a hadz znovu kockou
        inak:
            ak hrac chce vytiahnut panacika
                vytiahni panacika a hadz znovu kockou
            inak ak hrac ma jedineho panacika
                potiahni tymto panacikom
            inak ak ma hrac viacerych panacikov
                daj mu na vyber, ktorym chce potiahnut
            inak 
                ide druhy hrac (lebo nemal inu moznost)
    ak hracovi padlo nieco ine ako 6:
        ak ma iba jedineho panacika, ktorym je mozno hybat
            pohni tymto panacikom a ide druhy hrac
        inak ak ma hrac na vyber z viacerych panacikov
            nechaj ho vybrat s ktorym chce potiahnuut a ide druhy hrac
        inak
            ide druhy hrac (lebo nemal inu moznost) 
'''
def tah_A():
    while True:
        print('A: Hádžeš kockou...')
        hod_A = hod()
        print('A: Padlo cislo:', hod_A)
        if not(0 in A) and hod_A==6 and (len(panacikovia(A,hod_A))!=koeficient) and (-1 in A):
            if len(panacikovia(A,hod_A))==0:
                A[A.index(-1)] = 0
                skok_A(A, 0, A.index(0))
                pole[suradnice_A[0][0]][suradnice_A[0][1]] = 'A'
                tlac()
                continue
            else:
                print('A: Chces si umiestnit noveho panacika?')
                if input().lower() in suhlas:
                    A[A.index(-1)] = 0
                    skok_A(A, 0, A.index(0))
                    pole[suradnice_A[0][0]][suradnice_A[0][1]] = 'A'
                    tlac()
                    continue
                elif len(panacikovia(A,hod_A))==1:
                    skok_A(A, hod_A, panacikovia(A, hod_A)[0])
                    pohyb_A(panacikovia(A, hod_A)[0], hod_A)
                    tlac()
                    continue
                elif len(panacikovia(A,hod_A))>1:
                    while True:
                        print('A: Ktorym panacikom chces pohnut?', end=' ')
                        vypis_panacikov(A, hod_A)
                        cislo = input()
                        if cislo.isdigit():
                            cislo = int(cislo)
                            if cislo in panacikovia(A, hod_A):
                                break
                    skok_A(A, hod_A, cislo)
                    pohyb_A(cislo, hod_A)
                    tlac()
                    continue
                else:
                    break
        elif len(panacikovia(A, hod_A)) == 1:
            skok_A(A, hod_A, panacikovia(A, hod_A)[0])
            pohyb_A(panacikovia(A, hod_A)[0], hod_A)
            tlac()
            break
        elif len(panacikovia(A,hod_A)) > 1:
            while True:
                print('A: Ktorym panacikom chces pohnut?', end=' ')
                vypis_panacikov(A, hod_A)
                cislo = input()
                if cislo.isdigit():
                    cislo = int(cislo)
                    if cislo in panacikovia(A, hod_A):
                        break
            skok_A(A,hod_A,cislo)
            pohyb_A(cislo,hod_A)
            tlac()
            break
        else:
            break
def tah_B():
    while True:
        print('B: Hádžeš kockou...')
        hod_B = hod()
        print('B: Padlo cislo:', hod_B)
        if not(0 in B) and hod_B==6 and (len(panacikovia(B,hod_B))!=koeficient) and (-1 in B):
            if len(panacikovia(B,hod_B))==0:
                B[B.index(-1)] = 0
                skok_B(B, 0, B.index(0))
                pole[suradnice_B[0][0]][suradnice_B[0][1]] = 'B'
                tlac()
                continue
            else:
                print('B: Chces si umiestnit noveho panacika?')
                if input().lower() in suhlas:
                    B[B.index(-1)] = 0
                    skok_B(B, 0, B.index(0))
                    pole[suradnice_B[0][0]][suradnice_B[0][1]] = 'B'
                    tlac()
                    continue
                elif len(panacikovia(B,hod_B))==1:
                    skok_B(B, hod_B, panacikovia(B, hod_B)[0])
                    pohyb_B(panacikovia(B, hod_B)[0], hod_B)
                    tlac()
                    continue
                elif len(panacikovia(B,hod_B))>1:
                    while True:
                        print('B: Ktorym panacikom chces pohnut?', end=' ')
                        vypis_panacikov(B, hod_B)
                        cislo = input()
                        if cislo.isdigit():
                            cislo = int(cislo)
                            if cislo in panacikovia(B, hod_B):
                                break
                    skok_B(B, hod_B, cislo)
                    pohyb_B(cislo, hod_B)
                    tlac()
                    continue
                else:
                    break
        elif len(panacikovia(B, hod_B)) == 1:
            skok_B(B, hod_B, panacikovia(B, hod_B)[0])
            pohyb_B(panacikovia(B, hod_B)[0], hod_B)
            tlac()
            break
        elif len(panacikovia(B,hod_B)) > 1:
            while True:
                print('B: Ktorym panacikom chces pohnut?', end=' ')
                vypis_panacikov(B, hod_B)
                cislo = input()
                if cislo.isdigit():
                    cislo = int(cislo)
                    if cislo in panacikovia(B, hod_B):
                        break
            skok_B(B,hod_B,cislo)
            pohyb_B(cislo,hod_B)
            tlac()
            break
        else:
            break
'''
Funkcia skok overuje, ci panacik jedneho hraca nezastupil panacika druheho hraca a v pripade, ze sa tak stalo, tak ma na starosti
vyhodenie prislusneho panacika(vracia vyhodeneho panacika daneho hraca resp. mu nastavi v list A/B hodnotu -1) 
'''
def skok_A(A,hod_A,cislo):
    x = suradnice_A[A[cislo]+hod_A][0]
    y = suradnice_A[A[cislo]+hod_A][1]
    if pole[x][y]=='B':
        for r in range(len(suradnice_B)):
            if [x, y] == [suradnice_B[r][0], suradnice_B[r][1]]:
                print(r)
                B[B.index(r)]=-1
def skok_B(B,hod_B,cislo):
    x = suradnice_B[B[cislo]+hod_B][0]
    y = suradnice_B[B[cislo]+hod_B][1]
    if pole[x][y]=='A':
        for r in range(len(suradnice_A)):
            if [x, y] == [suradnice_A[r][0], suradnice_A[r][1]]:
                A[A.index(r)]=-1

#je pomocna premenna, ktora pomaha pri vykreslovani hracej plochy, pocte domcekov/panacikov, etc.
koeficient = (n-3)//2
#c je cislo, ktore pomaha pri tvoreni a vykreslovani pola a pri vyhladavani * pri prechode na dvojciferne cisla
if n<10:
    c = 0
else:
    c = 1
#generovanie farieb pre panacikov
farba = []
for i in range(31,31+koeficient):
    farba.append('\033[1;'+str(i)+'m')
#nakopiruje do 'pole' hraciu plochu + vyhlada suradnice *
pole = copy.deepcopy(genclovece(n))
suradnice = copy.deepcopy(hladaj(n))

#vytvori plochu po ktorej sa budu pohybovat panacikovia hraca A a B
suradnice_A = sur_A()
suradnice_B = sur_B()
#Vytvorenie 'figurok', kde -1 znaci, ze figurka este nie je v hracom poli,0, ze panacik bol prave vytiahnuty a ina hodnota znaci, kde sa nachadza
A = [-1 for i in range(koeficient)]
B = [-1 for j in range(koeficient)]
#list retazcov možností, ktoré hráč môže potenciálne použiť ako súhlas pri vykladaní panáčika
suhlas = ['ano','áno','dobre','jasné','jasne','oukey','ok','môžeš']
#Zaciatok
while True:
    if A[:koeficient]==[-1]*len(A):
        zaciatok_A()
    else:
        tah_A()
    if sorted(A[:koeficient])==[i for i in range(len(suradnice_A)-koeficient,len(suradnice_A))]:
        print('Vyhral hrac A')
        exit()
    if B[:koeficient]==[-1]*len(A):
        zaciatok_B()
    else:
        tah_B()
    if sorted(B[:koeficient])==[i for i in range(len(suradnice_B)-koeficient,len(suradnice_B))]:
        print('Vyhral hrac B')
        exit()