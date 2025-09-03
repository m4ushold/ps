# [Gold IV] Головоломка - 21468 

[문제 링크](https://www.acmicpc.net/problem/21468) 

### 성능 요약

메모리: 2380 KB, 시간: 160 ms

### 분류

해 구성하기, 구현, 시뮬레이션

### 제출 일자

2025년 9월 3일 13:15:31

### 문제 설명

<p>Пете на день рождения подарили новую головоломку. Головоломка представляет собой цилиндр, состоящий из <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> круглых слоев, нанизанных на одну вертикальную ось. Каждый слой можно вращать независимо от других. Каждый слой разбит на <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> квадратиков, каждый из которых может быть либо черным, либо белым. В устойчивом состоянии квадратики соседних слоев находятся в точности друг под другом.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/bcdcadfe-015f-4f09-bea6-58fdc55c1331/-/preview/" style="width: 89px; height: 211px;"></p>

<p>Для задания конфигурации головоломки удобно рассмотреть ее развертку --- <<разрезать>> поверхность цилиндра вдоль вертикальной линии, проходящей по границам квадратиков, и обозначить черные клетки символом <<0>>, а белые --- символом <<1>>. Пусть, например, одна из возможных разверток головоломки, приведенной на рисунке, следующая (на рисунке видно только первые три столбца этой развертки):</p>

<pre style="text-align: center;">000110
001110
101000
001000
011111
011110
</pre>

<p>Задача решающего головоломку состоит в том, чтобы, поворачивая слои, добиться того, чтобы все вертикальные столбцы были различны. Например, головоломка приведенная выше, не решена, поскольку два из ее столбцов (четвертый и пятый на приведенной развертке) одинаковы. Если же повернуть нижний слой влево на один квадратик, развертка головоломки примет следующий вид:</p>

<pre style="text-align: center;">000110
001110
101000
001000
011111
111100
</pre>

<p>Теперь все столбцы различны и следовательно головоломка решена.</p>

<p>Для того, чтобы решать головоломку было интереснее, на ее раскраску наложено дополнительное условие: нельзя повернуть один из слоев головоломки меньше чем на полный оборот таким образом, что внешний вид головоломки останется тем же. Так, например, для <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi><mo>=</mo><mn>6</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n = 6$</span></mjx-container> слой с раскраской <<010101>> не разрешается, поскольку при его повороте на 2 квадратика внешний вид головоломки не меняется.</p>

<p>По заданной развертке головоломки выясните, можно ли ее решить, и если да, то приведите пример развертки решенной головоломки.</p>

### 입력 

 <p>Первая строка входного файла содержит число <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> --- количество слоев в головоломке и количество квадратиков в одном слое (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><mn>200</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le n \le 200$</span></mjx-container>). Следующие <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> строк содержат по <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> символов, каждый из которых равен 0 или 1 --- развертку головоломки.</p>

### 출력 

 <p>Если решить головоломку можно, на первой строке выходного файла выведите слово <<<code>Yes</code>>>. В этом случае следующие <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> строк должны содержать произвольную развертку решенной головоломки.</p>

<p>Если решить головоломку нельзя, выведите <<<code>No</code>>> на первой строке выходного файла.</p>

