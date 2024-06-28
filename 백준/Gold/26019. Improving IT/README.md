# [Gold V] Improving IT - 26019 

[문제 링크](https://www.acmicpc.net/problem/26019) 

### 성능 요약

메모리: 33356 KB, 시간: 172 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 6월 28일 12:26:50

### 문제 설명

<p>Your best friend is part of the business team at the <em>Global Center for Parallel Computing</em> (GCPC). She is responsible for buying and selling the hardware that is powering the system that will be in use for the next \(n\) months.</p>

<p>Currently, she is planning the CPU replacement cycle for a single CPU. To ensure that the system is always up-to-date, the CPU must be replaced at least every \(m\) months.</p>

<p>Fortunately, she can sell the replaced CPU to lower the overall costs to operate the new system. However, storage capacity is pricey, and she has to accept the resale value the CPU has in the month it is replaced. That means, when a CPU that was used for \(j\) months is replaced in month \(i\), you need to sell the current CPU for the value it has after \(j\) months of usage and buy a new CPU for the price of the \(i\)th month.</p>

<p>She already compiled a list of CPU prices for the next \(n\) months including their resale value after \(1\) to \(m\) months.</p>

<p>Note that you definitely need to buy a CPU in month \(1\) and you need to sell the last CPU in month \(n + 1\). How much money does the system cost at least over the \(n\) months?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers \(n\) and \(m\) (\(1\leq n,m\text{ and } n \cdot m \leq 5 \cdot 10^5\)).</li>
	<li>\(n\) lines; the $i$th line has an integer $c$ (\(0 \leq c \leq 10^9\)), the cost of a CPU in month \(i\), followed by \(\min(m, n - i + 1)\) integers $c_j$ (\(0 \leq c_j \leq 10^9\)), the money you earn by selling this CPU after $j > 0$ months.</li>
</ul>

### 출력 

 <p>Output a single integer, the minimum total cost. Note that this number can be negative if reselling CPUs was profitable.</p>

