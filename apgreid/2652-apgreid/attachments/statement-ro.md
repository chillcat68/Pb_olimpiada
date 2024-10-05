Yamada, cel mai bun jucător al jocului Forest of Savior, se pregătește pentru a participa într-o bătălie împreună cu coechipierii săi. Pentru a câștiga această luptă, Yamada trebuie să se folosească de diverse obiecte magice pe care le-a obținut de-a lungul timpului. 

Obiectele cu puteri magice ale lui Yamada sunt de trei tipuri:
   * **Cărți de vrăji.** Dacă personajul are puterea $P$ și citește o carte de putere magică $x$, atunci puterea personajului va deveni $P^x$.
   * **Poțiuni.** Dacă personajul are puterea $P$ și bea o poțiune de putere magică $x$, atunci noua lui putere va fi $P + x$. 
   * **Nestemate.** Dacă personajul are puterea $P$ și sparge o piatră prețioasă de putere magică $x$, atunci noua putere obținută va fi $P \cdot x$.

Personajul lui are o putere inițială $P_0$, iar fiecare dintre aceste obiecte, după ce este folosit, îi va schimba puterea acestuia în mod ireversibil. De exemplu, dacă personajul lui Yamada începe cu puterea inițială $P_0 = 3$, după folosirea unei poțiuni de putere magică $2$ puterea personajului crește și devine egală cu $5$. Utilizarea ulterioară a unei cărți de vrăji de putere magică $3$ îi va crește personajului puterea la $125$.

Yamada își poate folosi obiectele în orice ordine, dar fiind copleșit de numărul de moduri în care își poate folosi obiectele, vă cere ajutorul vostru!


# Cerință

Ajutați-l pe Yamada să determine:
   1. Dintre toate obiectele avute la dispoziție, care este cea mai puternică carte de vrăji, care este cea mai puternică poțiune și care este cea mai puternică nestemată.
   2. În ce ordine ar trebui să se folosească de obiectele magice astfel încât, la final, puterea personajului său să fie maximă. 
   3. Care este puterea maximă pe care o poate atinge personajul său. Fiindcă acest număr poate fi foarte mare, Yamada vrea doar să afle care ar fi restul împărțirii acestui număr la $1 \ 000 \ 000 \ 007$. 

# Date de intrare

Pe prima linie din fișierul de intrare `apgreid.in` se va află valoarea $T$, care reprezintă cerința care trebuie rezolvată și poate avea una din valorile $1$, $2$ sau $3$. 

Pe următoarea linie se află numerele naturale $M$ și $P_0$, reprezentând, în ordine, numărul total de obiecte pe care le are Yamada, respectiv puterea inițială a personajului său.

Pe fiecare dintre următoarele $M$ linii, se află descrierea câte unui obiect magic. Linia $i$ ($1 \leq i \leq M$) conține un caracter de tip literă $l_i$, care reprezintă tipul obiectului (`c` — carte de vrăji, `p` — poțiune și `n` — nestemată) și un număr $x_i$, reprezentând puterea magică în funcție de tipul obiectului. Valorile $l_i$ și $x_i$ sunt despărțite printr-un spațiu.

# Date de ieșire

Pentru cerința $T = 1$, pe prima linie a fișierului de ieșire `apgreid.out` se vor afișa trei numere naturale reprezentând, în ordine, cea mai mare puterea magică a unei cărți de vrăji, a unei poțiuni respectiv a unei nestemate.

Pentru cerința $T = 2$, în fișierul de ieșire se vor afișa pe $M$ linii diferite perechile de caractere și numere, reprezentând tipul și puterea obiectelor în ordinea în care Yamada ar trebui să le folosească pentru a maximiza puterea personajului său. Fiecare linie va conține un caracter $l$ (care va fi unul dintre `c`, `p` sau `n`) separat printr-un spațiu de un număr $x$ care reprezintă puterea magică a obiectului respectiv. Dacă există mai multe moduri de a obține puterea maximă, oricare dintre ele va fi considerat corect.

Pentru cerința $T = 3$, pe prima linie a fișierului de ieșire se va afișa un număr întreg, reprezentând restul împărțirii puterii maxime pe care o poate atinge personajul lui Yamada la $1 \ 000 \ 000 \ 007$.

# Restricții și precizări

* $1 \leq T \leq 3$
* $1 \leq M \leq 100 \ 000$
* $1 \leq P_0 \leq 1 \ 000 \ 000 \ 000$
* $l_i \in \lbrace$`c`$,$ `n`$,$ `p`$\rbrace $ pentru orice $1 \leq i \leq M$
* $1 \leq x_i \leq 1 \ 000 \ 000 \ 000$ pentru orice $1 \leq i \leq M$
* Dacă $T = 1$, atunci Yamada are cel puțin un obiect magic din fiecare din cele trei tipuri.

|#| Punctaj |        Restricții                                    | 
|-|---------|------------------------------------------------------|
|1|   19    | $T = 1$                                              |
|2|   13    | $T = 2$, $1 \leq M \leq 1\ 000$                         |
|3|   17    | $T = 2$                                              |
|4|    9    | $T = 3$, $1 \leq M \leq 1\ 000$, $1 \leq x_i \leq 1\ 000$  |
|5|   11    | $T = 3$, $1 \leq x_i \leq 1\ 000$                       |
|6|   12    | $T = 3$, $1 \leq M \leq 1\ 000$                         |
|7|   19    | $T = 3$                                              |


# Exemplul 1

`apgreid.in`
```
1
6 3
p 1
n 3
c 10
n 2
p 12
p 8
```

`apgreid.out`
```
10 12 3
```

# Exemplul 2

`apgreid.in`
```
2
2 3
c 3
p 2
```

`apgreid.out`
```
p 2
c 3
```

# Exemplul 3

`apgreid.in`
```
3
2 3
p 2
c 3
```

`apgreid.out`
```
125
```