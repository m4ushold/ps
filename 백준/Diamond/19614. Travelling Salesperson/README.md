# [Diamond IV] Travelling Salesperson - 19614 

[문제 링크](https://www.acmicpc.net/problem/19614) 

### 성능 요약

메모리: 6136 KB, 시간: 580 ms

### 분류

애드 혹, 그래프 이론

### 제출 일자

2024년 7월 21일 08:34:47

### 문제 설명

<p>In the city of RedBlue, every pair of buildings is connected by a road, either red or blue. To switch from travelling along red roads to blue roads or vice versa costs one ticket. The length of a route is the number of buildings that are visited. For example, the following route has a length of five and costs one ticket.</p>

<p style="text-align: center;">1 <span style="color:#3498db;">—</span> 2 <span style="color:#3498db;">—</span> 3 <span style="color:#e74c3c;">—</span> 4 <span style="color:#e74c3c;">—</span> 3</p>

<p>If we wanted to travel on a blue road again after visiting vertex 3 for the second time, we would need another ticket, for a total of two tickets:</p>

<p style="text-align: center;">1 <span style="color:#3498db;">—</span> 2 <span style="color:#3498db;">—</span> 3 <span style="color:#e74c3c;">—</span> 4 <span style="color:#e74c3c;">—</span> 3 <span style="color:#3498db;">—</span> 2</p>

<p>You are a travelling salesperson visiting the city of RedBlue, and you wish to visit each building at least once, while minimizing repeated visits of the same buildings. You have not yet decided which building you are starting your route from, so you would like to plan out all possible routes. Furthermore, you only have access to one ticket. For each building, you would like to find a route of minimum length that begins at that building, visits all the buildings at least once, and uses at most one ticket.</p>

### 입력 

 <p>The first line will contain a single integer N (2 ≤ N ≤ 2 000), the number of buildings in RedBlue.</p>

<p>Lines 2 to N each contain a string, with line i containing the string C<sub>i</sub>, representing the colours of the roads connected to building i. The string C<sub>i</sub> = C<sub>i,1</sub>C<sub>i,2</sub>...C<sub>i,i-1</sub> has a length of i-1 and consists only of the characters <code>R</code> and <code>B</code>. If C<sub>i,j</sub> is R, then the road between buildings i and j is red. Otherwise, it is blue.</p>

### 출력 

 <p>Output 2N lines. Lines 2i-1 for 1 ≤ i ≤ N should contain a single integer Mi, representing the length of the travel plan starting at building i. Lines 2i for 1 ≤ i ≤ N should each contain M<sub>i</sub> space separated integers, describing the order in which you visit the buildings, starting at building i.</p>

