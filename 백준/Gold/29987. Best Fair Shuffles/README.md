# [Gold IV] Best Fair Shuffles - 29987 

[문제 링크](https://www.acmicpc.net/problem/29987) 

### 성능 요약

메모리: 5968 KB, 시간: 132 ms

### 분류

애드 혹, 수학

### 제출 일자

2024년 7월 5일 14:33:37

### 문제 설명

<p>A Fair shuffle is a specific method of shuffling N distinct cards arranged horizontally from left to right. In a Fair shuffle, the cards are divided into two contiguous partitions which may have different card counts, and one of them may even have zero cards. Let’s denote the left partition as L and the right partition as R.</p>

<p>Cards from the left partition (L) are then merged with the cards from the right partition (R) while maintaining the relative order between the cards of each partition.</p>

<p>Given the final permutation obtained after applying K Fair shuffles to an initial sequence of N non-repeating cards numbered from 1 to N, your task is to determine the minimum possible value of K.</p>

<p>For example, if we start with the sequence 1 2 3 4 5 and perform a Fair shuffle by partitioning it into L: 1 2 and R: 3 4 5, cards from L and R can be merged in various ways:</p>

<ul>
	<li>1 3 2 4 5</li>
	<li>1 3 4 2 5</li>
	<li>3 4 5 1 2</li>
	<li>1 2 3 4 5</li>
	<li>etc</li>
</ul>

<p>Each arrangement represents a possible outcome of applying a single Fair shuffle. However, 1 3 2 5 4 is not a possible outcome as the relative order of cards 4 and 5 from R is not preserved.</p>

<p>Assume that the outcome of the first Fair shuffle is 1 3 2 4 5. If we perform a second Fair shuffle on it, we could partition the sequence into L: 1 3 2 4 and R: 5 and merge it as 1 3 2 5 4.</p>

### 입력 

 <p>The first line contains an integer N(1 ≤ N ≤ 10<sup>6</sup>), the number of cards in the deck. The second line contains a permutation of integer numbers from 1 to N describing the final arrangement of the cards.</p>

### 출력 

 <p>Output a single line with an integer K indicating the minimum number of Fair shuffles required to transform the initial sequence into the given one.</p>

