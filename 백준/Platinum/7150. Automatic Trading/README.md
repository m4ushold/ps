# [Platinum III] Automatic Trading - 7150 

[문제 링크](https://www.acmicpc.net/problem/7150) 

### 성능 요약

메모리: 6856 KB, 시간: 236 ms

### 분류

이분 탐색, 해싱, 라빈–카프, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 11월 1일 10:20:46

### 문제 설명

<p>A brokerage firm is interested in detecting automatic trading. They believe that a particular algorithm repeats itself; that is, it makes the same sequence of trades at a later time. The firm has identified a set of 26 key stocks that they believe are likely to be traded in concert, and they’ve encoded a series of trades as a string of letters: the letter itself indicates the stock, upper case indicates a buy, lower case indicates a sell. They want you to write a program to determine, for any two starting points, the longest sequence of identical trades from those two starting points, starting from and including those starting points as the first trade in the sequence.</p>

### 입력 

 <p>There will be several test cases in the input. Each test case will start with a string s on the first line, consisting solely of upper case and lower case letters (1≤length(s)≤100,000). On the next line will be an integer q (1≤q≤100,000), indicating the number of queries. The following q lines each describe a query with two integers, i and j (0≤i<j<length(s)), which represent two zero-based positions in the string. The input will end with a line containing only an asterisk (‘*’).</p>

### 출력 

 <p>For each query, output a single integer, indicating the length of the longest sequence of trades starting at i which is identical to the sequence of trades starting at j. Output no spaces. Do not print any blank lines between lines of output.</p>

