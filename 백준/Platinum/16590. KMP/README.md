# [Platinum IV] KMP - 16590 

[문제 링크](https://www.acmicpc.net/problem/16590) 

### 성능 요약

메모리: 4112 KB, 시간: 92 ms

### 분류

이분 매칭, 최대 유량

### 제출 일자

2024년 2월 19일 12:45:02

### 문제 설명

<p>KMP is a string algorithm that searches for occurrences of a string as substrings on another string. The name of the algorithm comes from the first character of the last names of the authors, namely Donald Knuth, James Hiram Morris, and Vaughan Pratt.</p>

<p>This problem has nothing to do with the algorithm, rather this problem is about the naming itself. There are N computer scientists in this world numbered from 1 to N. The i<sup>th</sup> computer scientist has a name A<sub>i</sub>. A name consists of one or more word, separated by a single space. A word consists of one or more characters. The first character is an uppercase alphabetical character (A-Z), while the rest of the characters are lowercase alphabetical characters (a-z).</p>

<p>There are Q queries, each consists of a string S of uppercase alphabetical characters. You are wondering whether an algorithm S can be authored by a subset of these N computer scientists. Let say Donald Knuth, James Hiram Morris, and Vaughan Pratt invent another algorithm. The first characters of any word in each computer scientist’s name are {D, K} in Donald Knuth, {J, H, M} in James Hiram Morris, and {V, P} in Vaughan Pratt. Then the algorithm can be named by taking exactly one of those first characters from each name (in the subset of the N computer scientists), e.g., DJV, DHP, KHV, KMP, KJP, etc. Note that the order does not matter, so algorithm names like PKH or VHK are also valid. However, KKMP or LHO are not valid in this example.</p>

<p>More formally, you are wondering whether there is a sequence of integers X<sub>1</sub>, X<sub>2</sub>, · · · , X<sub>|S|</sub> such that:</p>

<ul>
	<li>1 ≤ X<sub>1</sub>, X<sub>2</sub>, · · · , X<sub>|S|</sub> ≤ N</li>
	<li>X<sub>i</sub> ≠ X<sub>j</sub> for i ≠ j</li>
	<li>One of the word in A<sub>X<sub>i</sub></sub> starts with the character S<sub>i</sub></li>
</ul>

### 입력 

 <p>Input begins with two integers: N Q (1 ≤ N ≤ 50; 1 ≤ Q ≤ 1000) representing the number of computer scientists and the number of queries, respectively. The next line contains N strings: A<sub>i</sub> representing the name of the i<sup>th</sup> computer scientist. It is guaranteed that the sum of the length of all A<sub>i</sub> is not more than 10<sup>6</sup>. The next Q lines contains a string S representing the query which you should answer. It is guaranteed that the sum of the length of all S is not more than 10<sup>6</sup>. It is also guaranteed that Ai and S satisfy the format given in the problem statement.</p>

### 출력 

 <p>For each query, output “YES” in a line if an algorithm of name S can be authored by a subset of the N computer scientists; otherwise, output “NO”.</p>

