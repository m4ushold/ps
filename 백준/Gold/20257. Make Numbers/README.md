# [Gold V] Make Numbers - 20257 

[문제 링크](https://www.acmicpc.net/problem/20257) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 구현

### 제출 일자

2024년 11월 6일 22:36:55

### 문제 설명

<p>Peter is a math teacher at an elementary school. To familiarize students with three basic arithmetic operations plus (+), minus (−) and times (×), he gives a simple arithmetic puzzle as homework. The puzzle is that you are given 4 digits, and you are told to build as many non-negative integers as possible using just those 4 digits and at least one of the three basic arithmetic operations. For example, you are given 1,1,2,1 as the digits, and then you can build 32 non-negative integers as Table 1.</p>

<p style="text-align: center;">Table 1: Numbers made by 1,1,2,1.</p>

<table class="table table-bordered tr-center td-center" style="width:100%;">
	<tbody>
		<tr>
			<td>0 = 2 − 1 − 1 × 1</td>
			<td>1 = 2 + 1 − 1 − 1</td>
			<td>2 = 2 + 1 − 1 × 1</td>
			<td>3 = 2 + 1 + 1 − 1</td>
			<td>4 = 2 + 1 + 1 × 1</td>
			<td>5 = 2 + 1 + 1 + 1</td>
			<td>8 = 11 − 2 − 1</td>
			<td>9 = 11 − 2 × 1</td>
		</tr>
		<tr>
			<td>10 = 12 − 1 − 1</td>
			<td>11 = 12 − 1 × 1</td>
			<td>12 = 12 + 1 − 1</td>
			<td>13 = 12 + 1 × 1</td>
			<td>14 = 12 + 1 + 1</td>
			<td>19 = 21 − 1 − 1</td>
			<td>20 = 21 − 1 × 1</td>
			<td>21 = 21 + 1 − 1</td>
		</tr>
		<tr>
			<td>22 = 21 + 1 × 1</td>
			<td>23 = 21 + 1 + 1</td>
			<td>32 = 21 + 11</td>
			<td>109 = 111 − 2</td>
			<td>111 = 112 − 1</td>
			<td>112 = 112 × 1</td>
			<td>113 = 112 + 1</td>
			<td>120 = 121 − 1</td>
		</tr>
		<tr>
			<td>121 = 121 × 1</td>
			<td>122 = 121 + 1</td>
			<td>132 = 12 × 11</td>
			<td>210 = 211 − 1</td>
			<td>211 = 211 × 1</td>
			<td>212 = 211 + 1</td>
			<td>222 = 111 × 2</td>
			<td>231 = 21 × 11</td>
		</tr>
	</tbody>
</table>

<p>To check whether the student’s answer includes all possible integers, Peter needs to know the total number of non-negative integers that can be built for the puzzle. Please write a program to help Peter compute the total number.</p>

### 입력 

 <p>The input file contains 4 integers separated by a space in a line, which indicates the given digits.</p>

### 출력 

 <p>Output the total number of non-negative integers that can be built.</p>

