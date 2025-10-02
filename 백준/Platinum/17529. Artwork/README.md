# [Platinum V] Artwork - 17529 

[문제 링크](https://www.acmicpc.net/problem/17529) 

### 성능 요약

메모리: 4524 KB, 시간: 4 ms

### 분류

자료 구조, 기하학, 분리 집합

### 제출 일자

2025년 10월 2일 20:29:44

### 문제 설명

<p>The Mona Dura is one of the most valuable artworks in Nlogonia Museum. The famous painting is displayed in a rectangular room of M by N meters. The room entrance is in a corner of it, while the Mona is in the corner diagonally opposite to the entrance.</p>

<p>To prevent theft, the room has motion sensors that are activated every night when the museum closes. Each sensor has a sensitivity S, such that the sensor triggers an alarm if it detects any movement at no more than S meters from its location.</p>

<p>Tonight a thief broke into the museum with the purpose to steal the Mona Dura. To achieve his goal, the thief needs to enter the room and reach the painting without being detected by any of the motion sensors, that is, he must keep a distance longer to Si meters from the i-th motion sensor all the time, for all the sensors.</p>

<p>The thief has access to the plants of the museum, therefore, he knows the size of the room, the coordinates, and the sensitivities of each of the motion sensors. Given this information, your task is to determine if it is possible for the thief to steal the Mona Dura.</p>

### 입력 

 <p>The first line of input contains three integer numbers, M, N, and K, representing the size of the room, and the number of sensors, respectively. (10 ≤ M, N ≤ 10<sup>4</sup>, 1 ≤ K ≤ 1000). The entrance to the room is located at position (0, 0), and the painting at position (M, N).</p>

<p>Each of the next K lines describes one of the K sensors, it contains three integer numbers, X, Y, and S, where (X, Y ) represents the sensors location and S represents the sensor’s sensitivity. (0 < X < M, 0 < Y < N, 0 < S ≤ 10<sup>4</sup>). All dimensions and coordinates in the input are in meters. It is guaranteed that all sensors have different coordinates.</p>

### 출력 

 <p>Your program must output a single line containing the character ‘S’ in case the painting can be stolen, or the character ‘N’ otherwise.</p>

