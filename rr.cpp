#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct process{
  int at, bt, ct, id, st;
}process;

bool comp(process a, process b){
  return a.at < b.at;
}

bool comp2(const process& a, const process& b){
	return a.ct < b.ct;
}

int main() {
  int n;
  cin>>n;
  process p[n];
  for(int i = 0;i < n;i++){
    p[i].id = i+1;
    int a,b;
    cin>>a>>b;
    p[i].at = a;
    p[i].bt = b;
    p[i].ct = 100000;
  }
  int tq;
  cin>>tq;
  sort(p, p+n, comp);
  int t = p[0].at;
  bool vis[n+1];
  memset(vis, false, sizeof vis);
  bool inq[n+1];
  memset(inq, false, sizeof inq);
  queue<process> q;
  q.push(p[0]);
  vis[p[0].id] = true;
  inq[p[0].id] = true;
  p[0].st = p[0].at;
  while(!q.empty()){
    process p1 = q.front();
    q.pop();
    inq[p1.id] = false; 
    if(!vis[p1.id]){
        vis[p1.id] = true;
        p1.st = t;
        for(int i = 0;i < n;i++){
        if(p[i].id == p1.id) p[i].st = t;
      }
        
    }
    
    if(p1.bt == 0) continue;
    //cout << p1.id << " ";
    t += min(p1.bt, tq);
    p1.bt -= min(p1.bt, tq);
    
    
    for(int i = 0;i < n;i++){
      if(!vis[p[i].id] && p[i].at <= t && p[i].bt != 0 && !inq[p[i].id]){
        q.push(p[i]);
        inq[p[i].id] = true;
      }
    }
    if(p1.bt == 0){
      for(int i = 0;i < n;i++){
        if(p[i].id == p1.id) p[i].ct = t;
      }
    }
    else {q.push(p1); inq[p1.id] = true;}
    
    //for(int i = 0; i < n; i++) cout << p[i].bt << " ";
    //cout << endl;
//     queue<process> q1;
//     int l = q.size();
//   for(int i = 0; i < l; i++){
//       process pt = q.front();
//       q.pop();
//       q1.push(pt);
//       q.push(pt);
//   }
//   while (!q1.empty())
//   {
      
//     cout << q1.front().id << " ";
//     q1.pop();
//   }
//   cout << endl;
   
  }
  
  sort(p, p+n, comp2);
	
	cout<<"id\t\tat\t\tbt\t\tst\t\tct\t\twt\t\ttt\t\tntt\n";
	int twt = 0, tt = 0;
	for(int i = 0;i < n;i++){
		cout<<p[i].id<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].st<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].ct-p[i].at-p[i].bt<<"\t\t"<<p[i].ct-p[i].at<<"\t\t"<<(p[i].ct-p[i].at) / (float) p[i].bt<<"\t\t"<<endl;
		twt += p[i].ct-p[i].at-p[i].bt;
		tt += p[i].ct-p[i].at;
	}
	float awt = twt / (float) n;
	float att = tt / (float) n;
	cout<<"Average turnaround time :"<<att<<endl;
	cout<<"Average waiting time :"<<awt<<endl;
}