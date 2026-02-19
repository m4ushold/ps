# [Platinum V] Justified Jungle - 15267 

[문제 링크](https://www.acmicpc.net/problem/15267) 

### 성능 요약

메모리: 126236 KB, 시간: 820 ms

### 분류

수학, 다이나믹 프로그래밍, 트리, 정수론, 트리에서의 다이나믹 프로그래밍, 조화수

### 제출 일자

2026년 2월 19일 11:30:36

### 문제 설명

<p>As you probably know, a tree is a graph consisting of n nodes and n − 1 undirected edges in which any two nodes are connected by exactly one path. A forest is a graph consisting of one or more trees. In other words, a graph is a forest if every connected component is a tree. A forest is justified if all connected components have the same number of nodes.</p>

<p>Given a tree G consisting of n nodes, find all positive integers k such that a justified forest can be obtained by erasing exactly k edges from G. Note that erasing an edge never erases any nodes. In particular when we erase all n − 1 edges from G, we obtain a justified forest consisting of n one-node components.</p>

### 입력 

 <p>The first line contains an integer n (2 ≤ n ≤ 1 000 000) — the number of nodes in G. The k-th of the following n − 1 lines contains two different integers a<sub>k</sub> and b<sub>k</sub> (1 ≤ a<sub>k</sub> , b<sub>k</sub> ≤ n) — the endpoints of the k-th edge.</p>

### 출력 

 <p>The first line should contain all wanted integers k, in increasing order.</p>

