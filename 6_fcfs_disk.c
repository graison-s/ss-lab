#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,head,tot_seek_time=0,avg_seek_time,request[100];
	printf("23 Graison S");
	printf("\nEnter the no. of requests : ");
	scanf("%d",&n);
	printf("Enter the requested tracks in ascending order of arrival time.\n");
	for(i=0; i<n; i++)
		scanf("%d",&request[i]);
	printf("Enter the current head position : ");
	scanf("%d",&head);
	for(i=0; i<n; i++){
		tot_seek_time += abs(request[i] - head);
		head = request[i];
	}
	avg_seek_time = tot_seek_time / n;
	printf("\nThe total seek time for fcfs is : %d",tot_seek_time);
	printf("\nThe average seek time for fcfs is : %d",avg_seek_time);
	return 0;
}