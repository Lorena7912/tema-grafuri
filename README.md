Regula de rulare este:
./clasament Input GrafOut ScorOut
iar pentru a executa toate testele, este necesară rularea în terminalul bash al comenzii:
./checker
din folder-ul proiectului.
---
Fisierele input contin cate 32 de echipe precedate de punctajul lor inaintea intrarii intr-un turneu. Programul determina actualizeaza punctajul echipelor pe masura ce disputa un meci,numarul de victorii a fiecareia si clasamentul final al tuturor echipelor,pe care il afiseaza pe cate cate o linie incepand cu prima echipa care a pierdut pana la echipa care a castigat turneul. In matricea de adiacenta utilizata, exista muchie de la j la i daca intre i si j, j a castigat. Numarul de victorii  este reprezentat de numarul de elemente nenule de pe fiecare coloana. In functia clasament, se determina numarul de victorii si level-ul (numarul de meciuri necesar pentru a castiga turneul). 

Liniile:
(124) level++; 
(125) victorii[castigatori->front->i]=level;
(136)prestigiu = (q * pow((2 - q), victorii[castigatori->front->i])) / (pow(2, level) + pow((2 - q), level) * (q - 1));

(137) fprintf(scor, "%.4f %s\n", prestigiu, castigatori->front->nume);

se datoreaza faptului ca atunci cand se calculeaza numarul de victorii, respectiv se calculeaza prestigiul si se afiseaza, se parcurge coada invinsilor, in care echipa castigatoare nu se afla, aceasta aflandu-se in coada de castigatori. Este necesara incremementarea variabilei level deoarece level-ul este reprezentat de numarul maxim de victorii, adica de numarul de victorii ale echipei castigatoare.

Functia void elim_c(char *s) elimină începând de la sfârșit numele unei echipe caracterele nedorite (spațiu, '\r', '\n') care pot apărea în șirul de caractere ca urmare a citirii numelui echipei cu funcția fgetc.


