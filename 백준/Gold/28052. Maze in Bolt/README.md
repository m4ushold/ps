# [Gold II] Maze in Bolt - 28052 

[문제 링크](https://www.acmicpc.net/problem/28052) 

### 성능 요약

메모리: 2920 KB, 시간: 72 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2025년 6월 30일 23:21:22

### 문제 설명

<p>Usain has an online store specializing in selling 3D puzzles made by 3D printers. One of the best-selling puzzles these days is the Maze in Bolt. This puzzle is composed of two parts: a screw-shaped piece with an embossed labyrinth engraved on it, and a nut. The inner part of the nut may contain tips. These tips make the nut slide only through the corridors of the labyrinth.</p>

<p>Initially, the two parts of the puzzle are separated. The challenge is to slide the nut all the way through the maze until it reaches the head of the bolt. The nut can be moved clockwise, counterclockwise, down (towards the head of the bolt), and up (away from the head). Each of these movements is only possible when every tip in the inner part of the nut is not prevented from sliding to the new position due to some wall of the maze. Besides the mentioned movements, another one is allowed: when the bolt and the nut are separated, the nut can be flipped. The illustration below shows both parts of the puzzle as well as all the allowed moves.</p>

<table class="table table-bordered td-center td-middle">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 71px; height: 180px;"> 			 </td>
			<td><img alt="" src="" style="width: 69px; height: 46px;"></td>
			<td><img alt="" src="" style="width: 135px; height: 228px;"></td>
		</tr>
		<tr>
			<td>(a) Screw-shaped piece</td>
			<td>(b) Nut piece</td>
			<td>(c) Movements of the nut</td>
		</tr>
	</tbody>
</table>

<p>A customer placed an order for a large quantity of the Maze in Bolt. Each puzzle is designed by Usain himself in a random and unique way but, due to the size of the order and the tight deadline, he believes he will not be able to check whether the created puzzles have a solution or not. Usain asked for your help in devising an algorithm that quickly checks any given pair of nut and bolt. For doing so, the inner part of the nut will be modeled as a binary circular string. Regarding the bolt, each row of the maze will be modeled the same way.</p>

### 입력 

 <p>The first line contains two integers $R$ ($1 ≤ R ≤ 1000$) and $C$ ($3 ≤ C ≤ 100$), indicating respectively the number of rows and columns of the maze. The second line contains a circular string $S$ of length $C$, representing the inner part of the nut. Each character of $S$ is “<code>1</code>” if the nut has a tip in the corresponding position, while an empty space is indicated by character “<code>0</code>”. Each of the next $R$ lines contains a circular string describing a row of the maze. In this case, each character of the string is “<code>1</code>” if the maze has a wall in the corresponding position, while an empty space is indicated by character “<code>0</code>”. Rows are given from top (the tip of the bolt) to bottom (the head).</p>

### 출력 

 <p>Output a single line with the uppercase letter “<code>Y</code>” if the puzzle has a solution, and the uppercase letter “<code>N</code>” otherwise.</p>

