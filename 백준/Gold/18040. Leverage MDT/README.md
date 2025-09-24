# [Gold II] Leverage MDT - 18040 

[문제 링크](https://www.acmicpc.net/problem/18040) 

### 성능 요약

메모리: 7000 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 9월 24일 11:39:38

### 문제 설명

<p>The kingdom of Nlogonia is a very prosperous one. Its king, Constantourist, expanded the kingdom by conquering nearby towns. However, now that Constantourist’s life is coming to an end, his two sons, Javasar and Golangsar, need to decide the fate of the kingdom.</p>

<p>Instead of fighting an unnecessary war to choose the next king, the two sons are trying to negotiate an agreement so as to divide the kingdom’s jurisdiction into two. Nlogonia is a rectangle-shaped land having N kilometers in the North-South direction and M kilometers in the West-East direction. Thus, during the initial stage of negotiations the two sons were able to divide the land in N × M square parcels of one kilometer on each side, using divisory lines parallel to the kingdom’s border. The next step is to distribute the parcels between the two sons.</p>

<p>Before the negotiations can continue, Javasar needs to decide which parcels he wants to claim for himself. He has already categorized each parcel in either good or bad, according to soil quality. Javasar wants his jurisdiction to be recognized as the best in Nlogonia, and so he is planning to choose only parcels with good soil quality. Moreover, being a perfectionist, he decided that the parcels that he will claim need to form a square.</p>

<p>Javasar is worried that these requirements might make him get only a few amount of parcels. Luckily for him, during one of his adventures to Byteland, he found an ancient Magical Divine Tool (MDT) which, when active, is able to reverse the soil quality of the parcel Javasar is currently standing in. In other words, if active, the MDT turns a bad quality parcel into a good one, and vice versa.</p>

<p>With this handy tool, Javasar came up with the perfect plan! He will travel outside the kingdom, to the West of the parcel that is at the North-West corner, and then he will visit each parcel exactly once following the route that the picture below shows. Notice that Javasar will enter and leave Nlogonia several times. In this way he will avoid activating or deactivating the MDT when he is inside the kingdom, and then nobody will see him manipulating the tool. Although the MDT is magical and divine, it does not activate or deactivate by itself.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/58314e4b-3f3b-4dfc-8763-0155f9c74bdc/-/preview/" style="width: 257px; height: 137px;"></p>

<p>As Javasar’s main advisor, you must tell him the maximum number of parcels it is possible to obtain, meeting his requirements, if he optimally leverages the MDT.</p>

### 입력 

 <p>The first line contains two integers N and M (1 ≤ N, M ≤ 1000), indicating the length (in kilometers) of Nlogonia in the North-South and West-East directions, respectively. Each of the next N lines contains a string of M characters, where each character is either the uppercase letter “G” or the uppercase letter “B”, representing that the soil quality of a parcel is good or bad, respectively. The description of the kingdom’s parcels is made from North to South, and from West to East.</p>

### 출력 

 <p>Output a single line with an integer indicating the maximum number of parcels Javasar can obtain, whilst meeting his requirements, if he optimally leverages the MDT.</p>

