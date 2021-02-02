#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dir
{
	char dir_name[10];
	char file_names[10][10];
	int f_count;
};
int find(struct dir d, char fname[] ){
	int i, f = -1;
	for(i=0; i<d.f_count; i++){
		if(strcmp(d.file_names[i],fname) == 0){
			f=i;
		}
	}
	return f;
}
void main(){
	int i, op, index;
	char fname[10];
	struct dir root;
	root.f_count = 0;
	printf("23 Graison S\n");
	printf("Enter the directory name : ");
	scanf("%s",root.dir_name);
	while(1){
		printf("\n-------------------------------------------------------------------------");
		printf("\n1. Create File\t\t2. Delete File\t\t3. Search File\n4. Display Files\t\t0. Exit\n");
		printf("Enter the option : ");
		scanf("%d",&op);
		switch(op){
			case 1:
					printf("\nEnter the name of the file: ");
					scanf("%s",fname);
					if(find(root, fname) == -1){
						strcpy(root.file_names[root.f_count++],fname);
						printf("\nFile created\n");
					}
					else
						printf("\nInvalid!! File already exists"); 
					break;
			case 2: 
					printf("\nEnter the file to delete: ");
					scanf("%s",fname);
					index = find(root,fname);
					if(index != -1){
						for(i=index;i<root.f_count-1; i++){
							strcpy(root.file_names[i],root.file_names[i+1]);
						}
						root.f_count--;
						printf("File deleted\n");
					}
					else
						printf("Invalid!! No such file exists.");
					break;
			case 3: 
					printf("\nEnter the file to search : ");
					scanf("%s",fname);
					if(find(root, fname) != -1)
						printf("File Found");
					else
						printf("File not found");
					break;
			case 4: 
					if(root.f_count == 0){
						printf("\nDirectory empty!!");
					}
					else{
						printf("------%s------\n",root.dir_name);
						for(i=0; i<root.f_count; i++){
							printf("%s\n",root.file_names[i]);
						}
					}
					break;
			case 0: exit(0);
		}
	}
}