# [Diamond V] Deck Randomisation - 17785 

[문제 링크](https://www.acmicpc.net/problem/17785) 

### 성능 요약

메모리: 7520 KB, 시간: 24 ms

### 분류

중국인의 나머지 정리, 수학, 정수론, 순열 사이클 분할

### 제출 일자

2025년 11월 5일 20:57:43

### 문제 설명

<p>Alice and Bob love playing Don’tminion, which typically involves a lot of shuffling of decks of different sizes. Because they play so often, they are not only very quick at shuffling, but also very consistent. Each time Alice shuffles her deck, her cards get permuted in the same way, just like Bob always permutes his cards the same way when he shuffles them. This isn’t good for playing games, but raises an interesting question.</p>

<p>They know that if they take turns shuffling, then at some point the deck will end up ordered in the same way as when they started. Alice shuffles once first, then Bob shuffles once, then Alice shuffles again, et cetera. They start with a sorted deck. What they do not know, however, is how many shuffles it will take before the deck is sorted again.</p>

<p>Can you help them compute how many shuffles it will take? As Alice and Bob can only do 10<sup>12</sup> shuffles in the limited time they have, any number strictly larger than this should be returned as huge instead.</p>

### 입력 

 <ul>
	<li>The first line contains a single integer 1 ≤ n ≤ 10<sup>5</sup>, the number of cards in the deck.</li>
	<li>The second line contains n distinct integers 1 ≤ a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> ≤ n, where a<sub>i</sub> is the new position of the card previously at position i when Alice shuffles the deck.</li>
	<li>The third line contains n distinct integers 1 ≤ b<sub>1</sub>, b<sub>2</sub>, . . . , bn ≤ n, where b<sub>i</sub> is the new position of the card previously at position i when Bob shuffles the deck.</li>
</ul>

### 출력 

 <ul>
	<li>Output a single positive integer m > 0, the minimal number of shuffles required to sort the deck, or huge when this number is strictly larger than 10<sup>12</sup>.</li>
</ul>

