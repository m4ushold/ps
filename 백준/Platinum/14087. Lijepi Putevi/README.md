# [Platinum V] Lijepi Putevi - 14087 

[문제 링크](https://www.acmicpc.net/problem/14087) 

### 성능 요약

메모리: 12456 KB, 시간: 48 ms

### 분류

그래프 이론, 자료 구조, 그리디 알고리즘, 그래프 탐색, 정렬, 너비 우선 탐색, 분리 집합

### 제출 일자

2026년 2월 14일 17:18:59

### 문제 설명

<p>U jednoj dalekoj zemlji postoji N gradova koji su s pomoću N - 1 cesta povezani u stablo, što znači da između svakih dvaju gradova postoji jedinstven put. Udaljenost dvaju gradova definiramo kao broj cesta na tom putu između njih.</p>

<p>Neobično je što ova zemlja ima dva glavna grada označena brojevima 1 i 2; ostali gradovi označeni su brojevima od 3 do N.</p>

<p>Mirko je dobio zadatak organizirati autobusni promet u ovoj zemlji. Da bi uspio efikasno organizirati autobuse, definirao je najprije važnost grada kao udaljenost toga grada od njemu bližeg glavnoga grada, a potom važnost puta kao najmanju važnost nekog grada na tome putu.</p>

<p>Vaš je zadatak zbrojiti važnosti puteva između svakih dvaju različitih gradova (takvih parova ima N∙(N - 1) / 2). </p>

### 입력 

 <p>U prvome retku nalazi se prirodan broj N (1 ≤ N ≤ 100 000), broj gradova.</p>

<p>Svaki od sljedećih N - 1 redaka sadrži dva međusobno različita broja A, B (1 ≤ A, B ≤ N), što predstavlja cestu između gradova A i B. </p>

### 출력 

 <p>U jedini redak ispišite traženi zbroj važnosti svih puteva. </p>

