# [Platinum IV] Keep Him Inside - 17792 

[문제 링크](https://www.acmicpc.net/problem/17792) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

해 구성하기, 기하학, 수학

### 제출 일자

2025년 9월 29일 23:33:37

### 문제 설명

<p>As a result of a long-standing war between the Sorcerers and the Orcs, you have been assigned as officer of one of the prison blocks. Recently the leader of the Orcs has been captured and placed inside a special cell. It works as follows: the cell is a convex polygon with at every vertex a guard tower in which a Sorcerer is placed.</p>

<p>Thanks to the recent agreement between the Sorcerers and Orcs, called the Beneficial Activities for Prisoners in Cells, the leader of the Orcs should be able to move around freely in his cell. You do not want your prisoner to escape, so you order the sorcerers to work together on a containment spell. If done right, this creates a magical aura around the prisoner that will prevent him from escaping.</p>

<p>In order for the containment spell to work, all Sorcerers need to channel a certain fraction of their maximum power into the spell such that two things hold:</p>

<ul>
	<li>The spell needs to be perfectly balanced: the sum of the fractions of power over all Sorcerers must equal 1.</li>
	<li>The centre of the spell should coincide with the prisoner. This means that the average of the positions of Sorcerers, weighted by the fraction of power they are channeling, should be the location of the prisoner.</li>
</ul>

<p>Given the layout of the cell and the location of the prisoner, assign a fraction of power each Sorcerer should spend so that the containment spell works.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6f351cf9-2012-43fa-9da3-23ef0ee1cdbe/-/preview/" style="width: 241px; height: 145px;"></p>

<p>Figure K.1: The prison of sample 1. S<sub>1</sub>, S<sub>2</sub>, and S<sub>3</sub> are the Sorcerers, while P is the prisoner. Note that (1/3)S<sub>1</sub> + (1/3)S<sub>2</sub> + (1/3)S<sub>3</sub> = 1/3(0, 0) + 1/3(3, 0) + 1/3(0, 3) = (1, 1) = P.</p>

### 입력 

 <ul>
	<li>The first line contains 3 ≤ n ≤ 10, the number of Sorcerers in guard towers and two integers −10<sup>4</sup> ≤ x, y ≤ 10<sup>4</sup>, the coordinates of the prisoner.</li>
	<li>Then follow n lines, each of which contains two integers −10<sup>4</sup> ≤ x, y ≤ 10<sup>4</sup>, the coordinates of a Sorcerer.</li>
</ul>

<p>It is guaranteed that the locations are given in counter clockwise order and form a strictly convex polygon, i.e. no three points lie on a line. The prisoner is located strictly inside the polygon.</p>

### 출력 

 <ul>
	<li>Output n lines where the ith line contains a floating point number between 0 and 1 inclusive: the fraction of power that the ith Sorcerer should use for the containment spell to work.</li>
</ul>

<p>If there are multiple possible solutions, you may output any one of them.</p>

<p>Your answer will be correct if the sum of fractions differs at most 10<sup>−4</sup> from 1 and the weighted centre of your spell is within distance 10<sup>−4</sup> of the prisoner. Note that it may not be sufficient to print your answer itself with 10<sup>−4</sup> precision.</p>

