# [Platinum III] Jaś Robaczek - 8812 

[문제 링크](https://www.acmicpc.net/problem/8812) 

### 성능 요약

메모리: 77444 KB, 시간: 360 ms

### 분류

자료 구조, 트리, 오프라인 쿼리, 최소 공통 조상, 희소 배열, 오일러 경로 테크닉

### 제출 일자

2025년 8월 1일 21:56:48

### 문제 설명

<p>Jaś jest robaczkiem i postanowił zamieszkać na drzewie. Drzewo, które wybrał jest bardzo młode - w momencie przeprowadzki Jasia ma tylko jeden wierzchołek ( oznaczony numerem 1 ). </p>

<p>Następnie zarówno drzewo jak i Jaś zajęli się swoimi sprawami. To znaczy:</p>

<ul>
	<li>Drzewo zaczęło rosnąć, regularnie wypuszczając nowe wierzchołki. Zapis "D <strong>x</strong>" oznacza, że w drzewie pojawił się nowy wierzchołek, przyłączony do wierzchołka <strong>x</strong> obecnego już wcześniej w drzewie ( w razie wątpliwości spójrz do przykładu i wyjaśnienia przykładu ).</li>
	<li>Jaś zaczął spacerować po drzewie, każdorazowo przechodząc z aktualnego wierzchołka do jednego z jego bezpośrednich sąsiadów. Zapis "J <strong>x</strong>" oznacza, że Jaś przesunął się o jeden wierzchołek w stronę wierzchołka <strong>x</strong> ( zwróć uwagę na to, że nie podajemy wierzchołka w którym Jaś de facto się znalazł, tylko ten, w którego stronę się poruszył ).</li>
</ul>

<p>Hektor obserwuje to wszystko i chciałby po każdym ruchu Jasia znać jego aktualną pozycję. Czy potrafisz mu pomóc?</p>

### 입력 

 <p>W pierwszej linii znajduje się jedna liczba naturalna <strong>Z</strong> ( 1 <= <strong>Z</strong> <= 10 ) oznaczająca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>W pierwszej linii zestawu znajduje się liczba naturalna <strong>N</strong> ( 1 <= <strong>N</strong> <= 10<sup>6</sup> ) oznaczająca liczbę wydarzeń.</p>

<p>W kolejnych <strong>N</strong> liniach podawane są opisy wydarzeń. Każdy z nich ma jedną z dwóch postaci o opisanym w treści znaczeniu:</p>

<ul>
	<li>"D <strong>x</strong>" ( 1 <= <strong>x </strong><= aktualna liczba wierzchołków w drzewie )</li>
	<li>"J <strong>x</strong>" ( 1 <= <strong>x</strong> <= aktualna liczba wierzchołków w drzewie )</li>
</ul>

<ul>
	<li>Jeśli w momencie podania opisu "J <strong>x</strong>" Jaś znajduje się już w wierzchołku <strong>x</strong>, to znaczy że w nim pozostaje ( taką, niezmienioną pozycję należy oczywiście również wypisać ).</li>
	<li>Kolejne, dołączane do drzewa wierzchołki numerowane są kolejnymi liczbami naturalnymi. Pierwszy dołączony wierzchołek otrzyma numer 2, kolejny 3, etc.</li>
</ul>

### 출력 

 <p>Dla każdego zestawu należy wypisać tyle linii, ile razy na wejściu pojawiło się wydarzenie "J <strong>x</strong>". Dla każdego takiego wydarzenia należy wypisać numer wierzchołka, w którym znalazł się Jaś.</p>

