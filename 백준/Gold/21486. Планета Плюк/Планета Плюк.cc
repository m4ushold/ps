#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

pll st,ed;
vector<ll> ans;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> st.first >> st.second >> ed.first >> ed.second;
    while(st.second < ed.second){
        st.first++;
        st.second++;
        ans.push_back(1);
    }
    while(abs(st.second) < abs(ed.second)){
        st.first++;
        st.second++;
        ans.push_back(1);
    }
    if(st.second > ed.second){
        st.first = -st.first;
        st.second = -st.second;
        ans.push_back(-1);
    }
    while(st.second < ed.second){
        st.first++;
        st.second++;
        ans.push_back(1);
    }
    while(st.first > ed.first){
        st.first -= 2;
        ans.push_back(-2);
    }
    while(st.first < ed.first){
        st.first += 2;
        ans.push_back(2);
    }
    for(ll i : ans){
        if(i == 1){
            cout << "-A\n+B\n";
        }
        else if(i == 2){
            cout << "+A\n+A\n+B\n+B\n";
        }
        else if(i == -2){
            cout << "+B\n+B\n+A\n+A\n";
        }
        else if(i == -1){
            cout << "+A\n+A\n";
        }
    }
}