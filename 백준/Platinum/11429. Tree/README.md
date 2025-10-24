# [Platinum V] Tree - 11429 

[문제 링크](https://www.acmicpc.net/problem/11429) 

### 성능 요약

메모리: 8608 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 트리에서의 다이나믹 프로그래밍

### 제출 일자

2025년 10월 24일 20:26:17

### 문제 설명

<p>A weighted tree is a tree where each edge is labeled with a number representing the edge's length. All lengths are positive. For each node, you have to find the maximum possible distance to any other node in the tree.</p>

### 입력 

 <p>The input file contains the description of the tree. The first line of the input file contains one integer N, 2<=N<=50000. Each of the following (N-1) lines contains the description of the tree’s edges. Each edge is described by three positive integers. The first two integers are the labels of the nodes connected by this edge, ranging from 1 to N, the third number – the length of the edge. The total length of all edges does not exceed 2<sup>31</sup> -1. It is guaranteed that the file contains a correct description of the tree.</p>

### 출력 

 <p>The output consists of exactly N lines: the k-th line contains the distance from node k (k=1..N ) to the most distant node.</p>

