#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,n,head,direction=1,tot_seek_time=0,avg_seek_time,request[100],finish[100];
	printf("23 Graison S");
	printf("\nEnter the no. of requests : ");
	scanf("%d",&n);
	printf("Enter the requested tracks in ascending order of arrival time.\n");
	for(i=0; i<n; i++)
		scanf("%d",&request[i]);
	printf("Enter the current head position : ");
	scanf("%d",&head);
	for(i=0; i<n; i++)
		finish[i] = 0;
	int count = 0,curr_track = head;
	while(1){
		if(count == n)
			break;
		if(direction == 1){
			for(i=0; i<n; i++){
				if(curr_track == request[i] && finish[i] == 0){
					tot_seek_time += abs(curr_track - head);
					head = curr_track;
					finish[i] = 1;
					count++;
				}
			}
		}
		if(curr_track == 0){
			head = 0;
			direction = 1;
		}
		if(curr_track == 199){
			tot_seek_time += abs(199-head);
			head = 199;
			direction = -1;
		}
		direction == 1 ? curr_track++ : curr_track--;
	}
	avg_seek_time = tot_seek_time / n;
	printf("\nThe total seek time for C-SCAN is : %d",tot_seek_time);
	printf("\nThe average seek time for C-SCAN is : %d\n",avg_seek_time);
	return 0;
}
