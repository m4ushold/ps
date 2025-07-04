# [Diamond IV] In Case of an Invasion, Please. . . - 16312 

[문제 링크](https://www.acmicpc.net/problem/16312) 

### 성능 요약

메모리: 43748 KB, 시간: 708 ms

### 분류

그래프 이론, 이분 탐색, 최단 경로, 데이크스트라, 최대 유량, 홀의 결혼 정리

### 제출 일자

2025년 7월 4일 13:24:54

### 문제 설명

<p>After Curiosity discovered not just water on Mars, but also an aggressive, bloodthirsty bunch of aliens, the Louvain-laNeuve municipal government decided to take precautionary measures; they built shelters in order to shelter everyone in the city in the event of an extraterrestial attack.</p>

<p>Several alien-proof shelters have been erected throughout the city, where citizens can weather an alien invasion. However, due to municipal regulations and local building codes the shelters are limited in size. This makes it necessary for the government to assign every citizen a shelter to calmly direct themselves towards in the rare event of a fleet of UFOs blotting out the sun. Conditional on no shelter being assigned more people than it can fit, it is of the utmost importance that the time it takes until everyone has arrived at a shelter is minimized.</p>

<p>We model Louvain-la-Neuve as a network of n locations at which people live, connected by m bidirectional roads. Located at s points throughout the city are the shelters, each with a given maximum capacity. What is the minimum amount of time it takes for everyone to arrive at a shelter, when we assign people to shelters optimally?</p>

<p>The Louvain-la-Neuve municipal government has made sure that there is enough shelter capacity for its citizens and all shelters can be reached from any location, i.e. it is always possible to shelter everyone in some way</p>

### 입력 

 <ul>
	<li>On the first line are three integers, the number of locations 1 ≤ n ≤ 10<sup>5</sup>, roads 0 ≤ m ≤ 2 · 10<sup>5</sup>, and shelters 1 ≤ s ≤ 10.</li>
	<li>Then follows a line with n integers 0 ≤ p<sub>i</sub> ≤ 10<sup>9</sup>, indicating the the number of people living at location 1 ≤ i ≤ n.</li>
	<li>Then follow m lines containing three integers 1 ≤ u, v ≤ n and 1 ≤ w ≤ 10<sup>9</sup> indicating that there is a bidirectional road connecting u and v that takes w time to traverse. For any two locations there is at most one road connecting them directly, and no road connects a location to itself.</li>
	<li>Finally follow s lines with two integers 1 ≤ s<sub>i</sub> ≤ n and 1 ≤ c<sub>i</sub> ≤ 10<sup>9</sup>, indicating that there is a shelter with capacity c<sub>i</sub> at location s<sub>i</sub>.</li>
</ul>

### 출력 

 <p>Print the minimum amount of time it takes to shelter everyone.</p>

