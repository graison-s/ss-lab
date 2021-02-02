#include<stdio.h>

void swap(int *p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void main(){
	int i,j,n;
	float avg_waiting,avg_turnaround;
	int process[100],burst_time[100],priority[100],waiting_time[100],turnaround_time[100];
	printf("23 Graison S\n");
	printf("Enter the no. of process: ");
	scanf("%d",&n);

	for(i=0; i<n; i++){
		printf("\nEnter the process id : ");
		scanf("%d",&process[i]);
		printf("Enter the burst time : ");
		scanf("%d",&burst_time[i]);
		printf("Enter the priority number : ");
		scanf("%d",&priority[i]);
	}
//sorting processes according to the priority number.
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(priority[j] > priority[j+1]) {
				swap(&process[j],&process[j+1]);
				swap(&burst_time[j],&burst_time[j+1]);
				swap(&priority[j],&priority[j+1]);
			}
		}
	}

	waiting_time[0] = 0;
	turnaround_time[0] = burst_time[0];
	for(i=1; i<n; i++){
		waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
		turnaround_time[i] = waiting_time[i] + burst_time[i];
	}

	avg_waiting = 0;
	avg_turnaround = 0;
	for(i=0; i<n; i++){
		avg_waiting += waiting_time[i];
		avg_turnaround += turnaround_time[i];
	}
	avg_waiting /= n;
	avg_turnaround /= n;

	printf("\nProcess  Burst_Time  Priority  Waiting_Time  Turnaround_Time\n");
	for(i=0; i<n; i++){
		printf("%-9d%-12d%-10d%-14d%-17d\n", process[i],burst_time[i],priority[i],waiting_time[i],turnaround_time[i]);
	}
	printf("\nAverage Waiting time = %0.2f",avg_waiting);
	printf("\nAverage Turnaround time = %0.2f\n",avg_turnaround);

}