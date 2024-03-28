# [Diamond V] Emission Spectrum - 13870 

[문제 링크](https://www.acmicpc.net/problem/13870) 

### 성능 요약

메모리: 120420 KB, 시간: 456 ms

### 분류

자료 구조, 퍼시스턴트 세그먼트 트리, 세그먼트 트리, 제곱근 분할법

### 제출 일자

2024년 3월 28일 21:11:02

### 문제 설명

<p>Scientists at the Interstellar Consortium of Planets and Constellations (ICPC) are studying the composition of many celestial objects by analyzing their emission spectrum. The emission spectrum of a celestial object is the spectrum of frequencies of electromagnetic radiation emitted due to its atomic energy transitions, along with the intensity of the emitted radiation. In other words, it corresponds to the intensity of each color for the light radiated by the object.</p>

<p>According to the postulates of quantum mechanics, the emission spectrum of a celestial object is always discrete. Therefore, the ICPC can store the emission spectrum of an object as a sequence of integers where each position in the sequence corresponds to the intensity of a specific wavelength. In this representation of the spectrum, larger numbers correspond to higher emitted intensities, and contiguous positions in the sequence correspond to contiguous wavelengths in the spectrum.</p>

<p>The emission spectrum of a celestial object is the result of very complex physical processes, and may thus vary through its lifetime. Notably, due to complex atomic reactions not yet fully understood, the intensity of two contiguous wavelengths can be swapped at a given time.</p>

<p>The ICPC is studying very closely the emission spectrum of some celestial object at particular wavelengths. However, scientists are having trouble obtaining useful data from their observations. Particularly, given a range of wavelengths and an integer K, they are interested in knowing the intensity of the wavelength which has the K-th smallest intensity in that range. Given a list of observational events mixing information requested by the scientists and wavelength intensity swaps in the spectrum, your task is to help the scientists by answering their queries.</p>

### 입력 

 <p>The first line contains two integers N and Q, representing the number of measured wavelengths and the number of events, respectively (1 ≤ N, Q ≤ 10<sup>5</sup> ). The second line contains N integers I<sub>1</sub>, I<sub>2</sub>, . . . , I<sub>N</sub> , representing I<sub>i</sub> the initial intensity of the i-th wavelength (0 ≤ I<sub>i</sub> ≤ 10<sup>9 </sup>for i = 1, 2, . . . , N). Each of the following Q lines corresponds to an event, and starts with a character representing the event type. If the event corresponds to a query from the ICPC scientists, the character is a ‘Q’; if it corresponds to an atomic swap reaction it is an ‘S’. Query events have three integers A, B and K after the ‘Q’ character, representing that the scientists are interested in the K-th smallest intensity in the range from A to B, inclusive (1 ≤ A ≤ B ≤ N and 1 ≤ K ≤ B − A + 1). Intensity swapping events have a single integer W after the ‘S’ character, representing that the intensities for wavelengths at positions W and W + 1 in the spectrum are swapped (1 ≤ W ≤ N − 1).</p>

### 출력 

 <p>Output one line for each query event in the input, containing a single integer number representing the intensity of the wavelength with the K-th smallest intensity in the range of the spectrum from A to B, inclusive (where A, B and K are the parameters specified in the corresponding query). Queries should be answered in the same order in which they appear in the input.</p>

