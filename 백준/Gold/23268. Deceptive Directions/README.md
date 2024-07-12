# [Gold II] Deceptive Directions - 23268 

[문제 링크](https://www.acmicpc.net/problem/23268) 

### 성능 요약

메모리: 9348 KB, 시간: 84 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 7월 12일 11:58:57

### 문제 설명

<p>You find yourself on a remote island, searching for a legendary lost treasure.  However, despite having gotten your hands on directions leading straight to the treasure, you have a problem.  It turns out you have a saboteur in your expedition, and that at some point they edited the precious directions so they might no longer lead to the treasure.</p>

<p>The island can be viewed as a rectangular grid, and the instructions are a sequence of east/west/north/south steps to take in this grid, from a given starting position.  These instructions lead straight to the treasure (but may involve walking around obstacles) in the sense that there is no shorter way of reaching the treasure.  However, the saboteur has arbitrarily replaced each step of the instructions by a step in one of the other three directions.  In other words, any "west" step has been replaced by "east", "north" or "south".  This replacement has been done independently for each step, so one "west" may have been replaced by "north" and another by "south", and so on.</p>

<p>Because of this sabotage, the instructions seem pretty useless.  But maybe they can still be used to narrow down the search.  Write a program to find all possible locations of the treasure.</p>

### 입력 

 <p>The first line of input consists of two integers $w$ and $h$ ($3 \le w, h \le 1000$), the width and height of the map.  Then follow $h$ lines, each containing $w$ characters, describing the map.  Each such character is either a '<code>.</code>' symbolizing a walkable space, '<code>#</code>' symbolizing an obstacle such as a body of water, dense forest, or a mountain, or '<code>S</code>' symbolizing the starting point of the directions.</p>

<p>Finally, there is a line containing a string $I$ ($1 \le |I| \le 10^5$) consisting only of the characters '<code>NWSE</code>', giving the faulty instruction sequence.</p>

<p>The map has exactly one '<code>S</code>' and its boundary consists only of obstacle cells.  The faulty instruction sequence is such that there is at least one possible location of the treasure.</p>

### 출력 

 <p>Output the map in the same format as the input (without the first line specifying the dimensions), with all possible locations of the treasure indicated by exclamation marks ('<code>!</code>').</p>

