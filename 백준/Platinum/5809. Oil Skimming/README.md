# [Platinum IV] Oil Skimming - 5809 

[문제 링크](https://www.acmicpc.net/problem/5809) 

### 성능 요약

메모리: 15288 KB, 시간: 300 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 이분 매칭

### 제출 일자

2025년 7월 27일 23:27:02

### 문제 설명

<p>Thanks to a certain "green" resources company, there is a new profitable industry of oil skimming. There are large slicks of crude oil floating in the Gulf of Mexico just waiting to be scooped up by enterprising oil barons. One such oil baron has a special plane that can skim the surface of the water collecting oil on the water's surface. However, each scoop covers a 10m by 20m rectangle (going either east/west or north/south). It also requires that the rectangle be completely covered in oil, otherwise the product is contaminated by pure ocean water and thus unprofitable!</p>

<p>Given a map of an oil slick, the oil baron would like you to compute the maximum number of scoops that may be extracted. The map is an NxN grid where each cell represents a 10m square of water, and each cell is marked as either being covered in oil or pure water.</p>

### 입력 

 <p>The input starts with an integer K (1 ≤ K ≤ 100) indicating the number of cases. Each case starts with an integer N (1 ≤ N ≤ 600) indicating the size of the square grid. Each of the following N lines contains N characters that represent the cells of a row in the grid. A character of '#' represents an oily cell, and a character of '.' represents a pure water cell.</p>

### 출력 

 <p>For each case, one line should be produced, formatted exactly as follows: "Case X: M" where X is the case number (starting from 1) and M is the maximum number of scoops of oil that may be extracted.</p>

