# [Gold IV] Bottles - 32829 

[문제 링크](https://www.acmicpc.net/problem/32829) 

### 성능 요약

메모리: 4460 KB, 시간: 8 ms

### 분류

누적 합, 정렬

### 제출 일자

2024년 11월 28일 17:17:02

### 문제 설명

<p>In the famous ICPC race, $n$ runners will participate. The course is $m$ kilometers long and for safety, it is divided into $m$ ranges. Each range is one kilometer long and Range $i$ ($1 ≤ i ≤ m$) is the interval $(i - 1, i)$, which is the section between $i - 1$ km and $i$ km from the starting point. We will ignore the case where the distance between the starting point and a runner is an integer. As the weather is quite hot, the organizers would like to put enough water. They will maintain a certain number of water bottles in each range. When a runner takes one bottle, they will put another immediately. They have found that the optimal number of water bottles could be obtained by calculating the maximum number of runners in that interval during the race. Based on the previous records of each runner, they have estimated how many seconds he/she will spend in each range.</p>

<p>Consider the following example. There are three runners, and the length of the course is six kilometers. The table shows the amount of time runners will spend in each range (in seconds).</p>

<table class="table table-bordered th-center td-center">
	<tbody>
		<tr>
			<th>Runner</th>
			<th>Range $1$</th>
			<th>Range $2$</th>
			<th>Range $3$</th>
			<th>Range $4$</th>
			<th>Range $5$</th>
			<th>Range $6$</th>
		</tr>
		<tr>
			<th>$1$</th>
			<td>$350$s</td>
			<td>$360$s</td>
			<td>$370$s</td>
			<td>$380$s</td>
			<td>$390$s</td>
			<td>$400$s</td>
		</tr>
		<tr>
			<th>$2$</th>
			<td>$240$s</td>
			<td>$240$s</td>
			<td>$240$s</td>
			<td>$240$s</td>
			<td>$240$s</td>
			<td>$240$s</td>
		</tr>
		<tr>
			<th>$3$</th>
			<td>$480$s</td>
			<td>$480$s</td>
			<td>$520$s</td>
			<td>$600$s</td>
			<td>$600$s</td>
			<td>$600$s</td>
		</tr>
	</tbody>
</table>

<p>Now we will check the number of runners in each range during the race. Intentionally, the table below is not complete. When you fill the whole table and compute the maximum number of runners for each range, you can see that you need to put three bottles of water in Range $1$, two in Range $2$ and Range $3$, and one in Range $4$, Range $5$, and Range $6$. Note that at $480$s, Runner $2$ leaves Range $2$ and Runner $3$ arrives at Range $2$, both of which will be ignored as their distance from the starting point is an integer. At $480$s, no runner is in Range $1$ and in Range $3$ and Runner $1$ is in Range $2$. Then, for example, at $481$s, Runner $1$ and Runner $3$ will be in Range $2$.</p>

<table class="table table-bordered th-center td-center">
	<tbody>
		<tr>
			<th>Time elapsed</th>
			<th>Range $1$</th>
			<th>Range $2$</th>
			<th>Range $3$</th>
			<th>Range $4$</th>
			<th>Range $5$</th>
			<th>Range $6$</th>
		</tr>
		<tr>
			<th>($0$s, $240$s)</th>
			<td>$3$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
		</tr>
		<tr>
			<th>($240$s, $350$s)</th>
			<td>$2$</td>
			<td>$1$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
		</tr>
		<tr>
			<th>($350$s, $480$s)</th>
			<td>$1$</td>
			<td>$2$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
		</tr>
		<tr>
			<th>($480$s, $710$s)</th>
			<td>$0$</td>
			<td>$2$</td>
			<td>$1$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
		</tr>
		<tr>
			<th>($710$s, $720$s)</th>
			<td>$0$</td>
			<td>$1$</td>
			<td>$2$</td>
			<td>$0$</td>
			<td>$0$</td>
			<td>$0$</td>
		</tr>
		<tr>
			<th>$\dots$</th>
			<td>$\dots$</td>
			<td>$\dots$</td>
			<td>$\dots$</td>
			<td>$\dots$</td>
			<td>$\dots$</td>
			<td>$\dots$</td>
		</tr>
	</tbody>
</table>

<p>Given the number of runners, the length of the course, and the amount of time each runner will spend in each range, write a program to compute the number of bottles to be put in each range.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, $n$ and $m$ ($1 ≤ n ≤ 100$, $1 ≤ m ≤ 300$), where $n$ is the number of runners and $m$ is the length of the course. In the following $n$ lines, the $i$-th line contains $m$ positive integers that represent the amount of time Runner $i$ will spend in each range. More precisely, the $j$-th number on the line is the time Runner $i$ will spend in Range $j$. No runner will spend more than $10\,000$ seconds in any range.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the numbers of bottles in each range from Range $1$ to Range $m$.</p>

