# [Diamond IV] Min Max Tree - 16011 

[문제 링크](https://www.acmicpc.net/problem/16011) 

### 성능 요약

메모리: 32320 KB, 시간: 732 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리, 이분 매칭, Heavy-light 분할

### 제출 일자

2026년 4월 15일 21:27:34

### 문제 설명

<p>Tanaka has recently solved a classical problem: given some tree with N vertices and weights on the edges, he found the maximum or minimum weight on K chains in the tree. Interestingly, all of these results were distinct! However, unfortunately, the weights from the original tree were lost.</p>

<p>Given Tanaka’s results, as well as the structure of the original tree, can you find some plausible assignment of weights for all edges? If you do, Groot will fall in love with the tree and you will be rewarded 100 points.</p>

### 입력 

 <p>The first line of the input will contain the integer N.</p>

<p>The next N − 1 lines of the input will contain a space-separated pair of integers (x, y) , with 1 ≤ x, y ≤ N that signifies that the tree has an edge from node x to node y. The nodes of the tree are indexed from 1 to N.</p>

<p>The next line of the input will contain the integer K.</p>

<p>The next K lines will contain a description of Tanaka’s query results, one result on each line. A result that signifies that the maximum on the path from node x to node y was z will be encoded as ”M x y z”, and one that signifies that the minimum on the path from node x to node y was z will be encoded as ”m x y z”.</p>

<p>It is guaranteed that the given edges form a tree, and that all z values are distinct.</p>

### 출력 

 <p>The output file should contain N − 1 lines, each containing three integers x y v that signify that in your assignment of weights to edges there exists an edge between node x and node y having weight v. These edges should be the same as the edges in the input file, ignoring their order. Also, the order of vertices x and y within an edge does not matter. These should lead to the described results. Also, v should be able to fit in a signed 32 bit integer.</p>

<p>It is guaranteed that some assignment of weights leads to the described results.</p>

