# [Gold III] Ace Arbiter - 26024 

[문제 링크](https://www.acmicpc.net/problem/26024) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

많은 조건 분기

### 제출 일자

2024년 7월 18일 18:26:20

### 문제 설명

<p>Alice and Bob are playing a friendly game of ping pong. The game consists of several rounds. At the end of each round, exactly one player gets one point. The first player to 11 points wins. When that happens, the game immediately ends. Alice start serving the first round, then Bob serves for the next two rounds, then Alice serves twice, then Bob serves twice, and so on.</p>

<p>At any time in the game, the current score is written $X$-$Y$, where $X$ is the number of points of the player who is currently serving, and $Y$ is the number of points of the other player. This constant switching of the scores back and forth can be a little bit error-prone. Eve is the umpire, and she wrote down a log of the current scores at a few different times during the game. But since Eve is a bit unreliable, you worry that she wrote down the wrong scores. Write a program which, given the list of scores Eve wrote down, checks whether or not this list of scores can appear in an actual game.</p>

### 입력 

 <p>The first line of input contains an integer $n$ ($1 \le n \le 100$), the number of lines in the log. Then follow $n$ lines, each containing a string of the from $X$-$Y$ ($0 \le X,Y \le 11$), the list of scores Eve wrote down, in chronological order.</p>

### 출력 

 <p>If the input is a valid log of a not necessarily finished game, output "<code>ok</code>". Otherwise, output "error $i$", where $1 \le i \le n$ is the largest value such that the list of the first $i-1$ entries is valid, but the list of the first $i$ entries is invalid.</p>

