# [Platinum V] Flipping Cards - 11638 

[문제 링크](https://www.acmicpc.net/problem/11638) 

### 성능 요약

메모리: 2924 KB, 시간: 96 ms

### 분류

너비 우선 탐색, 자료 구조, 깊이 우선 탐색, 분리 집합, 그래프 이론, 그래프 탐색

### 제출 일자

2026년 2월 16일 11:26:59

### 문제 설명

<p>Mike and his young daughter Jesse are playing a new card game meant for kids. The rules are quite simple, each player is dealt a hand of cards. Each card has one picture on each side. They take turns playing cards and the first one to run out of cards is the winner.</p>

<p>A player’s turn consists of picking a subset of cards from their hand and laying them on the table. The only rule is that the cards must be placed on the table such that no two cards are showing the same picture.</p>

<p>Mike thought this was a very appropriate game to play with his kid because of the simple rules. Mike also liked this game because finding the best strategy is an algorithmically interesting challenge!</p>

<p>Help Mike determine if he can play his entire hand on his first round.</p>

### 입력 

 <p>The first line of the input contains a single positive integer T (T ≤ 10) indicating the number of test cases. Each test case begins with a single integer n denoting the number of cards in Mike’s hand. Here 1 ≤ n ≤ 50 000. Following this are n lines, each describing a card in Mike’s hand.</p>

<p>The pictures on the cards are represented by integers. The ith card is given by two integers p<sub>i</sub>, q<sub>i</sub> where 1 ≤ p<sub>i</sub>, q<sub>i</sub> ≤ 2n.</p>

### 출력 

 <p>For each test case you should output a single line with the word possible if it is possible for Mike to play his entire hand in one turn, or impossible if Mike cannot play his entire hand in one turn.</p>

