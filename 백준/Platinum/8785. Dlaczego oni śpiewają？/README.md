# [Platinum V] Dlaczego oni śpiewają? - 8785 

[문제 링크](https://www.acmicpc.net/problem/8785) 

### 성능 요약

메모리: 2156 KB, 시간: 4 ms

### 분류

자료 구조, 기하학, 분리 집합

### 제출 일자

2026년 2월 17일 12:50:46

### 문제 설명

<p>Czy wiecie, że wśród rozlicznych mocnych stron Hektora znajduje się także doskonały słuch muzyczny? Czasem jednak staje się to dla niego prawdziwym utrapieniem, gdyż czyni słuchanie fałszujących ludzi szczególnie nieprzyjemnym doświadczeniem.</p>

<p>Dzisiaj w szkole Hektora odbywa się casting do programów <em>Dlaczego oni śpiewają?</em>, oraz <em>Gwiazdy śpiewają pod lodem</em>. Dziedziniec przed szkołą wypełnił się oczekującymi na swoją kolej uczestnikami, z których każdy rozgrzewa się fałszując niemiłosiernie.</p>

<p>Czy da się przejść przez dziedziniec tak, aby nie usłyszeć żadnego z fałszujących uczestników?</p>

<p>Dziedziniec ma kształt prostokąta o wysokości <strong>N</strong> i szerokości <strong>M</strong>. Wyróżniamy na nim (<strong>N</strong>+1)*(<strong>M</strong>+1) punktów o współrzędnych całkowitych, z punktem (0,0) w lewym górnym rogu i punktem (<strong>N</strong>,<strong>M</strong>) w prawym dolnym rogu. </p>

<p>Na dziedzińcu stoi <strong>K</strong> fałszujących osób, każdą opisują współrzędne punktu <strong>P<sub>i</sub></strong>, w którym stoi, oraz zasięg fałszowania, to znaczy promień okręgu o środku w <strong>P<sub>i</sub></strong> w którym słychać daną osobę.</p>

<p>Fałszujące osoby stoją w punktach o współrzędnych całkowitych, ale Hektor (to w końcu jego szkoła i jego dziedziniec!) może poruszać się dowolną nie wychodzącą poza dziedzinieć ścieżką o rzeczywistych współrzędnych kolejnych punktów.</p>

<p>Sprawdź, czy istnieje ścieżka o współrzędnych rzeczywistych łącząca dowolny punkt na dolnej krawędzi dziedzińca (czyli punkt o współrzędnych (<strong>N</strong>,<strong>a</strong>) dla dowolnego rzeczywistego <strong>a</strong> z przedziału od 0 do <strong>M</strong>) z dowolnym punktem na górnej krawędzi (czyli punktem o współrzędnych (0,<strong>b</strong>) dla dowolnego rzeczywistego <strong>b</strong> z przedziału od 0 do <strong>M</strong>), która nie wychodzi poza obszar dziedzińca i nie przechodzi przez obszary fałszowania żadnej ze śpiewających osób. </p>

### 입력 

 <p>W pierwszej linii wejścia znajduje się jedna liczba naturalna <strong>Z</strong> ( 1 <= <strong>Z</strong> <= 10 ) oznaczająca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>W pierwszej linii opisu zestawu znajdują się trzy oddzielone spacjami, opisane w treści liczby całkowite <strong>N</strong>, <strong>M</strong> i <strong>K</strong> ( 1 <= <strong>N</strong>, <strong>M</strong> <= 1000, 1 <= <strong>K</strong> <= 1000 ). Następnie w <strong>K</strong> kolejnych liniach opisywane są kolejne fałszujące osoby. Każdą opisują trzy oddzielone spacjami liczby całkowite <strong>w<sub>i</sub></strong>, <strong>c<sub>i</sub></strong>, <strong>r<sub>i</sub></strong> ( 0 <= <strong>w<sub>i</sub></strong> <= <strong>N</strong>, 0 <= <strong>c<sub>i</sub></strong> <= <strong>M</strong>, 1 <= <strong>r<sub>i</sub></strong> <= 1000 ), gdzie (<strong>w<sub>i</sub></strong>,<strong>c<sub>i</sub></strong>) oznaczają współrzędne danej osoby, a <strong>r<sub>i</sub></strong> jej zasięg fałszowania.  </p>

### 출력 

 <p>Dla każdego zestawu testowego należy w osobnej linii wypisać "TAK", jeśli poszukiwana ścieżka istnieje i "NIE" w przeciwnym wypadku.</p>

