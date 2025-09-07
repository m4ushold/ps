# [Bronze II] Composed Rhythms - 32551 

[문제 링크](https://www.acmicpc.net/problem/32551) 

### 성능 요약

메모리: 5220 KB, 시간: 28 ms

### 분류

해 구성하기

### 제출 일자

2025년 9월 7일 19:00:51

### 문제 설명

<p>Rhythm is an important part of music and it is crucial for aspiring musicians to gain understanding of it. As the skill of the musician advances, more complex rhythms are introduced to them. To ease the learning of musical passages, a method of simplifying rhythms can be helpful. One method is to reduce the rhythm into groups of twos and threes.</p>

<p>A rhythm is composed of multiple beats. A single beat does not make up a rhythm, as the beats depend on each other. The rhythm can be subdivided into smaller components. For example, a rhythm of $7$ beats can be subdivided into $4$ beats and $3$ beats, or alternatively into $2$, $3$, and $2$ beats. However, a rhythm of $7$ beats cannot be subdivided into $1$, $3$, and  $3$ beats, since one of the components does not form a rhythm.</p>

<p>This leaves $2$ as the smallest group size of beats we can use to decompose a rhythm, but if we only use groups of size $2$ then we cannot have an odd number of beats. Adding $3$ as a group size allows us to decompose any rhythm, even if it has an odd number of beats.</p>

<p>Given the number of beats in a rhythm, provide one decomposition of the rhythm into groups of sizes $2$ and $3$.</p>

### 입력 

 <p>The first and only line of input contains a single integer $N$ ($2 \leq N \leq 10^6$), denoting the number of beats in the rhythm.</p>

### 출력 

 <p>First output one line with an integer $K$, the number of groups of which your decomposition consists. Then output a line with $K$ space-separated integers, each of which is a $2$ or a $3$. Your decomposition must be made up of the correct number of beats.</p>

<p>If there are multiple correct answers, you may output any of them.</p>

