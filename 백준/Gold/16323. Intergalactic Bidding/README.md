# [Gold V] Intergalactic Bidding - 16323 

[문제 링크](https://www.acmicpc.net/problem/16323) 

### 성능 요약

메모리: 111000 KB, 시간: 124 ms

### 분류

임의 정밀도 / 큰 수 연산, 그리디 알고리즘

### 제출 일자

2025년 8월 6일 21:03:56

### 문제 설명

<p>Today the Intergalactic Council of Pebble Coins (ICPC) conducted an intergalactic auction of the Neutronium Chaos Pebble Coin (NCPC). This coin, which was forged in the Ancient Coin Machine (ACM), is rumored to be the key to ruling the universe.</p>

<p>Due to the extremely competitive nature of the auction, as well as the odd mechanics of the intergalactic currency used (far too advanced for mere mortals to understand), the auction was conducted with the following rules:</p>

<ol>
	<li>only one participant was allowed to make a bid at a time,</li>
	<li>each participant was only allowed to make one bid, and</li>
	<li>a participant making a bid had to bid at least twice the amount of the highest bid at the time.</li>
</ol>

<p>The first participant making a bid was allowed to make a bid of any positive amount.</p>

<p>After the auction there were a lot of sore losers – understandably, having just lost their chance at world domination. To make the losers feel a little better and prevent possible rioting, the ICPC has decided to hold a lottery for the participants. The winners of the lottery are determined as follows. The ICPC picks a random number s. A group of participants is called winning if the sum of their bets from the auction is equal to s. A participant wins the lottery and receives a prize – a shiny Pebble Coin – if they belong to any winning group of participants.</p>

<p>Given the names of the participants, the bets that they made, and the random number s chosen by the ICPC, help them determine which participants won the lottery.</p>

### 입력 

 <p>The first line of input contains two integers n and s, where 1 ≤ n ≤ 1 000 is the number of participants, and 1 ≤ s < 10<sup>1 000</sup> is the random number chosen by the ICPC.</p>

<p>Then follow n lines describing the participants. Each line contains a string t and an integer b, where t is the name of a participant, and 1 ≤ b < 10<sup>1 000</sup> is the amount of his bet. The name of each participant is unique and consists of between 1 and 20 letters from the English alphabet.</p>

### 출력 

 <p>Output an integer k denoting the number of participants that won the lottery. Then output k lines containing the names of the participants that won the lottery, one per line, in any order.</p>

