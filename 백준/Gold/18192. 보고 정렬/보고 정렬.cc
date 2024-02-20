#include "bogoSort.h"
#include <bits/stdc++.h>
using namespace std;

void sort_array(int N) {
    vector<int> v=copy_array();
    int n=N, cnt=0;
	while(1){
		int s=-1, e;
		for(int i=0;i<n;i++) if(v[i]!=i) { s=i; break; }
		if(s==-1) break;
		while(v[s]!=s){
			for(int i=s;i<n;i++) if(v[i]==s) { e=i; break; }
			shuffle_array(s, e);
			v=copy_array();
            ++cnt;
		}
	}
}