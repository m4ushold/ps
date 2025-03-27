# [Platinum IV] Tourists - 13059 

[문제 링크](https://www.acmicpc.net/problem/13059) 

### 성능 요약

메모리: 47304 KB, 시간: 436 ms

### 분류

최소 공통 조상, 트리

### 제출 일자

2025년 3월 27일 11:15:25

### 문제 설명

<p>In Tree City, there are n tourist attractions uniquely labeled 1 to n. The attractions are connected by a set of n − 1 bidirectional roads in such a way that a tourist can get from any attraction to any other using some path of roads.</p>

<p>You are a member of the Tree City planning committee. After much research into tourism, your committee has discovered a very interesting fact about tourists: they LOVE number theory! A tourist who visits an attraction with label x will then visit another attraction with label y if y > x and y is a multiple of x. Moreover, if the two attractions are not directly connected by a road the tourist will necessarily visit all of the attractions on the path connecting x and y, even if they aren’t multiples of x. The number of attractions visited includes x and y themselves. Call this the length of a path.</p>

<p>Consider this city map:</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13059/1.png" style="height:231px; width:620px"></p>

<p>Here are all the paths that tourists might take, with the lengths for each:</p>

<pre>1 → 2 = 4, 1 → 3 = 3, 1 → 4 = 2, 1 → 5 = 2, 1 → 6 = 3, 1 → 7 = 4,
1 → 8 = 3, 1 → 9 = 3, 1 → 10 = 2, 2 → 4 = 5, 2 → 6 = 6, 2 → 8 = 2,
2 → 10 = 3, 3 → 6 = 3, 3 → 9 = 3, 4 → 8 = 4, 5 → 10 = 3</pre>

<p>To take advantage of this phenomenon of tourist behavior, the committee would like to determine the number of attractions on paths from an attraction x to an attraction y such that y > x and y is a multiple of x. You are to compute the sum of the lengths of all such paths. For the example above, this is: 4 + 3 + 2 + 2 + 3 + 4 + 3 + 3 + 2 + 5 + 6 + 2 + 3 + 3 + 3 + 4 + 3 = 55.</p>

### 입력 

 <p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. The first line of input will consist of an integer n (2 ≤ n ≤ 200,000) indicating the number of attractions. Each of the following n−1 lines will consist of a pair of space-separated integers i and j (1 ≤ i < j ≤ n), denoting that attraction i and attraction j are directly connected by a road. It is guaranteed that the set of attractions is connected.</p>

### 출력 

 <p>Output a single integer, which is the sum of the lengths of all paths between two attractions x and y such that y > x and y is a multiple of x.</p>

