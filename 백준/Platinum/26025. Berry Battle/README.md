# [Platinum III] Berry Battle - 26025 

[문제 링크](https://www.acmicpc.net/problem/26025) 

### 성능 요약

메모리: 38188 KB, 시간: 380 ms

### 분류

애드 혹, 해 구성하기, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2024년 7월 18일 18:25:43

### 문제 설명

<p>Berry picking is hard work, but also a peaceful and relaxing experience. After a long day of picking, it is common to see nothing but berries once you close your eyes to sleep. As your mind drifts into unconciousness, the berries will start living their own life and create all kinds of absurd scenarios.</p>

<p>You are given a tree with $n$ vertices numbered from $1$ to $n$. Initially, there is one berry in each vertex. There is also one ant in each vertex, guarding the berries. When picking the berry at vertex $v$, all the ants that are on different vertices will walk one step towards $v$. The ants already at $v$ will stay where they are. Note that since the graph is a tree, there is always one unique path the ants will take.</p>

<p>Your goal is to pick all the berries in the tree. The ants are no danger to you as long as they stay separated. But if at any point all the $n$ ants end up in the same vertex, they will attack you. Find a permutation of the vertices, so that if you pick the berries in that order, all the ants will <em>not</em> end up in the same vertex.</p>

### 입력 

 <p>The first line contains an integer $n$ ($2 \leq n \leq 3 \cdot 10^5$).</p>

<p>The following $n-1$ lines each contain two integers $u$ and $v$ ($1 \leq u \neq v \leq n$), meaning that an edge goes between vertices $u$ and $v$.</p>

### 출력 

 <p>If it is impossible to find an answer, print "NO".</p>

<p>Otherwise, first print "YES" on one line. On the second line, print $n$ integers $p_1, p_2, \cdots , p_n$, the order in which to pick the berries ($1 \leq p_i \leq n$). This means that the $i$:th berry you pick is the one in vertex $p_i$.</p>

