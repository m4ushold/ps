# [Gold V] Lola’s Schedule - 22275 

[문제 링크](https://www.acmicpc.net/problem/22275) 

### 성능 요약

메모리: 3004 KB, 시간: 12 ms

### 분류

브루트포스 알고리즘, 수학

### 제출 일자

2024년 7월 8일 16:12:34

### 문제 설명

<p>Lola is an energetic girl with many interests, making each day an ocean of possibilities for her, full of exciting activities she is more than willing to participate in. Unfortunately, many of the activities Lola participates in happen in closed spaces, and because of that her vitamin D levels are slightly below ideal. To help, a doctor prescribed a vitamin supplement that she must take daily every X minutes.</p>

<p>Lola wrote an app to keep track of her activities. The main feature of the app is the scheduling of activities. Each activity consists of a title and its start and end times. The app also allows creating one-off reminders, consisting simply of a title and the moment she should receive a single notification, and recurring reminders, consisting of a title, the time for the first notification, and how often the reminder should repeat. After buying the supplement, Lola wants to add a recurring reminder to the app, that repeats every X minutes, to make sure she will get notified whenever it is time to take the supplement. Ideally, she prefers not to have to take the supplement while participating in an activity. With such a busy schedule, she is having a hard time coming up with the ideal moment to start taking it.</p>

<p>Your task is to help Lola to choose the ideal time T after buying the supplement to take it for the first time. A time T is said to be ideal if it is at most <code>8</code> hours past the moment when Lola bought the supplement, the number of times when she needs to take the supplement which conflicts with her activities is minimum, and there’s no other time earlier than T that would result in the same number of conflicts.</p>

<p>For clarity purposes, suppose that Lola needs to take the supplement every <code>30</code> minutes, bought it a certain day at <code>10:00</code>, and has a single activity scheduled from <code>18:00</code> to <code>18:30</code> during that day. If she chooses to take the supplement for the first time immediately, she would take it at <code>10:00</code>, <code>10:30</code>, . . . , <code>17:30</code>, <code>18:00</code>, <code>18:30</code>, . . . . Thus, she’d have two conflicts with her activity (one at <code>18:00</code> and the other at <code>18:30</code>).</p>

<p>Although Lola cannot wait until her activity ends to take the supplement for the first time (because of the <code>8</code> hours limit), she can reduce the number of conflicts by waiting <code>7</code> hours and <code>59</code> minutes. In that way she would take the supplement at <code>17:59</code>, <code>18:29</code>, <code>18:59</code>, . . . , with a single conflict at <code>18:29</code>. Much better, isn’t it? However, this is not ideal, because there is an earlier time that also produces a single conflict, which is waiting <code>1</code> minute and taking the supplement for the first time at <code>10:01</code>, with a single conflict at <code>18:01</code>. As it’s not possible to completely avoid conflicts, the ideal time, in this case, is taking the supplement for the first time <code>1</code> minute after buying it.</p>

<p>You’ll be given a list of activities, exported from the app Lola wrote, containing information about all her activities starting after the time when she bought the supplement. Lola already did some preprocessing of the data and each activity is described by the number of minutes from the time she bought the supplement and its duration in minutes.</p>

### 입력 

 <p>The first line contains two integers N (1 ≤ N ≤ 10<sup>4</sup>) and X (1 ≤ X ≤ 720), indicating that Lola has N upcoming activities exported from her app, and that she must take the supplement every X minutes. Each of the following N lines describes an activity with two integers S and D (1 ≤ S, D ≤ 10<sup>5</sup>), representing that the activity starts S minutes after buying the supplement, and that its duration is D minutes. Activities do not overlap, that is, given any pair of different activities, one of them ends strictly before the other starts, or vice versa.</p>

### 출력 

 <p>Output a single line with two integers T and C, indicating respectively the ideal time for taking the supplement for the first time, expressed in minutes since buying the supplement, and the number of conflicts that taking the supplement at this time will lead to.</p>

