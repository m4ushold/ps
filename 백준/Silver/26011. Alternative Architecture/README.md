# [Silver I] Alternative Architecture - 26011 

[문제 링크](https://www.acmicpc.net/problem/26011) 

### 성능 요약

메모리: 2032 KB, 시간: 4 ms

### 분류

기하학, 피타고라스 정리

### 제출 일자

2024년 6월 28일 01:08:54

### 문제 설명

<p>In his free time, Thomas greatly enjoys working on the extensive Lego project that he has built in his attic, adding house after house to his miniature city. However, he has become a bit bored with the completely rectangular layout that is enforced by the little studs of the huge base plate that his city is built on.</p>

<p>After an exchange with some other Lego creators he came across a technique that will allow him to place his buildings at different angles. Each building rests on a rectangular ground plate, to the underside of which he attaches four round $1\times 1$-plates in the corners. These $1\times 1$-plates are then placed on four studs of the base plate, like in Figure A.1.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 279px; height: 184px;"></p>

<p style="text-align: center;">Figure A.1: Placing a $6\times6$ plate diagonally.</p>

<p>If the ground plate of the building is $a\times b$ studs, what is the number of orientations it can be placed in using this technique, so that all the corner plates exactly fit on studs of the base plate?</p>

<p style="text-align: center;"><img alt="" src="" style="width: 500px; height: 375px;"></p>

<p style="text-align: center;">Figure A.2: Illustration of the first sample case. There are many ways of placing a $6 \times 11$ plate, but only $6$ distinct orientations.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $a$ and $b$ ($2 \le a,b \le 10^6$), the dimensions of the ground plate the building is resting on.</li>
</ul>

### 출력 

 <p>Output one integer, the number of different orientations the ground plate can be placed in.</p>

