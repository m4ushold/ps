# [Platinum III] Pack the Slopes - 27819 

[문제 링크](https://www.acmicpc.net/problem/27819) 

### 성능 요약

메모리: 34420 KB, 시간: 3212 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그리디 알고리즘, Heavy-light 분할, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 작은 집합에서 큰 집합으로 합치는 테크닉, 정렬, 트리

### 제출 일자

2024년 10월 4일 23:26:22

### 문제 설명

<p>You are trying to organize a group of skiers. The skiers are taking a trip to a large mountain, which has been rented for the day.</p>

<p>There are <b>N</b> rest points numbered from 1 to <b>N</b> on the mountain, and they are connected by <b>N</b>-1 slopes. Each slope starts at some rest point and goes directly to another rest point, with no intermediate slopes or rest points. A slope can be traversed in only one direction.</p>

<p>Each skier starts at the summit rest point and traverses a slope to reach another rest point. From there, the skier can traverse another slope to reach another rest point, and so on. Once a skier reaches their destination rest point, they stop skiing for the day and head to the ski lodge for hot cocoa. The destination rest point cannot be the summit rest point. However, notice that a skier's destination rest point can be the start of zero or more slopes; that is, a skier does not necessarily have to keep using available slopes until there are none available: they can always walk carefully down the rest of the mountain! For all rest points, there is exactly one sequence of slopes that a skier can use to reach it from the summit rest point.</p>

<p>Each slope can accommodate only a certain total number of skiers in a day, after which the snow gets too choppy to ski. In addition, the ski resort can charge or reward each skier for each slope that they ski on. Each slope may have a different price, and each skier must pay the price for each slope they ski on. A slope's price can be positive, zero, or even negative; a negative price represents a bounty awarded for testing that slope. As the organizer, you pay all the slope prices and collect all the bounties on behalf of your group of skiers. Notice that if multiple skiers use the same slope, you pay that slope's price or collect the slope's bounty multiple times. The sum of all costs you pay minus the sum of all bounties you collect is the total expense for the trip. The expense can be positive, zero, or negative. A negative expense means that you actually made money on the trip!</p>

<p>As the organizer, you want to figure out the maximum number of skiers that you can put on the mountain. Also, you would like to figure out the minimum possible expense for a trip with that maximum number of skiers.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. The first line of a test case contains a single integer <b>N</b>: the number of rest points on the mountain.</p>

<p>Each of the final <b>N</b>-1 lines of a test case describes a slope via four integers <b>U<sub>i</sub></b>, <b>V<sub>i</sub></b>, <b>S<sub>i</sub></b>, and <b>C<sub>i</sub></b>. These are the slope's starting rest point, the slope's ending rest point, the maximum number of skiers the slope can accommodate, and the slope's price per skier, respectively.</p>

<p>The summit rest point where the skiers start from is always numbered 1.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y z</code>, where <code>x</code> is the test case number (starting from 1), <code>y</code> is the maximum number of skiers, and <code>z</code> is the minimum expense for having <code>y</code> skiers ski at least one slope each.</p>

