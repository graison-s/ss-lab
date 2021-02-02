#include<stdio.h>

struct process{
	int id,arrival_time,burst_time,rem_burst;
	int completion_time,waiting_time,turnaround_time;
};
struct process queue[20];
int rear = -1,front = -1;
void enqueue(struct process p){
	if(front == -1){
		front = rear = 0;
		queue[front] = p;
	}
	else{
		queue[++front] = p;
	}
}
struct process dequeue(){
	return queue[rear++];
}
int isempty(){
	if(front == -1 || rear > front)
		return 1;
	else
		return 0;
}
void main() {
	int i,j,n,quantum, ready[20];
	float avg_waiting = 0, avg_turnaround = 0;
	struct process p[20], temp;
	printf("23 Graison S\n");
	printf("Enter the no. of process: ");
	scanf("%d",&n);

	for(i=0; i<n; i++){
		printf("\nEnter the process id : ");
		scanf("%d",&p[i].id);
		printf("Enter the arrival time : ");
		scanf("%d",&p[i].arrival_time);
		printf("Enter the burst time : ");
		scanf("%d",&p[i].burst_time);
	}
	printf("Enter the quantum time : ");
	scanf("%d",&quantum);
	for(i=0; i<n; i++)
		p[i].rem_burst = p[i].burst_time;

	int t = 0;
	
	for(i=0; i<n; i++)
		ready[i] = 0;
	//insert arrived processes to ready queue.
	for(i=0; i<n; i++){
		if(p[i].arrival_time <= t){
			enqueue(p[i]);
			ready[i] = 1;
		}
	}
	while(!isempty()){
		temp = dequeue();
		if(temp.rem_burst > quantum){
			t = t + quantum;
			temp.rem_burst -= quantum;
		}
		else{
			t = t + temp.rem_burst;
			temp.rem_burst = 0;
			for(i=0; i<n; i++){
				if(p[i].id == temp.id){
					p[i].completion_time = t;
				}
			}
		}
		for(i=0; i<n; i++){
			if(p[i].arrival_time <= t && ready[i] == 0){
				enqueue(p[i]);
				ready[i] = 1;
			}
		}
		if(temp.rem_burst != 0)
			enqueue(temp);
	}

	for(i=0; i<n; i++){
		p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
		p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
		avg_turnaround += p[i].turnaround_time;
		avg_waiting += p[i].waiting_time;
	}
	avg_turnaround /= n;
	avg_waiting /= n;

	printf("\nProcess  Arrival_Time  Burst_Time  Waiting_Time  Turnaround_Time\n");
	for(i=0; i<n; i++){
		printf("%-9d%-14d%-12d%-14d%-17d\n", p[i].id,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
	}
	printf("\nAverage Waiting time = %0.2f",avg_waiting);
	printf("\nAverage Turnaround time = %0.2f\n",avg_turnaround);


}
