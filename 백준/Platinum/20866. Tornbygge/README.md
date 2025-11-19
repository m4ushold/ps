# [Platinum V] Tornbygge - 20866 

[문제 링크](https://www.acmicpc.net/problem/20866) 

### 성능 요약

메모리: 6276 KB, 시간: 56 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 11월 19일 10:23:15

### 문제 설명

<p>Lille Dirk Ref vill bygga ett så högt torn som möjligt med sina N klossar. Alla klossar är rätblock med en kvadratisk botten, och ett torn är en mängd med klossar som är staplade direkt ovanpå varandra (det får inte ligga två klossar bredvid varandra). För att tornet inte ska bli instabilt och rasa måste varje kloss bredd (alltså sidan på den kvadratiska botten den står på) alltid vara strikt mindre än bredden av klossen den står på. Alltså byggs tornet med de bredaste klossarna i botten, och smalare klossar ju högre upp man kommer. Dessutom måste även varje kloss vara minst lika högt som klossen nedanför, för att tornet ska bli snyggt. Hjälp Dirk att räkna ut hur högt torn han maximalt kan bygga.</p>

### 입력 

 <p>Den första raden innehåller ett heltal $N$, antalet klossar Dirk har. Därefter följer $N$ rader, en för varje kloss. På den $i$:te av dessa rader står två heltal, det $i$:te blockets bredd $W_i$, $1 \leq W_i \leq 10^9$ och höjd $H_i$, $1 \leq H_i \leq 10^9$.</p>

### 출력 

 <p>Skriv ut en rad med ett heltal: den maximala höjden som Dirk kan bygga.</p>

