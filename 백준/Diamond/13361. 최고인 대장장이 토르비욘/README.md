# [Diamond V] 최고인 대장장이 토르비욘 - 13361 

[문제 링크](https://www.acmicpc.net/problem/13361) 

### 성능 요약

메모리: 22964 KB, 시간: 172 ms

### 분류

값 / 좌표 압축, 자료 구조, 분리 집합, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 10월 31일 14:40:05

### 문제 설명

<p><em>전성기 시절의 오버워치는 지구 상에서 가장 진보된 최첨단 무기를 보유했으며, 그 무기의 출처는 바로 토르비욘 린드홀름이라는 전무후무한 기술자의 작업장이었다.</em></p>

<p>하지만 이런 토르비욘에게도 진상손님이 있었으니....</p>

<p>진상 손님 한조는 만우절을 기념해 동생인 겐지에게 이상한 검을 선물하겠다며 토르비욘에게 말도 안되는 주문을 했다.</p>

<p>토르비욘이 받은 괴상한 주문은 아래와 같다.</p>

<p><em>직사각형 모양의 철판을 한 줄로 용접해서 만들며 절대 자르지 않을 것</em>.</p>

<p><em>명색이 검이므로 철판을 이을 때는 너비가 점점 줄어들어야 한다. 너비가 더 커지거나 같은 길이로도 이어 붙일 수 없다.</em></p>

<p><em>검은 가장 길게 만들어야 할 것.</em></p>

<p>다행히도 토르비욘이 가진 모든 철판들을 이용해서 한조가 원하는 검을 만들 수 있다. 토르비욘은 실물을 만들기 전에 견적을 내보려고 한다. 세상에서 가장 긴 검을 만들기 전에 검을 건조시킬 높은 작업장을 먼저 지어야 하기 때문이다.</p>

<p>검의 길이를 구하여라.</p>

### 입력 

 <p>첫 번째 줄에는 철판의 개수인 정수 n이 입력된다. (1 ≤ n ≤ 250 000)</p>

<p>이후 입력되는 n개의 줄에는 철판의 길이인 s와 t가 입력된다. (1 ≤ s ≤ t ≤ 10<sup>9</sup> nm)</p>

<p>n개의 철판을 모두 사용하여 검을 만드는 방법이 존재하는 입력만 주어진다.</p>

### 출력 

 <p>n개의 철판을 모두 사용해 만들 수 있는 가장 긴 검의 길이를 구하여라. 검의 너비는 반드시 줄어들어야 한다.</p>

