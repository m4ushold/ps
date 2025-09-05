# [Platinum V] KALLAX Construction - 16303 

[문제 링크](https://www.acmicpc.net/problem/16303) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 9월 5일 19:17:09

### 문제 설명

<p>You are the owner of IKEA, and you need to order a large number of bolts B. There is a single bolt manufacturer, but there are multiple companies reselling these bolts in packs (e.g. boxes, pallets). These companies form a directed chain, where each company buys packs from the previous company and combines these into new packs (with, of course, the logo of the company displayed brilliantly).</p>

<p>At first glance, it might seem that these intermediate companies offer no advantage, as they just repack the packs of the previous company into larger packs. However, every company has their own target audience, so they want to sell packs with a specific amount of bolts. Because every company only uses the packs of the previous company, it might not be possible to create a pack that has the exact number of bolts specified. Instead, if a company wants to create a pack which is guaranteed to contain X bolts, it will bundle various packs from the previous company where the displayed amount of bolts on these packs sums to no less than X. If there are multiple such combinations it will pick any from those whose displayed sum is minimal. For a better understanding, see the example below. Note that individual companies have no knowledge of the supply chain other than the pack sizes the previous company offers them.</p>

<p>You realise you can take advantage of this: when a company specifies that a pack has a certain number of bolts, it might in practice contain more! Therefore you start a quest of figuring out which pack has the lowest advertised amount, while still containing at least the number of bolts you need. Thanks to your business relations, you can freely choose the company to buy a pack from, including the manufacturer.</p>

### 입력 

 <ul>
	<li>The first line of the input contains an integer 1 ≤ B ≤ 10<sup>3</sup> giving the number of bolts that you need.</li>
	<li>The second line of the input contains an integer 1 ≤ k ≤ 10 giving the number of companies.</li>
	<li>The next k lines each describe a company. Each line consists of the integers l<sub>i</sub> , n<sub>1</sub>, n<sub>2</sub>, . . . , n<sub>l<sub>i</sub></sub> meaning that the company i produces 1 ≤ l<sub>i</sub> ≤ 10 types of packages of sizes 0 < n<sub>1</sub> < n<sub>2</sub> < . . . < n<sub>l<sub>i</sub></sub> ≤ 10<sup>3</sup>, respectively.</li>
</ul>

### 출력 

 <ul>
	<li>A single integer giving the smallest size of a package that you can buy which contains at least B bolts no matter how the companies build their packages, or <code>impossible</code> if this cannot be achieved.</li>
</ul>

