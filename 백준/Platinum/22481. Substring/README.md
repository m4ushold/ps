# [Platinum III] Substring - 22481 

[문제 링크](https://www.acmicpc.net/problem/22481) 

### 성능 요약

메모리: 24588 KB, 시간: 68 ms

### 분류

수학, 문자열, 정수론, 집합과 맵, 해싱, 라빈–카프

### 제출 일자

2026년 3월 24일 16:31:32

### 문제 설명

<p>長さnの文字列s=s<sub>1</sub>,s<sub>2</sub>,…,s<sub>n</sub>およびm個のクエリが与えられる。 各クエリq<sub>k</sub> (1 ≤ k ≤ m)は、"L++", "L--", "R++", "R--"の4種類のいずれかであり、 k番目のクエリq<sub>k</sub>に対してl[k]とr[k]を以下で定義する。</p>

<ul>
	<li>
	<p>L++：l[k]=l[k-1]+1,r[k]=r[k-1]</p>
	</li>
	<li>
	<p>L--：l[k]=l[k-1]-1,r[k]=r[k-1]</p>
	</li>
	<li>
	<p>R++：l[k]=l[k-1],r[k]=r[k-1]+1</p>
	</li>
	<li>
	<p>R--：l[k]=l[k-1],r[k]=r[k-1]-1</p>
	</li>
</ul>

<p>但し、l[0]=r[0]=1である。</p>

<p>この時、m個の部分文字列 s<sub>l[k]</sub>, s<sub>l[k]+1</sub>, …, s<sub>r[k]-1</sub>, s<sub>r[k]</sub> (1 ≤ k ≤ m) について、何種類の文字列が作られるかを答えよ。</p>

### 입력 

 <p>入力は以下の形式で与えられる</p>

<pre>n m
s
q<sub>1</sub>
q<sub>2</sub>
…
q<sub>m</sub>
</pre>

### 출력 

 <p>問題の解を1行に出力せよ</p>

