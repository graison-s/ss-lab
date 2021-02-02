#include<stdio.h>
#include<stdlib.h>

void findSafeState(int** allocation, int** need, int* available,int n, int m){
	int i,j,k,f,s=0;
	int* work = (int*)malloc(m*sizeof(int));
	int* finish = (int*)malloc(n*sizeof(int));
	int* safe_seq = (int*)malloc(n*sizeof(int));
	for(i=0; i<m; i++){
		work[i] = available[i];
	}
	for(i=0; i<n; i++){
		finish[i] = 0;
	}
	for( k=0; k<5; k++ ) {
		if(s == n)
			break;
		for(i=0; i<n; i++){
			if(finish[i] == 0){
				f = 1;
				for(j=0; j<m; j++){
					if(need[i][j] > work[j]){
						f=0;break;
					}
				}
				if(f == 1){
					for(j=0; j<m; j++){
						work[j] += allocation[i][j];
					}
					safe_seq[s++] = i;
					finish[i] = 1;
				}
			}
		}
	}
	if(s == n){
		printf("The system is in safe state.\n");
		printf("The safe sequence is : ");
		for(i=0; i<n; i++){
			printf("p%d--> ",safe_seq[i]);
		}
		printf("\b\b\b\b    \n");
	}
	else
		printf("The system is not in a safe state.\n");
}
void main(){
	int i,j,n,m,p,f;
	printf("23 Graison S\n");
	printf("\nEnter the no. of resources : ");
	scanf("%d",&m);
	printf("Enter the no. of processes : ");
	scanf("%d",&n);

	int** allocation = (int**)malloc(n*sizeof(int*));
	int** max = (int**)malloc(n*sizeof(int*));
	int** need = (int**)malloc(n*sizeof(int*));
	int* available = (int*)malloc(m*sizeof(int));
	int* request = (int*)malloc(m*sizeof(int));
	for(i=0; i<n; i++){
		*(allocation+i) = (int*)malloc(m*sizeof(int));
		*(max+i) = (int*)malloc(m*sizeof(int));
		*(need+i) = (int*)malloc(m*sizeof(int));
	}

	printf("Enter the allocation matrix\n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter the max matrix\n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the available array\n");
	for(i=0; i<m; i++)
		scanf("%d",&available[i]);

	printf("The need matrix is\n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			need[i][j] = max[i][j] - allocation[i][j];
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	findSafeState(allocation,need,available,n,m);
	printf("\nEnter the process that requires new resources: ");
	scanf("%d",&p);
	printf("Enter the request array\n");
	for(j=0; j<m; j++)
		scanf("%d",&request[j]);
	f=1;
	for(j=0; j<m; j++){
		if(request[j] > need[p][j])
			f=0;
	}
	if(f == 1){
		f=1;
		for(j=0; j<m; j++){
			if(request[j] > available[j])
			f=0;
		}
		if(f == 1){
			for(j=0; j<m; j++){
				available[j] -= request[j];
				allocation[p][j] += request[j];
				need[p][j] -= request[j];
			}
			findSafeState(allocation,need,available,n,m);
		}
		else{
			printf("\nResources are not available\n");
		}
	}
	else{
		printf("\nThe process has exceeded its maximum claim.\n");
	}
}
