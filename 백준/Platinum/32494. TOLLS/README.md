# [Platinum V] TOLLS - 32494 

[문제 링크](https://www.acmicpc.net/problem/32494) 

### 성능 요약

메모리: 6464 KB, 시간: 112 ms

### 분류

이분 탐색, 값 / 좌표 압축, 자료 구조, 분리 집합, 누적 합, 정렬

### 제출 일자

2024년 11월 10일 14:22:56

### 문제 설명

<p>In the country named Ivo, there are $N$ cities connected by $N-1$ bidirectional highways and you can get from any city to any other city using the highways. Each highway connects two different cities $u_i$ and $v_i$ and it has a toll tax $w_i$, $1 \leq i \leq N-1$. We will call "trip" a simple path (not containing duplicate cities) along the highways between two different cities $u$ and $v$. The costs for the trips in the country Ivo have been reduced and instead of paying the sum of the tolls along the trip, only one toll is paid, which is a maximal toll for a highway along the trip.</p>

<p>Ivaylo is responsible for the profits in the country. The government asked Ivaylo $Q$ questions for the sum of the costs of all the trips with costs in the interval $[l_j, r_j]$, $1 \leq j \leq Q$. It is guaranteed that the first question is for the sum of the costs of the trips between every two different cities, i.e. $l_1=1$ and $r_1=max_{1 \leq i \leq N-1}\{w_i\}$. Ivaylo cannot handle this task, calculating by hand, and because he cannot work with computers he requires that you write a program <strong><code>tolls</code></strong>, which calculates the answers to the questions.</p>

### 입력 

 <p>The first line of the standard input contains two positive integers $N$ and $Q$ -- the number of cities in the country Ivo and the number of questions given to Ivaylo. Each of the next $N-1$ lines contains three positive integers $u_i, v_i, w_i$, which describe a highway between the cities $u_i$ and $v_i$ with toll $w_i$. Each of the rest $Q$ lines contains two positive integers $l_j, r_j$, which describe the questions given to Ivaylo.</p>

### 출력 

 <p>For each question, in input order, output on a separate line the sum of the costs of the trips that are in the interval $[l_j, r_j]$.</p>

