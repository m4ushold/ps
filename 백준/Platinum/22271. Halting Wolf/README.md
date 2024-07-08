# [Platinum III] Halting Wolf - 22271 

[문제 링크](https://www.acmicpc.net/problem/22271) 

### 성능 요약

메모리: 2260 KB, 시간: 0 ms

### 분류

최대 유량

### 제출 일자

2024년 7월 8일 16:13:09

### 문제 설명

<p>Senoof loves programming languages, and the only thing he loves more than using them is creating new ones. His latest invention is the Wolf Programming Language, a very simple language consisting of only two types of instructions. They are numbered consecutively and written one under the other to make a program. Execution starts at instruction 1 and continues until the program gets stuck.</p>

<p>The two types of instructions are:</p>

<ul>
	<li>“K L<sub>1</sub> L<sub>2</sub> · · · L<sub>K</sub>” is a finite jump. Each value L<sub>i</sub> is an instruction number in the program, while K indicates how many of them are specified. When a finite jump is executed, one of the values L<sub>i</sub> is chosen, and the execution continues with instruction L<sub>i</sub>. But that’s not all! The program changes the finite jump instruction so as to consume the chosen value. If a program executes a finite jump without available values, it gets stuck and halts.</li>
	<li>“<code>*</code> L” is an infinite jump. When it’s executed, the program continues with instruction L, leaving the infinite jump instruction unmodified.</li>
</ul>

<p>I know, Senoof is crazy, but it’s not that difficult. The picture below shows an example, where current instruction is indicated with a <code>▷</code> sign, and a consumed value is denoted with a <code>⊔</code> sign. The program in (a) starts execution at instruction 1, which is a finite jump. Suppose that the second value is chosen, that is, execution continues with instruction 2 and this value is consumed in instruction 1, which yields the situation shown in (b). Since instruction 2 is an infinite jump to instruction 3, execution continues with this instruction, without consuming any value from instruction 2. Now imagine that from instruction 3 execution jumps to instruction 4, then to instruction 1, and then again to instruction 1, consuming the corresponding values. The situation at this point is shown in (c). As you can see the program gets stuck and halts, because there are no available values for jumping.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td>
			<pre>▷ 1: 2 1 2  
  2: * 3    
  3: 3 4 3 4
  4: 2 1 1  
</pre>
			</td>
			<td>
			<pre>  1: 2 1 ⊔  
▷ 2: * 3    
  3: 3 4 3 4
  4: 2 1 1  
</pre>
			</td>
			<td>
			<pre>▷ 1: 2 ⊔ ⊔  
  2: * 3    
  3: 3 ⊔ 3 4
  4: 2 ⊔ 1  
</pre>
			</td>
		</tr>
		<tr>
			<td>(a)</td>
			<td>(b)</td>
			<td>(c)</td>
		</tr>
	</tbody>
</table>

<p>After some playing around, Senoof noticed that programs written in Wolf may run forever, which does not imply that a given instruction can be executed infinitely many times. He kindly just sent us the following example of a program that may run forever, although instruction 1 can be executed at most twice.</p>

<pre style="text-align: center;">  1: 2 1 2  
  2: * 4    
  3: 3 4 3 4
  4: * 2    
</pre>

<p>Given a program written in Wolf, you must determine the maximum number of times that instruction 1 can be executed.</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 100), the number of instructions the program has. Each of the next N lines describes an instruction. A finite jump is represented with a non-negative integer K followed by K integers L<sub>1</sub>, L<sub>2</sub>, . . . , L<sub>K</sub> (1 ≤ L<sub>i</sub> ≤ N for i = 1, 2, . . . , K). On the other hand, an infinite jump is described with the character “<code>*</code>” (asterisk) followed by an integer L (1 ≤ L ≤ N). It is guaranteed that the total amount of instructions mentioned in the finite jumps is at most 10<sup>4</sup>.</p>

### 출력 

 <p>Output a single line with an integer indicating the maximum number of times instruction 1 can be executed, or the character “<code>*</code>” (asterisk) if instruction 1 can be executed infinitely many times.</p>

