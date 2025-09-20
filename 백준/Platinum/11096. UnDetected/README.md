# [Platinum IV] UnDetected - 11096 

[문제 링크](https://www.acmicpc.net/problem/11096) 

### 성능 요약

메모리: 4404 KB, 시간: 0 ms

### 분류

그래프 이론, 자료 구조, 그래프 탐색, 기하학, 분리 집합

### 제출 일자

2025년 9월 20일 15:29:42

### 문제 설명

<p>The Department of Defense has been designing autonomous robots that can infiltrate war zones and other hostile places in order to carry out missions. Now they want to test their latest design, the Penetrator1700, and they’ve hired you to help design the test environment.</p>

<p>The test environment is a rectangular field with some sensors placed within the field. Each sensor has a certain radius defining the region within which it can detect a robot. You want to design the field to have as many sensors as possible while still permitting a route across the field that avoids detection.</p>

<p>The field is a region of the coordinate plane defined by 0 ≤ x ≤ 200 and 0 ≤ y ≤ 300. The robot can be modeled by a point that must remain on the field at all times. It starts at the bottom of the field (y = 0) and must end at the top of the field (y = 300), and must not pass within range of any sensor. There are N sensor locations given by triples (x, y, r) of integers, where each (x, y) is a point on the field, and r is its radius of detection. The implied sensor circles may overlap, but will never be tangent with each other nor with the boundary of the field. All sensors are initially inactive. You must find the largest value of k such that if sensors 1, 2, 3, . . . , k are activated there is a path for the robot across the field, but no path if the (k+1)st sensor is also activated. It is guaranteed that there is no path if all N sensors are activated.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11096/1.png" style="height:211px; width:164px"></p>

<p style="text-align: center;">Figure K.1: Sensor circles corresponding to the first three sample inputs.</p>

### 입력 

 <p>Input begins with a positive integer N ≤ 200. Each of the next N lines has three space-separated integers, representing x, y, r for a sensor, where r ≤ 300. All sensors lie at different (x, y) positions. The first three sample inputs below correspond to the figure shown.</p>

### 출력 

 <p>Output a single integer (which may be 0) giving the largest k as described above.</p>

