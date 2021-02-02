#include<stdio.h>
typedef struct process
{
	int id;
	int arrival_time;
	int burst_time;
	int completion_time;
	int waiting_time;
	int turnaround_time;
} process;

void swap(process *p1, process *p2){
	process temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void sort(process p[],int n){
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(p[j].arrival_time > p[j+1].arrival_time){
				swap(&p[j],&p[j+1]);
			}
		}
	}
}

void main(){
	int n,i,j,value,low,completion;
	float avg_waiting,avg_turnaround;
	process p[10];
	printf("23 Graison S\n");
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("\nEnter the process id : ");
		scanf("%d",&p[i].id);
		printf("Enter the arrival time : ");
		scanf("%d",&p[i].arrival_time);
		printf("Enter the burst time : ");
		scanf("%d",&p[i].burst_time);
	}
	sort(p,n);
	completion = 0;
	for(i=0; i<n; i++){
		low = p[i].burst_time;
		value = i;
		j=i+1;
		while( j<n && p[j].arrival_time <= completion ){
			if( p[j].burst_time < low){
				low = p[j].burst_time;
				value = j;
			}
			j++;
		}
		p[value].completion_time = completion + low;
		p[value].turnaround_time = p[value].completion_time - p[value].arrival_time;
		p[value].waiting_time = p[value].turnaround_time - p[value].burst_time;
		swap(&p[i],&p[value]);
		completion = p[i].completion_time;
	}
	avg_waiting = 0;
	avg_turnaround = 0;
	for(i=0; i<n; i++){
		avg_waiting += p[i].waiting_time;
		avg_turnaround += p[i].turnaround_time;
	}
	avg_waiting /= n;
	avg_turnaround /= n;
	printf("\nProcess  Arrival_Time  Burst_Time  Waiting_Time  Turnaround_Time\n");
	for(i=0; i<n; i++){
		printf("%-9d%-14d%-12d%-14d%-17d\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
	}
	printf("\nAverage Waiting time = %0.2f",avg_waiting);
	printf("\nAverage Turnaround time = %0.2f\n",avg_turnaround);
}