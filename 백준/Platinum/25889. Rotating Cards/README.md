# [Platinum V] Rotating Cards - 25889 

[문제 링크](https://www.acmicpc.net/problem/25889) 

### 성능 요약

메모리: 4580 KB, 시간: 240 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 10월 27일 12:48:10

### 문제 설명

<p>A magician has a stack of n cards labeled 1 through n, in random order. Her trick involves discarding all of the cards in numerical order (first the card labeled 1, then the card labeled 2, etc.). Unfortunately, she can only discard the card on the top of her stack and the only way she can change the card on the top of her stack is by moving the bottom card on the stack to the top, or moving the top card on the stack to the bottom. The cost of moving any card from the top to the bottom or vice versa is simply the value of the label on the card. There is no cost to discard the top card of the stack. Help the magician calculate the minimum cost for completing her trick.</p>

<p>Given the number of cards in the magician's stack and the order of those cards in the stack, determine the minimum cost for her to discard all of the cards.</p>

### 입력 

 <p>The first input line contains a positive integer, t, indicating the number of test cases to process. Each test case is on a separate input line by itself and starts with an integer, c (1 ≤ c ≤ 10<sup>5</sup>), indicating the number of cards in the stack, followed by c labels for the cards in the stack (starting from the top going to the bottom). Each of these labels will be in between 1 and c, inclusive, and each label will be unique.</p>

### 출력 

 <p>For each test case, output a single integer on a line by itself indicating the minimum cost for the magician to complete her magic trick.</p>

