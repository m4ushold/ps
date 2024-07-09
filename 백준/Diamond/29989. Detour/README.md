# [Diamond V] Detour - 29989 

[문제 링크](https://www.acmicpc.net/problem/29989) 

### 성능 요약

메모리: 4296 KB, 시간: 2240 ms

### 분류

데이크스트라, 분할 정복, 그래프 이론, 최단 경로

### 제출 일자

2024년 7월 9일 16:18:50

### 문제 설명

<p>In the city of Nlogonia, the mayor is taking action on his promises to revitalize the city’s road infrastructure. However, the road renewal process renders certain roads temporarily impassable, requiring the establishment of detours to ensure uninterrupted traffic flow.</p>

<p>Each road segment connects two crossroads in the city, has a positive length and can be traversed in both directions. A detour is a designated alternative route that temporarily replaces a road segment under renewal. Specifically, when the road connecting crossroads U and V is impassable, the detour must be a sequence of roads that originates at U and terminates at V , while intentionally avoiding the direct road between U and V . The goal is to find the shortest detour for each road segment to minimize disruptions while road improvements take place.</p>

<p>As the Intern at the Center for Pavement and Cars, your responsibility is to support the mayor’s initiative by calculating the length of the shortest detour for each road segment within the city.</p>

### 입력 

 <p>The first line contains two integers, N and M (1 ≤ N ≤ 300), representing the number of crossroads in the city and the number of road segments. Each of the following M lines contains three integers, U, V , and L (1 ≤ U ≤ N, 1 ≤ V ≤ N, U  ≠ V , 1 ≤ L ≤ 10<sup>6</sup>), representing a two-way road segment of length L that connects crossroads U and V. No road segment is duplicated.</p>

### 출력 

 <p>Output M lines, each line containing an integer. The integer on the i-th line represents the shortest detour length for the i-th road segment or -1 if there is no possible detour. The answer for each road segment should be given in the same order as road segments are described in the input.</p>

