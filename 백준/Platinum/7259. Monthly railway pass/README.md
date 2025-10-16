# [Platinum V] Monthly railway pass - 7259 

[문제 링크](https://www.acmicpc.net/problem/7259) 

### 성능 요약

메모리: 41696 KB, 시간: 336 ms

### 분류

그래프 이론, 자료 구조, 분리 집합

### 제출 일자

2025년 10월 16일 18:23:05

### 문제 설명

<p>There are N cities in Bitlandia. Some cities are connected by train or bus, and connections work both ways. Marijonas is preparing for a month-long vacation in Bitlandia. He wants to use trains as much as possible, so he bought a monthly railway ticket. This ticket allows Marijonas unlimited train travel for a month, but it does not cover the cost of bus trips.</p>

<p>Marijonas wants to stay in one city - but is not yet sure in which one. Marijonas would like to stay in a city which allows for a cheap travel to all other cities, because he intends to travel to some of them while staying in the chosen city.</p>

<p>For Marijonas, going from one city to another is cheap if there is a route on which he travels on an unlimited number of trains and at most one bus.</p>

<p>Calculate the number of Bitlandia cities Marijonas could stay in.</p>

### 입력 

 <p>Two numbers are given in the first line: the number of cities N, and the number of connections between two cities M. Cities are labeled by 1 up to N, inclusive.</p>

<p>Each of the next M lines consist of two numbers, a<sub>i</sub> and b<sub>i</sub>, and a character T<sub>i</sub>. The i-th connection connects cities a<sub>i</sub> and b<sub>i</sub>, while the character T<sub>i</sub> indicates the transportation type of the connection: if T<sub>i</sub> is T, then the i-th connection is by train, and if T<sub>i</sub> is A, it is by bus.</p>

### 출력 

 <p>Output a single integer – the number of cities Marijonas could stay in.</p>

