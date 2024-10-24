# [Platinum III] novci - 3219 

[문제 링크](https://www.acmicpc.net/problem/3219) 

### 성능 요약

메모리: 5992 KB, 시간: 28 ms

### 분류

2-sat, 그래프 이론, 강한 연결 요소

### 제출 일자

2024년 10월 24일 17:46:25

### 문제 설명

<p>John and Ted are playing a very interesting game.</p>

<p>John throws a bunch of coins on the table, takes them back one by one, puts them in his pocket and writes P if the coin's upper side was head or G if it was tail.</p>

<p>This way, John will get a random sequence of characters P and G, and then make a number of statements of the form:</p>

<p>"the i-th letter is X or the j-th letter is Y"</p>

<p>where i and j are different numbers, X and Y are either P or G (independent of each other), and at least one of the claims in the statement is true.</p>

<p>Ted is sitting on his sofa on the other side of the room, listening to John and trying to determine his sequence based on the statements he makes.</p>

<p>Write a program that will help Ted determine any sequence (if one exists) of characters so that at least one claim is true in all of John's statements. </p>

### 입력 

 <p>The first line of input contains an integer L, 2 ≤ L ≤ 1000, the length of the sequence.</p>

<p>The second line of input contains an integer N, 1 ≤ N ≤ 100,000, the number of statements.</p>

<p>Each of the following lines contains a statement of the form:</p>

<pre>i X j Y</pre>

<p>1 ≤ i, j ≤ L, i and j are different, and X and Y are both either 'P' or 'G'. </p>

### 출력 

 <p>The first and only line of output should contain the discovered sequence.</p>

<p>If there is no such sequence, output -1.</p>

<p>Note: the solution need not be unique.</p>

