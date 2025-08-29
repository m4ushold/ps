# [Platinum II] Isomorphic Inversion - 16301 

[문제 링크](https://www.acmicpc.net/problem/16301) 

### 성능 요약

메모리: 18800 KB, 시간: 20 ms

### 분류

그리디 알고리즘, 해싱, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 8월 29일 14:47:05

### 문제 설명

<p>Let s be a given string of up to 10<sup>6</sup> digits. Find the maximal k for which it is possible to partition s into k consecutive contiguous substrings, such that the k parts form a palindrome. More precisely, we say that strings s<sub>0</sub>, s<sub>1</sub>, . . . , s<sub>k−1</sub> form a palindrome if s<sub>i</sub> = s<sub>k−1−i</sub> for all 0 ≤ i < k.</p>

<p>In the first sample case, we can split the string <code>652526</code> into 4 parts as <code>6|52|52|6</code>, and these parts together form a palindrome. It turns out that it is impossible to split this input into more than 4 parts while still making sure the parts form a palindrome.</p>

### 입력 

 <ul>
	<li>A nonempty string of up to 10<sup>6</sup> digits.</li>
</ul>

### 출력 

 <ul>
	<li>Print the maximal value of k on a single line.</li>
</ul>

