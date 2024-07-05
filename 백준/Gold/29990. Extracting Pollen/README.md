# [Gold III] Extracting Pollen - 29990 

[문제 링크](https://www.acmicpc.net/problem/29990) 

### 성능 요약

메모리: 9836 KB, 시간: 140 ms

### 분류

스위핑

### 제출 일자

2024년 7월 5일 14:35:07

### 문제 설명

<p>Spring has arrived, ushering in a season of hard work at the Swarm of Bees Company (SBC). With the blooming of N beautiful flowers in the garden, each flower boasts a certain quantity of pollen grains. The SBC enforces strict rules to keep the bees industrious in their pollen collection.</p>

<ol>
	<li>The first rule pertains to the amount of pollen grains collected: when a bee visits a flower, it must gather the sum of the digits in its current pollen quantity. For instance, if a bee visits a flower with 123 pollen grains, it must collect 1 + 2 + 3 = 6 grains, leaving the flower with 123 − 6 = 117 grains. Similarly, if the flower holds 201 grains, the bee must gather 2 + 0 + 1 = 3 grains, leaving 198 grains remaining.</li>
	<li>All bees must form a queue at the start of the day; the bee at the front of the queue must collect pollen from one of the flowers with the largest amount pollen. If a bee visits a flower with 0 grains of pollen, it collects zero grains. After collecting pollen from a flower, the bee ends its shift and returns to the hive.</li>
</ol>

<p>Gertrude finds these rules bewildering and seeks help to determine the pollen amount she must collect when it’s her turn. Getrude has amazingly sharp sight and noticed that she is currently the K-th bee in the SBC-defined order.</p>

### 입력 

 <p>The first line contains two integers N (1 ≤ N ≤ 10<sup>6</sup>) and K (1 ≤ K ≤ 10<sup>9</sup>), representing the number of flowers and Gertrude’s position in the bee line, respectively. The second line contains N integers, where the i-th integer F<sub>i</sub> (1 ≤ F<sub>i</sub> ≤ 10<sup>6</sup> for 1 ≤ i ≤ N) denotes the initial quantity of pollen grains of the i-th flower.</p>

### 출력 

 <p>Output a single integer Q representing the amount of pollen Gertrude will collect.</p>

