# [Diamond V] Jumping Grasshopper - 18038 

[문제 링크](https://www.acmicpc.net/problem/18038) 

### 성능 요약

메모리: 6124 KB, 시간: 268 ms

### 분류

자료 구조, 세그먼트 트리, 이분 탐색

### 제출 일자

2025년 9월 24일 13:40:06

### 문제 설명

<p>Jazmín has a garden in front of her house, with N plants forming a line in the left-right direction. She is very proud of her plants, and measures their growing heights with great precision, because she thinks that each plant is different and so it must have a different height.</p>

<p>One day Jazmín found a grasshopper in her garden, and after watching it for some time, she noticed a very peculiar behavior. During each jump the grasshopper moves to the first plant taller than its current plant, in the direction it is looking at. Besides, before landing on the new plant, the grasshopper does a backflip that changes its direction. That is, if before jumping the grasshopper is looking to the left, once the jump is completed it is looking to the right, and vice versa. The grasshopper keeps jumping until there is no taller plant in the direction it is looking at.</p>

<p>Jazmín decided to record her sightings of the grasshopper. Each time she saw it, she wrote the plant where the grasshopper was, and the direction it was looking at. She also recorded how her plants were growing, as she always does. Now Jazmín wonders, for each sighting of the grasshopper, on which plant it stopped jumping. Jazmín’s notebook is currently broken, so she cannot write her own program. Can you help her?</p>

### 입력 

 <p>The first line contains two integers N and M (1 ≤ N, M ≤ 2×10<sup>5</sup>), indicating respectively the number of plants and the number of records. Plants are identified by distinct integers from 1 to N according to their positions in front of the house, starting from the leftmost plant. The second line contains N different integers H<sub>1</sub>, H<sub>2</sub>, . . . , H<sub>N</sub> (0 ≤ H<sub>i</sub> ≤ 10<sup>9</sup> for i = 1, 2, . . . , N), where H<sub>i</sub> is the initial height of plant i. The following M lines describe Jazmín’s records in chronological order, one line per record. If a record represents the growing of a plant, the line contains the uppercase letter “U” followed by two integers I (1 ≤ I ≤ N) and H (H ≤ 10<sup>9</sup>), indicating that the new height of plant I is H; the new height H is greater than the old height of plant I, and different from the current height of each of the other plants. If a record represents the sighting of the grasshopper, the line contains the uppercase letter “L” or the uppercase letter “R” followed by an integer J (1 ≤ J ≤ N) indicating that the grasshopper starts jumping from plant J; the grasshopper starts looking to the left if the letter is “L”, and it starts looking to the right if the letter is “R”. There is at least one record that is a sighting of the grasshopper.</p>

### 출력 

 <p>Output a line for each sighting of the grasshopper. The line must contain an integer indicating the plant where the grasshopper stops jumping. Write the results in chronological order, that is, using the same order of the input.</p>

