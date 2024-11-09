# [Diamond V] Oil - 12771 

[문제 링크](https://www.acmicpc.net/problem/12771) 

### 성능 요약

메모리: 2384 KB, 시간: 1684 ms

### 분류

기하학, 정렬, 스위핑

### 제출 일자

2024년 11월 10일 02:01:18

### 문제 설명

<p>A large part of the world economy depends on oil, which is why research into new methods for finding and extracting oil is still active. Profits of oil companies depend in part on how efficiently they can drill for oil. The International Crude Petroleum Consortium (ICPC) hopes that extensive computer simulations will make it easier to determine how to drill oil wells in the best possible way.</p>

<p>Drilling oil wells optimally is getting harder each day – the newly discovered oil deposits often do not form a single body, but are split into many parts. The ICPC is currently concerned with stratified deposits, as illustrated in Figure G.1.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/12771/1.png" style="height:269px; width:547px"></p>

<p style="text-align: center;">Figure G.1: Oil layers buried in the earth. This figure corresponds to Sample Input 1.</p>

<p>To simplify its analysis, the ICPC considers only the 2-dimensional case, where oil deposits are modeled as horizontal line segments parallel to the earth’s surface. The ICPC wants to know how to place a single oil well to extract the maximum amount of oil. The oil well is drilled from the surface along a straight line and can extract oil from all deposits that it intersects on its way down, even if the intersection is at an endpoint of a deposit. One such well is shown as a dashed line in Figure G.1, hitting three deposits. In this simple model the amount of oil contained in a deposit is equal to the width of the deposit. Can you help the ICPC determine the maximum amount of oil that can be extracted by a single well?</p>

### 입력 

 <p>The first line of input contains a single integer n (1 ≤ n ≤ 2 000), which is the number of oil deposits. This is followed by n lines, each describing a single deposit. These lines contain three integers x<sub>0</sub>, x<sub>1</sub>, and y giving the deposit’s position as the line segment with endpoints (x<sub>0</sub>, y) and (x<sub>1</sub>, y). These numbers satisfy |x<sub>0</sub>|, |x<sub>1</sub>| ≤ 10<sup>6</sup> and 1 ≤ y ≤ 10<sup>6</sup>. No two deposits will intersect, not even at a point.</p>

### 출력 

 <p>Display the maximum amount of oil that can be extracted by a single oil well.</p>

