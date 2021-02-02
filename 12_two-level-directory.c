#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dir
{
	char dir_name[10];
	char file_names[10][10];
	int f_count;
};
int find_file(struct dir d, char fname[] ){
	int i, f = -1;
	for(i=0; i<d.f_count; i++){
		if(strcmp(d.file_names[i],fname) == 0){
			f=i;
		}
	}
	return f;
}
int find_directory(struct dir d[],int d_count,char dname[]){
	int i,f = -1;
	for(i=0; i<d_count; i++){
		if(strcmp(d[i].dir_name,dname) == 0){
			f = i;
		}
	}
	return f;
}
void main(){
	int i,j,op,index,index2,d_count;
	char fname[10], dname[10];
	struct dir users[10];
	d_count = 0;
	for(i=0; i<10; i++)
		users[i].f_count = 0;
	printf("23 Graison S\n");
	while(1){
		printf("\n-------------------------------------------------------------------------");
		printf("\n1. Create directory\t\t2. Create File\t\t3. Delete File\n4. Search File\t\t5. Display Files\t\t0. Exit\n");
		printf("Enter the option : ");
		scanf("%d",&op);
		switch(op){
			case 1: 
					printf("\nEnter the name of the directory : ");
					scanf("%s",dname);
					if(find_directory(users,d_count,dname) == -1){
						strcpy(users[d_count++].dir_name,dname);
						printf("\nDirectory created.");
					}
					else
						printf("\nInvalid!! Directory already exists"); 
					break;
			case 2:
					printf("\nEnter the directory : ");
					scanf("%s",dname);
					index = find_directory(users,d_count,dname);
					if(index != -1){
						printf("\nEnter the name of the file: ");
						scanf("%s",fname);
						if(find_file(users[index], fname) == -1){
							strcpy(users[index].file_names[users[index].f_count++],fname);
							printf("\nFile created\n");
						}
						else
							printf("\nInvalid!! File already exists"); 
					}
					else
						printf("\nInvalid!! Directory not found.");
					break;
			case 3: 
					printf("\nEnter the directory : ");
					scanf("%s",dname);
					index = find_directory(users,d_count,dname);
					if(index != -1){
						printf("\nEnter the file to delete: ");
						scanf("%s",fname);
						index2 = find_file(users[index],fname);
						if(index2 != -1){
							for(i=index2;i<users[index].f_count-1; i++){
								strcpy(users[index].file_names[i],users[index].file_names[i+1]);
							}
							users[index].f_count--;
							printf("File deleted\n");
						}
						else
							printf("Invalid!! No such file exists.");
					}
					else
						printf("\nInvalid!! Directory not found.");
					break;
			case 4: 
					printf("\nEnter the directory : ");
					scanf("%s",dname);
					index = find_directory(users,d_count,dname);
					if(index != -1){
						printf("\nEnter the file to search : ");
						scanf("%s",fname);
						if(find_file(users[index], fname) != -1)
							printf("File Found");
						else
							printf("File not found");
					}
					else
						printf("\nInvalid!! Directory not found.");
					break;
			case 5: 
					if(d_count == 0){
						printf("\nNo directories!!");
					}
					else{
						for(i=0; i<d_count; i++){
							printf("\n------%s------\n",users[i].dir_name);
							for(j=0; j<users[i].f_count; j++){
								printf("%s\n",users[i].file_names[j]);
							}
						}
					}
					break;
			case 0: exit(0);
		}
	}
}