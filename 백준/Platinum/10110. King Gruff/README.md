# [Platinum IV] King Gruff - 10110 

[문제 링크](https://www.acmicpc.net/problem/10110) 

### 성능 요약

메모리: 20168 KB, 시간: 144 ms

### 분류

데이크스트라, 그래프 이론, 누적 합, 최단 경로

### 제출 일자

2025년 9월 17일 13:20:37

### 문제 설명

<p>King Gruff the Wolf rules over a happy, prosperous land inhabited by adorable Foxes. Unfortunately for them, he is not a nice king at all, and wants to make their lives miserable!</p>

<p>His country has N (1 ≤ N ≤ 10<sup>5</sup>) cities, with M (0 ≤ M ≤ 10<sup>5</sup>) roads running amongst them. The ith road allows one to travel from city X<sub>i</sub> to a different city Y<sub>i</sub> (1 ≤ X<sub>i</sub>, Y<sub>i</sub> ≤ N), in that direction only, and has a length of L<sub>i</sub> (1 ≤ L<sub>i</sub> ≤ 10<sup>4</sup>) and a shutdown cost of C<sub>i</sub> (1 ≤ C<sub>i</sub> ≤ 10<sup>4</sup>). There may be multiple roads running between a pair of cities, even in the same direction.</p>

<p>King Gruff particularly dislikes the Foxes living in two different cities A and B (1 ≤ A, B ≤ N), and would like to make it more inconvenient (or even impossible) to travel from city A to city B. In particular, he’ll select a distance value D (1 ≤ D ≤ 10<sup>9</sup>), and then simultaneously shut down every single road in his kingdom which is part of at least one path from city A to city B with total length no more than D. For each such road, however, he’ll have to dig into his royal treasury and pay its shutdown cost. A path consists of a sequence of roads such that each road (except the first) starts at the city that the previous road ended at, and may visit a city or road multiple times.</p>

<p>Gruff is having trouble making up his mind about what value of D to choose, however - a larger value would make things more inconvenient for his Foxy subjects, but might cost him more money as well! As such, he’ll consider Q (1 ≤ Q ≤ 10<sup>5</sup>) different values, D<sub>1</sub>, D<sub>2</sub>, . . ., D<sub>Q</sub>. For each one, he’d like to know how many tax dollars would need to be spent to shut down all roads which lie on at least one sufficiently short path from city A to city B. Since you don’t like Foxes either, you’ve agreed to help the Wolf write a program to calculate this!</p>

### 입력 

 <p>The first line contains 4 integers, each separated by a space:</p>

<ul>
	<li>N (1 ≤ N ≤ 10<sup>5</sup>), the number of cities, followed by</li>
	<li>M (0 ≤ M ≤ 10<sup>5</sup>), the number of roads, followed by</li>
	<li>A (1 ≤ A ≤ N), the starting city, followed by</li>
	<li>B (1 ≤ B ≤ N), the ending city.</li>
</ul>

<p>Each of the next M lines contain four space-separated integers X<sub>i</sub>, Y<sub>i</sub>, L<sub>i</sub>, and C<sub>i</sub>, describing the road from X<sub>i</sub> to Y<sub>i</sub> with length L<sub>i</sub> and shutdown cost C<sub>i</sub> (where 1 ≤ X<sub>i</sub>, Y<sub>i</sub> ≤ N, 1 ≤ L<sub>i</sub>, C<sub>i</sub> ≤ 10<sup>4</sup>). The next line contains Q (1 ≤ Q ≤ 10<sup>5</sup>), the number of different distance values to consider.</p>

<p>The next Q lines each contain one integer D<sub>i</sub> (1 ≤ D<sub>i</sub> ≤ 10<sup>9</sup>), which is the distance value to consider in shutting down roads.</p>

### 출력 

 <p>The output consists of Q lines, each with one integer, representing the total cost required to shut down all necessary roads given a distance value of Di , for i = 1..Q</p>

