# [Diamond IV] Laminar Family - 15294 

[문제 링크](https://www.acmicpc.net/problem/15294) 

### 성능 요약

메모리: 37380 KB, 시간: 140 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리, Heavy-light 분할

### 제출 일자

2026년 4월 15일 17:06:07

### 문제 설명

<p>While studying combinatorial optimization, Lucas came across the notion of “laminar set family”. A subset family F of some set Ω is called laminar if and only if it does not contain an empty set and for any two distinct sets A, B ∈ F it is correct that either A ⊂ B or B ⊂ A or A ∩ B = ∅.</p>

<p>As an experienced problem setter Lucas always tries to apply each new piece of knowledge he gets as an idea for a programming competition problem. An area of his scientific interests covers recognition problems that usually sound like “Given some weird combinatorial property, check if the given structure satisfies it”.</p>

<p>Lucas believes that the perfect programming competition problem should contain a cactus a tree in it. Trying to put together laminar sets and trees into a recognition problem, he finally came up with the following problem: given an undirected tree on n vertices and a family F = {F<sub>1</sub>, . . . , F<sub>k</sub>} of sets, where F<sub>i</sub> consists of all vertices belonging to the simple path between some two vertices a<sub>i</sub> and b<sub>i</sub> of the tree, check if the family F is a laminar family. Note that in this case Ω = V , and each F<sub>i</sub> ⊆ V .</p>

<p>As you can see, Lucas had succeeded in suggesting this problem to the programming contest. Now it is up to you to solve it.</p>

### 입력 

 <p>The first line of the input contains two integers n and f (1 ≤ n, f ≤ 100 000) — the number of vertices in the tree and the number of elements in a family F.</p>

<p>Next n−1 lines describe the tree structure. In the i-th line there are two integers u<sub>i</sub> and v<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ n, u<sub>i</sub> ≠ v<sub>i</sub>) — the indices of the vertices that are connected by the i-th edge of the tree.</p>

<p>Next f lines describe the sets forming the family F. In the i-th line there are two integers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n), such that F<sub>i</sub> consists of all vertices belonging to the simple path between vertices a<sub>i</sub> and b<sub>i</sub> in the tree (including a<sub>i</sub> and b<sub>i</sub>).</p>

### 출력 

 <p>Output the only word “Yes” or “No” depending on whether or not the given set family is laminar.</p>

