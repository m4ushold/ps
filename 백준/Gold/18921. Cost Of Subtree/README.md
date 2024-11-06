# [Gold I] Cost Of Subtree - 18921 

[문제 링크](https://www.acmicpc.net/problem/18921) 

### 성능 요약

메모리: 6824 KB, 시간: 40 ms

### 분류

자료 구조, 분리 집합, 그리디 알고리즘, 정렬

### 제출 일자

2024년 11월 6일 09:11:21

### 문제 설명

<p>The valuable tree with $n$ vertices grows near Byteazar's house. Edge $i$ has cost $v_i$ assigned to it.</p>

<p>A subtree of the tree is defined as a non-empty <strong>connected</strong> subset of its edges.</p>

<p>The <em>cost</em> of a subtree is defined as the number of edges in the subtree multiplied by the <strong>lowest</strong> value of $v_i$ in it.</p>

<p>Byteazar wants to make some money by selling subtrees, so he wants to know the maximum cost of a subtree of his tree.</p>

### 입력 

 <p>The first line contains a single integer $n$ ($2 \le n \le 10^5$) --- the number of vertices in the tree. Each of the following $n-1$ lines contains three integers $a_i$, $b_i$ and $v_i$ ($1 \le a_i, b_i \le n$; $a_i \ne b_i$; $1 \le v_i \le 10^9$) --- the vertices connected by the edge and its cost.</p>

### 출력 

 <p>Print one integer --- the maximum cost of a subtree of the given tree.</p>

