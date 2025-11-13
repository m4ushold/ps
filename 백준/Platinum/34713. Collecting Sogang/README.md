# [Platinum III] Collecting Sogang - 34713 

[문제 링크](https://www.acmicpc.net/problem/34713) 

### 성능 요약

메모리: 10876 KB, 시간: 116 ms

### 분류

그리디 알고리즘, 이분 탐색, 매개 변수 탐색

### 제출 일자

2025년 11월 13일 15:12:06

### 문제 설명

<p>알파벳 소문자로 이루어진 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다. 이 문자열에서 <span style="color:#c0392b;"><code>s</code></span>, <span style="color:#c0392b;"><code>o</code></span>, <span style="color:#c0392b;"><code>g</code></span>, <span style="color:#c0392b;"><code>a</code></span>, <span style="color:#c0392b;"><code>n</code></span>, <span style="color:#c0392b;"><code>g</code></span> 여섯 개의 문자를 문자열의 <strong>앞에서부터 순서대로</strong> 추출하여 <span style="color:#c0392b;"><code>sogang</code></span>이라는 단어를 만들 수 있다. 이때, 이 여섯 개의 문자가 문자열에서 <strong>연속할 필요는 없다.</strong></p>

<p><span style="color:#c0392b;"><code>sogang</code></span>단어를 완성할 때마다 상품 하나를 받는다. 사용된 문자는 문자열에서 제거되며, 제거된 자리의 뒷부분에 있는 문자들은 앞으로 당겨진다. 이 과정을 여러 번 반복할 때, 받을 수 있는 상품의 최대 개수를 구하시오.</p>

### 입력 

 <p>첫 번째 줄에 문자열의 길이에 해당하는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le N \le 100\,000$</span></mjx-container>)</p>

<p>두 번째 줄에는 알파벳 소문자로 구성된 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>인 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다.</p>

### 출력 

 <p>위의 규칙에 따라 단어를 만들 때, 받을 수 있는 상품의 최대 개수를 출력하여라.</p>

