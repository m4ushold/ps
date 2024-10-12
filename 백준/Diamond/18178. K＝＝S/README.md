# [Diamond V] K==S - 18178 

[문제 링크](https://www.acmicpc.net/problem/18178) 

### 성능 요약

메모리: 2576 KB, 시간: 188 ms

### 분류

아호-코라식, 자료 구조, 분할 정복을 이용한 거듭제곱, 수학, 트리, 트라이

### 제출 일자

2024년 10월 12일 13:23:52

### 문제 설명

<p>Progressive hard octave rock tunes (so-called “phorts”) are written using a specific music notation. This flavor of rock is built on just 13 different note pitches, other pitches (in other octaves) are considered to be an outdated musical ballast. Each note can be either a long one or a short one. Consequently, there are exactly 26 different notes in the rock.</p>

<p>You are going to compose a phort tune on the occasion of your friend’s birthday and perform it with your band on the main town square. While composing the phort, you need to avoid certain musical phrases, which are heavily copyrighted as a result of long research sponsored by big record companies. It has been established that these phrases are very catchy, easy to remember, and could be exploited to bind the listeners subconsciously to a particular music company which would utilize these phrases in their production.</p>

<p>The tune is a sequence of notes. A musical phrase is also a sequence of notes and it is considered to be contained in a tune if its notes form a contiguous subsequence of the tune, which means the same notes appear in the tune right after each other in the same order.</p>

<p>Fortunately, only a few forbidden phrases have been patented so far. Thus, you have a relative freedom in composing your own tunes. In particular, you are interested in the number of acceptable tunes of some length. An acceptable tune is any tune which does not contain a forbidden phrase. The length of the tune is equal to the number of notes it contains.</p>

### 입력 

 <p>The first line contains two integers N, Q (1 ≤ N ≤ 10<sup>9</sup>, 1 ≤ Q ≤ 100). N is the length of the tune, Q is the number of forbidden musical phrases. Each of the Q following lines describes one forbidden phrase. A description of a forbidden phrase starts with a positive integer L, indicating its length, followed by a string of L lowercase English letters. Each letter represents one rock note, different letters represent different notes.</p>

<p>The sum of lengths of all forbidden phrases does not exceed 100.</p>

### 출력 

 <p>Output the number of different acceptable tunes of length N. Print the result modulo 1 000 000 007.</p>

