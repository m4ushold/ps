# [Platinum IV] Balance - 4202 

[문제 링크](https://www.acmicpc.net/problem/4202) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

기하학, 다각형의 넓이

### 제출 일자

2024년 4월 11일 12:42:14

### 문제 설명

<p>A sailboat has many forces acting on it. This allows it to sail in many different directions, even if the wind is not blowing in the desired direction. In order for the boat to be easily controlled, however, certain forces must be balanced.</p>

<p>Suppose the wind is blowing from the north and the boat is facing west. Above the water, the blowing wind hits the sails, and because of the way that they are angled, pushes the boat to the southwest. The keel extends deep below the water. The water resistance on the keel creates a counterforce pushing the boat northward. Ideally, the northward force on the keel will counteract the southward component of the force on the sails, so that the boat will move to the west.</p>

<p>A problem can arise if the centre of the sails (called the Centre of Effort, or CE) is not directly above the centre of the keel (called the Centre of Lateral Resistance, or CLR). In general, the boat can pivot about the centre of the keel. If the sails are too far forward of the keel, the wind will push the bow (the front) of the boat southwards, and the boat will turn towards the south. If the sails are too far aft of (behind) the keel, the wind will push the stern (the back) southwards, and the boat will turn towards the north. Ideally, the sails and keel are balanced so that the boat sails in a straight line.</p>

<p>In this problem, you will examine a side view of the boat to determine whether the CE is above the CLR. The CE is defined as the centroid of the part of the boat above the waterline. The CLR is defined as the centroid of the part of the boat below the waterline. The centroid of a polygon is the unique point such that any line passing through it divides the polygon into two halves of equal area.</p>

### 입력 

 <p>The first line of input will contain a single integer n specifying the number of points along the outline of the side view of the boat. The following n lines will each contain two integers: the x and y coordinate of a point along the outline. The points will be given in order along the outline. The x axis (i.e. the line y = 0) represents the waterline. Assume that the boat faces in the direction of increasing x coordinates.</p>

### 출력 

 <p>If the CE is forward of the CLR, print the line:</p>

<pre>CE is forward of CLR by N units.</pre>

<p>If the CE is aft of (behind) the CLR, print the line:</p>

<pre>CE is aft of CLR by N units.</pre>

<p>In both cases, replace the N with the difference in the x coordinates of the CE and CLR to two decimal places. If the x coordinates of the CE and CLR are equal, print the line:</p>

<pre>Balanced.</pre>

