#include<stdio.h>

void main(){
	int i,size;
	float avg_waiting,avg_turnaround;
	int processes[100],burst_time[100],waiting_time[100],turnaround_time[100];
	printf("23 Graison S\n");
	printf("Enter the no. of processes: ");
	scanf("%d",&size);

	printf("\nEnter the processes");
	for(i=0; i<size; i++){
		printf("\nProcess %d : ",i);
		scanf("%d",&processes[i]);
	}
	printf("Enter the burst time of processes");
	for(i=0; i<size; i++){
		printf("\nProcess %d : ", processes[i] );
		scanf("%d",&burst_time[i]);
	}

	waiting_time[0] = 0;
	turnaround_time[0] = burst_time[0];
	for(i=1; i<size; i++){
		waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
		turnaround_time[i] = waiting_time[i] + burst_time[i];
	}

	avg_waiting = 0;
	avg_turnaround = 0;
	for(i=0; i<size; i++){
		avg_waiting += waiting_time[i];
		avg_turnaround += turnaround_time[i];
	}
	avg_waiting /= size;
	avg_turnaround /= size;

	printf("\nProcess  Burst_Time  Waiting_Time  Turnaround_Time\n");
	for(i=0; i<size; i++){
		printf("%-9d%-12d%-14d%-15d\n", processes[i],burst_time[i],waiting_time[i],turnaround_time[i]);
	}
	printf("\nAverage Waiting time = %0.2f",avg_waiting);
	printf("\nAverage Turnaround time = %0.2f\n",avg_turnaround);

}