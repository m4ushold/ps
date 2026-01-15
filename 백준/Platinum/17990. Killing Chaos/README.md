# [Platinum IV] Killing Chaos - 17990 

[문제 링크](https://www.acmicpc.net/problem/17990) 

### 성능 요약

메모리: 3984 KB, 시간: 20 ms

### 분류

자료 구조, 분리 집합, 오프라인 쿼리

### 제출 일자

2026년 1월 15일 11:47:41

### 문제 설명

<p>In the dangerous wild west, robbers are attacking a long train with many coaches. Chaos erupts, and the robbers realize that the amount of chaos equals the number of passengers in the train, rounded up to the nearest multiple of 10. In order to quench the chaos, they therefore decide to kill some passengers by blowing up one of the coaches.</p>

<p>What the robbers failed to realize, however, is that when there are multiple disjoint train segments, then the total amount of chaos is equal to the sum of the chaos of each train segment <em>times</em> the number of train segments!</p>

<p>Frantic to quench the now even worse chaos, the robbers continue blowing up every coach until all passengers are dead. Phew!</p>

<p>The chaos in a train segment is equal to the number passengers in that train segment rounded up to the nearest multiple of 10. What was the maximum amount of chaos during the robbery?</p>

### 입력 

 <p>On the first line is a single integer n, (3 ≤ n ≤ 100 000), the number of coaches in the train. On the second line follows n integers p<sub>1</sub>, p<sub>2</sub>, . . . p<sub>n</sub>, (0 ≤ p<sub>i</sub> ≤ 100 for each i ∈ {1, 2, . . . , n}) the number of passengers in each coach. On the third and final line follows a permutation of the numbers from 1 to n indicating the order in which the robbers blew up the coaches.</p>

### 출력 

 <p>A single integer, the maximum chaos that occurred during the robbery.</p>

