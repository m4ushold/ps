# [Silver V] Mõttemeister - 7184 

[문제 링크](https://www.acmicpc.net/problem/7184) 

### 성능 요약

메모리: 2544 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2024년 9월 16일 13:33:02

### 문제 설명

<p>Mõttemeister on kahe mängija lauamäng. Esimene mängija mõtleb salajase 4-kohalise arvu ja teine hakkab seda ära arvama.</p>

<p>Igal käigul pakub arvaja 4-kohalise arvu. Esimene mängija vastab kahe arvuga $A$ ja $B$, kus $A$ näitab, mitu õiget numbrit oli pakutud arvus, ning $B$, mitu nendest paiknesid õigel kohal.</p>

<p>Seejärel teeb arvaja uue pakkumise ning mäng jätkub, kuni arvaja arvab salajase arvu ära või käikude arv ületab teatud piiri.</p>

<p>Näiteks olgu salajane arv 5247. Pakkumisele 1234 oleks vastus 2 (numbrid 2 ja 4 on õiged) ja 1 (number 2 on õige koha peal).</p>

<p>Kui pakkumises on korduvaid numbreid, siis loetakse iga numbrit õigeks ainult niimitu korda, kuimitu eksemplari on seda numbrit salajases arvus.</p>

<p>Kirjuta programm, mis etteantud pakkumiste ja vastuste põhjal leiab kõik võimalikud salajase arvu väärtused.</p>

### 입력 

 <p>Tekstifaili on täisarv $N$ ($1 \le N \le 10\,000$). Järgmisel $N$ real on igaühel ühe käigu kirjeldus: pakutud 4-kohaline arv, selle õigete numbrite arv $A$ ($0 \le A \le 4$) ja selles õigel kohal olevate numbrite arv $B$ ($0 \le B \le A$).</p>

### 출력 

 <p>Tekstifaili esimesele reale väljastada salajase arvu võimalike väärtuste arv $M$. Järgmisele $M$ reale väljastada salajase arvu võimalikud väärtused kasvavas järjekorras.</p>

