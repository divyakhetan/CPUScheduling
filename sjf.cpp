#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class process{
public:
	int id,at,bt,ct;
};


bool operator<(const process& a, const process& b){
	return a.bt > b.bt;
}

bool compare(const process& a, const process& b){
	return a.at < b.at;
}

bool comp2(const process& a, const process& b){
	return a.ct < b.ct;
}

int main(){
	int n;
	//cout<<"Enter the number of processes: ";
	cin>>n;
	process p[n];
	//cout<<"Enter the arrival, burst time: ";
	for(int i = 0;i < n;i++){
		int x,y;
		cin>>x>>y;
		p[i].id = i;
		p[i].at = x;
		p[i].bt = y;
	}	
	bool vis[n];
	memset(vis, false, sizeof vis);
	priority_queue<process> pq;
	//sort based on arrival time
	sort(p, p+n, compare);
	pq.push(p[0]);
	int ct[n];
	int t = p[0].at;
	while(!pq.empty()){
		process p1 = pq.top();
		pq.pop();
		if(vis[p1.id]) continue;
		vis[p1.id] = true;
		t += p1.bt;		
		for(int i = 0;i < n;i++) if(p[i].id == p1.id) p[i].ct = t;
		for(int i = 0;i < n;i++){
			if(!vis[p[i].id] && p[i].at <= t) pq.push(p[i]);
		}
	}
	
	sort(p, p+n, comp2);
	
	cout<<"id\t\tat\t\tbt\t\tst\t\tct\t\twt\t\ttt\t\tntt\n";
	int twt = 0, tt = 0;
	for(int i = 0;i < n;i++){
		cout<<p[i].id+1<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ct-p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].ct-p[i].at-p[i].bt<<"\t\t"<<p[i].ct-p[i].at<<"\t\t"<<(p[i].ct-p[i].at) / (float) p[i].bt<<"\t\t"<<endl;
		twt += p[i].ct-p[i].at-p[i].bt;
		tt += p[i].ct-p[i].at;
	}
	float awt = twt / (float) n;
	float att = tt / (float) n;
	cout<<"Average turnaround time :"<<att<<endl;
	cout<<"Average waiting time :"<<awt<<endl;
	
}