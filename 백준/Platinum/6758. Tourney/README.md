# [Platinum V] Tourney - 6758 

[문제 링크](https://www.acmicpc.net/problem/6758) 

### 성능 요약

메모리: 34792 KB, 시간: 460 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 11월 18일 23:59:43

### 문제 설명

<p>Don Cherry has been hired to run 24-hour coverage of a series of single-elimination, bracket-style, furniture disassembly tourneys (tournaments). Each competitor has a furniture disassembly skill level, an integer between 1 and 1 000 000 000. In every head-to-head match, the competitor with the larger skill level wins and moves on, while the other is eliminated from the tourney. It is guaranteed that, at any time, the skill levels of all competitors are distinct, so there are no ties.</p>

<p>There are 2<sup>N</sup> (1 ≤ N ≤ 20) competitor positions in the tourney tree, numbered 1, 2, . . . , 2<sup>N</sup> from left to right. In the first round, competitors 1 and 2 face off in a furniture disassembly race, as do competitors 3 and 4, etc. In each subsequent round, the winners of the first two matches from the previous round compete, as do the winners of the following two, etc. After N rounds, a single winner remains. For example, when N = 2, the tourney tree looks like this:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a16491ec-b026-4313-9129-ae3bbee12f40/-/preview/" style="width: 166px; height: 103px;"></p>

<p>where A represents the winner of the match between competitors 1 and 2, B represents the winner of the match between competitors 3 and 4, and C represents the winner of the match between A and B. The winner of this tourney is C.</p>

<p>Because of sponsorship contracts, some competitors will be replaced over time. After any new person comes in, a new tourney is held.</p>

<p>In order to help Don Cherry, you must write a program to compute certain tourney statistics at various points in time, given a sequence of M (1 ≤ M ≤ 1 000 000) commands — see the input format below.</p>

### 입력 

 <p>The first line of input contains two integers, N (1 ≤ N ≤ 20) and M (1 ≤ M ≤ 1 000 000), separated by one space.</p>

<p>The next 2<sup>N</sup> lines, for i from 1 to 2<sup>N</sup>, each contain one integer S<sub>i</sub>, indicating the skill level of the initial competitor at position i in the tourney tree.</p>

<p>Each of the following M lines will be a command in one of three formats:</p>

<ul>
	<li>“R i S” means that the competitor at position i is removed, and replaced with a new one with skill level S. A new tourney is then held.</li>
	<li>“W” means that your program should determine who won the current tourney. Print out the position i (between 1 and 2<sup>N</sup>) of this competitor.</li>
	<li>“S i” means that your program should print out the number of rounds that the competitor at position i won in the current tourney.</li>
</ul>

### 출력 

 <p>For each “W” or “S i” command in the input, print out the corresponding integer on a line by itself.</p>

