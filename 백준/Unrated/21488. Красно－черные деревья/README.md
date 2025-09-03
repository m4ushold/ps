# [Unrated] Красно-черные деревья - 21488 

[문제 링크](https://www.acmicpc.net/problem/21488) 

### 성능 요약

메모리: 201432 KB, 시간: 252 ms

### 분류

분류 없음

### 제출 일자

2025년 9월 2일 22:03:17

### 문제 설명

<p>Широкое распространение в стандартных библиотеках многих языков программирования получила реализация сбалансированных деревьев на основе так называемых <em>красно-черных деревьев</em>. В данной задаче вам предлагается посчитать количество красно-черных деревьев заданной формы.</p>

<p>Напомним, что двоичным деревом называется набор <em>вершин</em>, организованных в виде <em>дерева</em>. Каждая вершина имеет не более двух <em>детей</em>, один из которых называется <em>левым</em>, а другой --- <em>правым</em>. Как левый, так и правый ребенок, а также оба могут отсутствовать. </p>

<p>Если вершина <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44C TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>Y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$Y$</span></mjx-container> --- ребенок вершины <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$X$</span></mjx-container>, то говорят, что вершина <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$X$</span></mjx-container> является <em>родителем</em> вершины <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44C TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>Y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$Y$</span></mjx-container>. У каждой вершины дерева, кроме одной, есть ровно один родитель. Единственная вершина, не имеющая родителя, называется <em>корнем</em> дерева.</p>

<p>Соединим каждую вершину кроме корня с ее родителем. Заметим, что для каждой вершины существует ровно один путь, ведущий в нее от корня.</p>

<p>Двоичное дерево называется <em>красно-черным</em>, если каждая его вершина раскрашена в красный либо в черный цвет, причем выполняются следующие условия:</p>

<ol>
	<li>если вершина красная, то ее родитель --- черный;</li>
	<li>количество черных вершин на пути от корня до любой вершины, у которой отсутствует хотя бы один ребенок, одно и то же.</li>
</ol>

<p>Примеры двоичного дерева, вершины которого раскрашены в два цвета, приведены на следующем рисунке. </p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/0f0c6c1e-ad26-4581-8719-a17a48076384/-/preview/" style="width: 144px; height: 108px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/126f42ce-7f09-4014-98ae-0ba68bd9fe22/-/preview/" style="width: 144px; height: 108px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/1d86ec5b-9275-4ddc-a87d-6b83b5c77f92/-/preview/" style="width: 143px; height: 108px;"></td>
		</tr>
		<tr>
			<td>(а)</td>
			<td>(б)</td>
			<td>(в)</td>
		</tr>
	</tbody>
</table>

<p>Если считать закрашенные вершины черными, а незакрашенные --- красными, то дерево на рисунке (а) является красно-черным деревом, а деревья на рисунках (б) и (в) --- нет. Для дерева на рисунке (б) нарушается первое свойство --- у красной вершины 5 родитель 2 также красный, а в дереве на рисунке (в) нарушается второе свойство --- на пути от корня до вершины 1 одна черная вершина, а, например, на пути от корня до вершины 3 --- две.</p>

<p>Для заданного двоичного дерева подсчитайте число способов раскрасить его вершины в черный и красный цвет так, чтобы оно стало красно-черным деревом.</p>

### 입력 

 <p>Первая строка входного файла содержит число <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> --- количество вершин в дереве (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><mn>1000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le n \le 1000$</span></mjx-container>).</p>

<p>Пусть вершины дерева пронумерованы числами от <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> до <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>. Следующие <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> строк содержат по два числа --- для каждой вершины заданы номера ее левого и правого ребенка. Если один из детей отсутствует, то вместо его номера записан ноль. Гарантируется, что входные данные корректны, то есть набор чисел во входном файле действительно задает двоичное дерево.</p>

### 출력 

 <p>Выведите в выходной файл одно число --- количество способов раскрасить вершины заданного во входном файле двоичного дерева в красный и черный цвета так, чтобы оно стало красно-черным деревом.</p>

