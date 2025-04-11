# [Platinum III] Goldmine - 8040 

[문제 링크](https://www.acmicpc.net/problem/8040) 

### 성능 요약

메모리: 6360 KB, 시간: 24 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑

### 제출 일자

2025년 4월 11일 10:38:13

### 문제 설명

<p>Byteman, one of the most deserving employee of The Goldmine of Byteland, is about to retire by the end of the year. The Goldmine management would like to reward him in acknowledgment of his conscientious work. As a reward Byteman may receive a small lot - a rectangular piece of the mine's area with sides of length s and w parallel to the axes of the coordinate system. He may choose the location of the lot. Of course, a value of the lot depends on the location. The value of the lot is a number of gold nuggets in the area of the lot (if a nugget lies on the border of the lot, then it is in the area of the lot). Your task is to write a program which computes the maximal possible value of the lot (the value of the lot with the best location). In order to simplify we assume that the terrain of the Goldmine is boundless, but the area of gold nuggets occurrence is limited.</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input the location of gold nuggets,</li>
	<li>computes the maximal value of a lot (i.e. the maximal number of gold nuggets on the lot of given size),</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there are two positive integers s and w separated by a single space, (1 ≤ s,w ≤ 10,000); they denote the lengths of lot's sides - parallel to the OX-axe and OY-axe respectively. There is one positive integer n written in the second line, (1 ≤ n ≤ 15,000). It denotes the number of nuggets in the area of the Goldmine. In the following n lines there are written the coordinates of the nuggets. Each of these lines consists of two integers x and y, (-30,000 ≤ x,y ≤ 30,000), separated by a single space and denoting the  and the  coordinate of a nugget respectively.</p>

### 출력 

 <p>The standard output should contain exactly one integer equal to the value of the most valuable lot of a given size.</p>

