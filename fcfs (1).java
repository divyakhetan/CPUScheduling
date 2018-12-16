import java.util.*;
import java.io.*;

class fcfs{

	static void swap(int a[], int i, int j){
		int t = a[i];
		a[i] = a[j];
		a[j] = t; 
	}
	
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int n;
		System.out.println("Enter the number of processes: ");
		n = s.nextInt();
		int at[] = new int[n];
		int st[] = new int[n];
		int id[] = new int[n];
		for(int i = 0;i < n;i++) id[i] = i+1;
		System.out.println("Enter the arrival time and service time for each process: ");
		for(int i = 0;i < n;i++){
			at[i] = s.nextInt();
			st[i] = s.nextInt();
		}
		
		for(int i = 0;i < n - 1;i++){
			for(int j = 0;j < n-i-1;j++){
				if(at[j] > at[j+1]){
					swap(at,j,j+1);
					swap(id,j,j+1);
					swap(st,j,j+1);
				}
			}
		}
		
		int ct[] = new int[n];
		int wt[] = new int[n];
		
		for(int i = 0;i < n;i++){
			if(i == 0) ct[i] = at[i] + st[i];
			else{
				if(at[i] > ct[i-1]) ct[i] = at[i] + st[i];
				else ct[i] = ct[i-1] + st[i];
			}
		}

		int tt[] = new int[n];
		float att = 0;
		for(int i = 0;i < n;i++) {tt[i] = ct[i] - at[i]; att += tt[i];}
		att = att / (float)n;
		float ntt[] = new float[n];
		float antt = (float)0;
		for(int i = 0;i < n;i++) ntt[i] = tt[i] / (float) st[i];
		int start[] = new int[n];
		for(int i = 0;i < n;i++) start[i] = at[i] + tt[i] - st[i];
		System.out.println("id\t\tat\t\tbt\t\tst\t\tct\t\ttt\t\tntt");
		for(int i = 0;i < n;i++){
			System.out.println(id[i] + "\t\t" + at[i] + "\t\t" + st[i] + "\t\t" + start[i] + "\t\t" + ct[i] + " \t\t" + tt[i] + "\t\t" + ntt[i]);
		}
		int twt = 0;
		for(int i = 0;i < n;i++) twt += tt[i] - st[i];
		
		float atwt = twt / (float)n;
		System.out.println("Average turnaround time: " + att);
		System.out.println("Average waiting time: " + atwt);
	}

}
