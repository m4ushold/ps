# [Gold III] Find my Family - 17787 

[문제 링크](https://www.acmicpc.net/problem/17787) 

### 성능 요약

메모리: 18344 KB, 시간: 132 ms

### 분류

이분 탐색, 자료 구조, 트리를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2025년 9월 29일 23:39:14

### 문제 설명

<p>You are looking for a particular family photo with you and your favorite relatives Alice and Bob. Each family photo contains a line-up of n people. On the photo you’re looking for, you remember that Alice, who is taller than you, was somewhere on your left from the perspective of the photographer. Also, Bob who is taller than both you and Alice, was standing somewhere on your right.</p>

<p>Since you have a large number of family photos, you want to use your computer to assist in finding the photo. Many of the photos are quite blurry, so facial recognition has proven ineffective. Luckily, the Batch Apex Photo Classifier, which detects each person in a photo and outputs the sequence of their (distinct) heights in pixels, has produced excellent results. Given this sequence of heights for k photos, determine which of these photos could potentially be the photo you’re looking for.</p>

### 입력 

 <ul>
	<li>The first line contains 1 ≤ k ≤ 1000, the number of photos you have to process.</li>
	<li>Then follow two lines for each photo.
	<ul>
		<li>The first line contains a single integer 3 ≤ n ≤ 3 · 10<sup>5</sup>, the number of people on this photo.</li>
		<li>The second line contains n distinct integers 1 ≤ h<sub>1</sub>, . . . , h<sub>n</sub> ≤ 10<sup>9</sup>, the heights of the people in the photo, from left to right.</li>
	</ul>
	</li>
</ul>

<p>It is guaranteed that the total number of people in all photos is at most 3 · 10<sup>5</sup>.</p>

### 출력 

 <ul>
	<li>On the first line, output the number of photos k that need further investigation.</li>
	<li>Then print k lines each containing a single integer 1 ≤ a<sub>i</sub> ≤ n, the sorted indices of the photos you need to look at.</li>
</ul>

