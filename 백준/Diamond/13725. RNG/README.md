# [Diamond II] RNG - 13725 

[문제 링크](https://www.acmicpc.net/problem/13725) 

### 성능 요약

메모리: 16244 KB, 시간: 10296 ms

### 분류

수학, 고속 푸리에 변환, 다항식을 이용한 선형점화식 계산

### 제출 일자

2026년 3월 30일 14:25:32

### 문제 설명

<p>로또를 좋아하는 cubelover는 로또 자동 제출 프로그램에 사용할 랜덤 숫자 생성기(RNG)를 만들기로 했다.</p>

<p>cubelover의 RNG는 아래와 같은 형태의 선형 재귀식으로 나타낼 수 있다.</p>

<p>A<sub>i</sub> = (A<sub>i−1</sub> × C<sub>1</sub> + A<sub>i−2</sub> × C<sub>2</sub> + ... + A<sub>i−k</sub> × C<sub>k</sub>) mod 104857601, (i > k)</p>

<p>N과 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>k</sub>, 그리고 C<sub>1</sub>, C<sub>2</sub>, ..., C<sub>k</sub>가 주어졌을 때, A<sub>N</sub>을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 k와 N (1 ≤ k ≤ 30,000, 1 ≤ N ≤ 10<sup>18</sup>)이 주어진다.</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>k</sub>가 셋째 줄에는 C<sub>1</sub>, C<sub>2</sub>, ..., C<sub>k</sub>가 주어진다. (0 ≤ A<sub>i</sub>, C<sub>i</sub> < 104857601)</p>

### 출력 

 <p>첫째 줄에 A<sub>N</sub>을 출력한다.</p>

