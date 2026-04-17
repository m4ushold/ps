# [Diamond I] Synchronization - 7610 

[문제 링크](https://www.acmicpc.net/problem/7610) 

### 성능 요약

메모리: 16748 KB, 시간: 148 ms

### 분류

트리, 링크/컷 트리

### 제출 일자

2026년 4월 17일 11:11:05

### 문제 설명

<p>The JOI Co., Ltd. has N servers in total around the world. Each server contains an important piece of information. Different servers contain different pieces of information. The JOI Co., Ltd. is now building digital lines between the servers so that the pieces of information will be shared with the servers. When a line is built between two servers, pieces of information can be exchanged between them. It is possible to exchange pieces of information from one server to another server which is reachable through the lines which are already built.</p>

<p>Each server has a high-performance synchronization system. When two servers can exchange pieces of information each other and they contain different pieces of information, they automatically synchronize the pieces of information. After a synchronization between the server A and the server B, both of the servers A and B will contain all the pieces of information which are contained in at least one of the servers A and B before the synchronization.</p>

<p>In order to reduce the cost, only N − 1 lines can be built. After the N − 1 lines are built, there will be a unique route to exchange pieces of information from one server to another server without passing through the same server more than once.</p>

<p>In the beginning (at time 0), no lines are built. Sometimes, lines are built in a harsh condition (e.g. in a desert, in the bottom of sea). Some of the lines become unavailable at some point. Once a line becomes unavailable, it is not possible to use it until it is rebuilt.</p>

<p>It is known that, at time j (1 ≤ j ≤ M), the state of exactly one line is changed.</p>

<p>We need to know the number of different pieces of information contained in some of the servers at time M + 1.</p>

<p>Write a program which, given information of the lines to be built and the state of the lines, determine the number of different pieces of information contained in some of the servers</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line of input contains three space separated integers N, M, Q. This means the number of the servers is N, a list of M changes of the state of the lines is given, and we need to know the number of different pieces of information contained in Q servers.</li>
	<li>The i-th line (1 ≤ i ≤ N − 1) of the following N − 1 lines contains space separated integers X<sub>i</sub>, Y<sub>i</sub>. This means the line i, when it is built, connects the server X<sub>i</sub> and the server Y<sub>i</sub>.</li>
	<li>The j-th line (1 ≤ j ≤ M) of the following M lines contains an integer D<sub>j</sub>. This means the state of the line D<sub>j</sub> is changed at time j. Namely, if the line D<sub>j</sub> is unavailable just before time j, this line is built at time j. If the line D<sub>j</sub> is available just before time j, this line becomes unavailable at time j. When the state is changed at time j, all the synchronization processes will be finished before time j + 1.</li>
	<li>The k-th line (1 ≤ k ≤ Q) of the follwing Q lines contains an integer C<sub>k</sub>. This means we need to know the number of different pieces of information contained in the server C<sub>k</sub> in the end.</li>
</ul>

### 출력 

 <p>Write Q lines to the standard output. The k-th line (1 ≤ k ≤ Q) should contain an integer, the number of different pieces of information contained in the server C<sub>k</sub> in the end.</p>

