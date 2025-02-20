# [Platinum I] Monkey and Apple-trees - 11843 

[문제 링크](https://www.acmicpc.net/problem/11843) 

### 성능 요약

메모리: 198760 KB, 시간: 372 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2025년 2월 20일 12:32:34

### 문제 설명

<p>Everyone knows that the yummiest fruit in the world is an apple. Even the monkey Chris knows that. There are many apple-trees in the a forest located along the river and numerated consecutively starting from 1. Sometimes Chris comes to the forest, chooses a group of apple-trees growing consecutively (selected interval) and counts the amount of apple-trees with red-ripen apples among them. Sometimes apples on a few consecutive apple-trees have red-ripen before his next arrival.</p>

<p>You have to answer how many apple-trees in the selected interval have red-ripen apples at each Chris's arrival. At the beginning all the apples are unripen</p>

### 입력 

 <p>In the first line of input file an integer M is given - number of events (1 ≤ M ≤ 100000). The following M lines contain description of events - each contains three integers D<sub>i</sub>, X<sub>i</sub>, Y<sub>i</sub> (1 ≤ D<sub>i</sub> ≤ 2, X<sub>i</sub> ≤ Y<sub>i</sub>). If the D<sub>i</sub> = 1, then the event is Chris's arrival, if the D<sub>i</sub> = 2 - red-ripening of all apples in the selected interval of the apple-trees. Other two numbers X<sub>i</sub> and Y<sub>i</sub>, describe the interval for the event.</p>

<p>For calculating the limits of the interval there is an additional number C. At the beginning C = 0. An interval for the event is interval from X<sub>i</sub>+C to Y<sub>i</sub>+C inclusively. It's guaranteed that 1 ≤ X<sub>i</sub>+C, Y<sub>i</sub>+C ≤ 10<sup>9</sup>.</p>

<p>If the event is apples red-ripening then C doesn't change. If the event is Chris's arrival, then as the result C becomes equal to the amount of red-ripen apple-trees he has counted.</p>

### 출력 

 <p>For each of Chris's arrival output one line with one number in it - the task answer.</p>

