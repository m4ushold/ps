# [Gold III] Manhattan Power Failure - 11450 

[문제 링크](https://www.acmicpc.net/problem/11450) 

### 성능 요약

메모리: 5968 KB, 시간: 12 ms

### 분류

그래프 이론, 자료 구조, 그래프 탐색, 분리 집합, 격자 그래프, 플러드 필

### 제출 일자

2025년 8월 4일 18:10:04

### 문제 설명

<p>There has been a huge storm ravaging through Manhattan destroying many power-lines and leaving entire blocks without power. The first damage assessment came up with a report showing which blocks are still connected by power lines and which are not. When a block is connected to another block with power lines, this means that if one block has power, then the other will also have power. Only blocks that are adjacent (either horizontally, or vertically) may be connected by a power line. Also, there is a quickly made list with all blocks that have power generators, or that are connected to external power sources.</p>

<p>Your task is to quickly identify where to put up emergency power lines, so that all block of this grid-like city have power again.</p>

### 입력 

 <p>The input starts with a line containing an integer T, the number of test cases. Then for each test case:</p>

<ul>
	<li>One line with four integers, n, m, p, c, where n, m (1 ≤ n, m ≤ 100) are the number of blocks that the city is wide respectively long (the city has n x m blocks), p (1 ≤ p ≤ n · m) is the number of power generators, and c (1 ≤ c ≤ 2n · m, or in fact: 1 ≤ c ≤ 2n · m − n − m) is the number of intact power lines between adjacent city blocks.</li>
	<li>p lines, each with two integers x (0 ≤ x < n), y (0 ≤ y < m) indicating that the block with coordinates (x, y) in the grid has its own power source or is connected to an external power source.</li>
	<li>c lines, each with two integers x (0 ≤ x < n), y (0 ≤ y < m), and a character d (d = ’R’ or d = ’U’) indicating that there is an intact power line either between block (x, y) and block (x + 1, y) if d = ’R’, or between block (x, y) and block (x, y + 1) if d = ’U’. Of course, if x = n − 1, then d cannot be ’R’. Likewise, if y = m − 1, then d cannot be ’U’.</li>
</ul>

### 출력 

 <p>Per test case, output one line with one integer indicating the number of emergency power lines needed to connect all blocks to a power source.</p>

