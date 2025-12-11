# [Platinum V] Lounge Lizards - 15038 

[문제 링크](https://www.acmicpc.net/problem/15038) 

### 성능 요약

메모리: 69368 KB, 시간: 900 ms

### 분류

기하학, 가장 긴 증가하는 부분 수열 문제, 수학

### 제출 일자

2025년 12월 11일 19:29:18

### 문제 설명

<p>Monitor lizards are a kind of reptile known mainly for their cold-bloodedness and addiction to computer screens. Due to their love for digital displays, these scaly creatures spend most of their time at home glued to a small television in the lounge.</p>

<p>Conflict has arisen at one particular reptile house. The audience here has grown so large that not everyone will be able to see the screen at once any more; specifically, a lizard will only be able to see enough if it is strictly taller than all of the lizards sitting exactly along the straight line from itself to the television.</p>

<p>Monitor lizards aren’t particularly picky about the actual contents of the screen or being able to see it obliquely (or even from the front)—they just want to be able to keep an eye on it.</p>

<p>The lizards don’t want to move, however. It’s possible to chase a monitor lizard away in order for the ones behind it to see, or leave it alone, but re-homing somewhere else in the room is unthinkable.</p>

<p>Assuming lizards are removed optimally, how many at most can remain and still see the screen?</p>

### 입력 

 <ul>
	<li>one line containing the space-separated integers T<sub>X</sub> and T<sub>Y</sub> (−10<sup>6</sup> ≤ T<sub>X</sub>, T<sub>Y</sub> ≤ 10<sup>6</sup>), the co-ordinates of the television.</li>
	<li>one line containing the integer N (1 ≤ N ≤ 10<sub>6</sub>), the number of lizards.</li>
	<li>N further lines, each containing three space-separated integers X<sub>i</sub>Y<sub>i</sub>H<sub>i</sub> (−10<sup>6</sup> ≤ X, Y ≤ 10<sup>6</sup> ; 1 ≤ H ≤ 10<sup>6</sup>), the co-ordinates and height respectively of one lizard.</li>
</ul>

<p>The co-ordinates of all televisions and lizards will be distinct.</p>

### 출력 

 <p>Output the maximum number of lizards that can stay and watch television at once.</p>

