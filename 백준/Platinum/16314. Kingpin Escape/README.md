# [Platinum I] Kingpin Escape - 16314 

[문제 링크](https://www.acmicpc.net/problem/16314) 

### 성능 요약

메모리: 9756 KB, 시간: 44 ms

### 분류

해 구성하기, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2024년 4월 12일 01:38:35

### 문제 설명

<p>You are the kingpin of a large network of criminal hackers. Legend has it there has never been a richer criminal than you. Not just because you are the smartest, but also because you are the stingiest.</p>

<p>The police have been after you for years, but they have never been able to catch you thanks to your great set of escape routes. Whenever they want to catch you in one of your many hideouts, you quickly get away through your network of tunnels, back-alleys and speakeasies. Your routes are set up so that from every hideout you have in the city you can get to any other hideout by following only your secret passageways. Furthermore, because you are such a penny-pincher, your network is the smallest possible: from every hideout to every other hideout there is precisely one route through the network, no more and no fewer.</p>

<p>Yesterday, your mole in the police force has informed you of an unfortunate fact: the police are on to you! They have gotten wind of your secret network, and will attempt to catch you. They are planning to block some of your escape routes, and catch you in the act. They will start blocking your secret passageways one by one, until you have nowhere left to go.</p>

<p>Fortunately, your headquarters are absolutely safe. If you can just get there, you are always fine. Furthermore, your mole in the police force can inform you immediately as soon as the police start blocking passageways, so that they only have time to block one of them before you get notified. If you get back to your headquarters before they block any more routes, you’re safe.</p>

<p>You want to add some passageways to the network so that whenever at most one of them is blocked, you can still get to your headquarters from any other hideout. Since the news has not changed your frugality, you want to extend your network as cheaply as possible. Can you figure out the least number of passageways you need to add, and which ones you need?</p>

### 입력 

 <ul>
	<li>The input starts with two integers 2 ≤ n ≤ 10<sup>5</sup>, the number of hideouts in the network, and 0 ≤ h < n, the location of your headquarters.</li>
	<li>Then follow n − 1 lines, each with two integers 0 ≤ a, b < n, signifying that there is an escape route between location a and location b.</li>
</ul>

### 출력 

 <p>The output consists of:</p>

<ul>
	<li>An integer m, the least number of escape routes you need to add to make the network safe again.</li>
	<li>Then, m lines with two integers 0 ≤ a, b < n each, the hideouts between which one of the escape routes has to be added.</li>
</ul>

