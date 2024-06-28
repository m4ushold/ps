# [Gold III] Chaotic Construction - 26013 

[문제 링크](https://www.acmicpc.net/problem/26013) 

### 성능 요약

메모리: 2532 KB, 시간: 28 ms

### 분류

자료 구조, 세그먼트 트리, 트리를 사용한 집합과 맵

### 제출 일자

2024년 6월 28일 12:28:19

### 문제 설명

<p>The city Gircle has only one street, and that street is cyclic. This was very convenient in times when people didn't carry a device with compass, GPS and detailed maps around in their pockets, because you only have to walk in one direction and will certainly arrive at your destination. Since Gircle's founding a lot of time has passed. Civil engineers now know a lot more about road network design and most people have immediate access to reliable and accurate navigation systems. However, the passage of time also affected the old street surface and more and more cracks and potholes appeared.</p>

<p>The local government has finally decided to improve the situation, but preserving the city's historic appeal and building new streets are unfortunately mutually exclusive. Because tourism is vital for Gircle's economy, the government's only viable option for improving the situation is to renovate segments of the street when necessary. Gircle's street is very narrow, so a construction site at a street segment makes it impossible for citizens to pass that segment or even leave or enter it.</p>

<p>As a member of the <em>Gircle</em> <em>Construction and Planning Commission</em> (GCPC), you always know when one of the $n$ street segments is closed or reopened. Naturally, the citizens expect you to tell them whether the trips they want to do are currently possible.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 300px; height: 295px;"></p>

<p style="text-align: center;">Figure C.1: Depiction of the query "<code>? 9 7</code>" in the sample input.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ ($2 \leq n \leq 10^5$) and $q$ ($1 \leq q \leq 10^5$), the number of street segments and the number of events. No street segment is initially closed.</li>
	<li>$q$ lines, each describing an event. Each event is described in one of the following ways:
	<ul>
		<li>"<code>- a</code>": Segment $a$ ($1 \leq a \leq n$) is closed. It is guaranteed that segment $a$ was open before.</li>
		<li>"<code>+ a</code>": Segment $a$ ($1 \leq a \leq n$) is reopened. It is guaranteed that segment $a$ was closed before.</li>
		<li>"<code>? a b</code>": A person asks you if it is possible to go from segment $a$ to segment $b$ ($1 \leq a, b \leq n \text{ and } a\neq b$).</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>For each event of the form "<code>? a b</code>", print one line containing the word "<code>possible</code>", if it is possible to move from segment $a$ to segment $b$, or "<code>impossible</code>" otherwise. If $a$ or $b$ are currently closed, the answer is "<code>impossible</code>".</p>

