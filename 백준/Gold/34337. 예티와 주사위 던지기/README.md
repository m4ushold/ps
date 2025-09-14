# [Gold V] 예티와 주사위 던지기 - 34337 

[문제 링크](https://www.acmicpc.net/problem/34337) 

### 성능 요약

메모리: 2180 KB, 시간: 4 ms

### 분류

수학, 브루트포스 알고리즘, 조합론, 백트래킹, 확률론

### 제출 일자

2025년 9월 14일 11:44:29

### 문제 설명

<p>올해 넥슨은 대학생들을 위한 새로운 대회 <b>코드배틀</b>을 런칭했다. 코드배틀은 주어진 게임 환경에서 승리할 수 있는 AI 코드를 개발해 서로 대결하는 대회이다. 예티는 1회 예선 문제인 <strong>요트 옥션(Yacht Auction)</strong>의 좋은 전략을 연구하기 위해 직접 요트(Yacht) 게임을 플레이해보기로 했다.</p>

<p>요트의 규칙은 다음과 같다:</p>

<ol>
	<li>주사위 5개를 던진다.</li>
	<li>원하는 주사위는 남겨두고, 나머지는 다시 던질 수 있다. 이를 재던지기라고 부른다.
	<ul>
		<li>이 재던지기는 한라운드에 최대 2번까지 가능하다.</li>
		<li>앞서 남겨둔 주사위도 원하면 다시 던질 수 있다.</li>
	</ul>
	</li>
	<li>최종으로 나온 주사위 조합을 가지고, 아직 채우지 않은 족보 중 하나를 반드시 선택하여 해당 족보의 규칙에 따라 점수를 기록한다.
	<ul>
		<li>족보란, 주사위 5개로 만든 조합을 점수로 환산하는 규칙들의 집합을 말한다.</li>
	</ul>
	</li>
</ol>

<p>예티는 이미 여러 족보를 채워 두었고, 이번 라운드에서 선택할 수 있는 남은 족보는 다음과 같다:</p>

<ul>
	<li><code>Ones</code>: 주사위 중 눈이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>인 주사위들의 눈의 합</li>
	<li><code>Twos</code>: 주사위 중 눈이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container>인 주사위들의 눈의 합</li>
	<li><code>Threes</code>: 주사위 중 눈이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3$</span></mjx-container>인 주사위들의 눈의 합</li>
	<li><code>Fours</code>: 주사위 중 눈이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4$</span></mjx-container>인 주사위들의 눈의 합</li>
	<li><code>Fives</code>: 주사위 중 눈이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5$</span></mjx-container>인 주사위들의 눈의 합</li>
	<li><code>Sixes</code>: 주사위 중 눈이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>6</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$6$</span></mjx-container>인 주사위들의 눈의 합</li>
	<li><code>Yacht</code>: 주사위 눈이 모두 같을 경우, 고정 50점</li>
</ul>

<p>현재 예티는 주사위를 던지고 재던지기를 이미 한 번 사용한 상태에서, 남은 한 번의 기회를 어떻게 활용할지 고민 중이다. 재던지기를 사용하지 않는 선택도 가능하다. 예티가 이번 라운드에서 얻을 수 있는 점수의 기댓값을 최대화할 수 있도록 전략을 세워주자.</p>

### 입력 

 <p>첫째 줄에 현재 주사위 눈의 조합을 뜻하는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>6</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$6$</span></mjx-container> 이하의 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5$</span></mjx-container>개가 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>첫째 줄에 예티가 이번 라운드에 얻을 수 있는 점수 기댓값의 최댓값에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>6</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$6^5$</span></mjx-container>를 곱한 값을 출력한다.</p>

