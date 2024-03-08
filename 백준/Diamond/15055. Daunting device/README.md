# [Diamond V] Daunting device - 15055 

[문제 링크](https://www.acmicpc.net/problem/15055) 

### 성능 요약

메모리: 3616 KB, 시간: 612 ms

### 분류

자료 구조, 제곱근 분할법, 트리를 사용한 집합과 맵

### 제출 일자

2024년 3월 8일 16:01:55

### 문제 설명

<p>In a recent trip to an excavation site in the Caribbean island of Saint Basil, you found a mysterious device with some instructions resembling a puzzle. Your local guide Vibenas tells you that if you solve the puzzle, the device might show you the place where a big treasure left by the old merciless pirate Lyerpes is hidden.</p>

<p>The device has a tape with L cells indexed from 0 to L−1. Each cell has a color than can be changed with commands to the device. Each color is encoded by an integer, and initially all cells have the same color. The instructions that you found represent N steps to be performed before the device shows the way to the treasure. Each step is described using four integers P, X, A and B. The instructions say that to complete the step you must first count the number of cells currently having color P. Let this number be S. Then you must calculate the values</p>

<p style="text-align:center">M1 = (A + S<sup>2</sup>) mod L ,<br>
M2 = (A + (S + B)<sup>2</sup>) mod L .</p>

<p>Finally you have to make all cells within the closed interval [min(M1, M2), max(M1, M2)] to be of color X.</p>

<p>After the exhausting task of processing the N steps required by the device, you still have one job: given a color that appears the greatest number of times in the device tape after all steps (that is, a most frequent color), you must go to the shipwreck of Lyerpes’ legendary vessel and say aloud the number of cells having that color. Note that this number is unique even if more than one color appears the greatest number of times in the device tape after all steps.</p>

<p>Doing all those calculations on the device will take ages but you, as a renowned programmer, can create a program that quickly indicates the answer for the puzzle. After that, the real hard part of your mission will be to find out where is the shipwreck of Lyerpes’ old vessel.</p>

### 입력 

 <p>The first line contains three integers L, C and N (1 ≤ L, C, N ≤ 10<sup>5</sup>), representing respectively the number of cells in the tape, the number of available colors, and the number of steps in the instructions. Colors are identified by distinct integers from 1 to C and initially all cells have color 1. Each of the next N lines describes a step of the instructions with four integers P, X, A and B (1 ≤ P, X ≤ C and 0 ≤ A, B ≤ 10<sup>8</sup>), indicating respectively the color whose number of cells is used to decide the range of the step, the color the cells in the range must have after the step is performed, and the other two values used to calculate the bounds of the range as described above.</p>

### 출력 

 <p>Given a color that appears the greatest number of times in the device tape after sequentially performing all steps described in the input, output a single line with an integer indicating the number of cells having that color.</p>

