# [Platinum IV] Win Diesel - 23790 

[문제 링크](https://www.acmicpc.net/problem/23790) 

### 성능 요약

메모리: 65804 KB, 시간: 224 ms

### 분류

너비 우선 탐색, 자료 구조, 그래프 이론, 그래프 탐색, 최소 공통 조상, 우선순위 큐, 트리

### 제출 일자

2025년 12월 19일 21:56:33

### 문제 설명

<p>Exploring cave systems on Mars is an easy procedure which was pre-planned on Earth. Each cave system contains several cave rooms which are pairwise disconnected. As the cave rooms are not accessible from the surface, you were given a digging rig so that you are able to dig channels between some of them.</p>

<p>The soil is not uniform and running the digging rig is extremely diesel intensive. To save diesel you need to excavate the minimum number of channels so that every cave is accessible from the surface through the channels. At the same time, the resulting system should be connected in a way so that the number of channels you need to pass to get from the surface to any particular cave is minimized.</p>

<p>You ran a scan over the whole cave system and now you know the danger level of each cave room. The scan also shows which pairs of cave rooms, or which cave room and surface, are separated by soil that can be dug through to create a channel. Let the distance of a cave room be the minimum possible number of channels that need to be traversed to reach the room from the surface, if all the possible channels were dug.</p>

<p>Due to safety reasons, the procedure prescribes that in the process of digging, the closest (least distant) cave rooms must be made accessible before any more distant cave rooms are made accessible. If this is not uniquely determining the next room to be made accessible, then the safest (least dangerous) room should be chosen from the candidates. If this does not uniquely determine the channel that needs to be dug, then out of already accessible starting locations the safest one has to be chosen.</p>

<p>Discovering the rooms in the given order forces you to traverse through the dug channels multiple times. The machine you use to move the digging rig also drinks diesel, although much less than the digging rig. You wonder, what is the amount of diesel that you will need to do this job – this is proportional to the number of channels that will need to be traversed, starting from 0 and counting until all the channels are dug.</p>

### 입력 

 <p>The first line contains two integers N and M (1 ≤ N ≤ 2 · 10<sup>5</sup>, 0 ≤ M ≤ 2 · 10<sup>5</sup>) the number of cave rooms (including surface) and the number of possible cave channels, respectively. Surface is denoted by 0 and the cave rooms are denoted by integers from 1 to N − 1 and are ordered by increasing danger level. Each of the next M lines contains two integers, representing two cave rooms or a cave room and surface, which are separated by soil soft enough so that it can be dug through to create a connecting channel.</p>

### 출력 

 <p>Print a single integer — the total number of channel traversals you need to perform to make the whole cave system accessible according to the prescribed procedure.</p>

