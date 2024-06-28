# [Platinum III] Breeding Bugs - 26012 

[문제 링크](https://www.acmicpc.net/problem/26012) 

### 성능 요약

메모리: 7520 KB, 시간: 160 ms

### 분류

이분 매칭, 수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 6월 28일 12:25:25

### 문제 설명

<p>This year is a good year for North America. 2022 is one of the few years where no brood of the periodical cicada is hatching and thus, no swarms will destroy the crops on the fields.</p>

<p>Those periodical cicadas have a somewhat strange property: They have highly synchronized life cycles, which means that almost all individuals in a local population emerge in the same year, resulting in periodical cicada plagues. Even odder is the fact that the periodicities of those life cycles appear to be prime, for example 13 or 17 years. The best theory for this so far is that a prime periodicity lets them avoid predators with shorter population cycles since a brood emergence of cicadas will rarely coincide with a predator's population boost. </p>

<p>But nobody likes cicada plagues, so this prime periodicity is now your problem. Your hope is that cicadas with non-prime periodicity will not be able to avoid predators anymore and that there will be fewer cicada plagues as a result. So, to prevent the next plague, you forge a plan to breed different cicada types to get a new type with non-prime periodicity. If you mate a cicada of a type with periodicity $a$ with another cicada of a type with periodicity $b$, you assume to get a cicada of a type with periodicity $a+b$. You have already captured $n$ cicadas to breed but you don't know which will mate. Therefore, you decided to set some cicadas free such that the remaining ones can mate this year in any way they want without producing a cicada of a type with prime periodicity. How many of your cicadas can you keep at most?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with a single integer $n$ ($1\leq n<750$), the number of cicadas.</li>
	<li>One line with $n$ integers $p_1, \ldots, p_n$ ($1\leq p_i<10^7$), where $p_i$ denotes the periodicity of the $i$th cicada.</li>
</ul>

### 출력 

 <p>Output a single integer, the maximum number of cicadas you can keep.</p>

