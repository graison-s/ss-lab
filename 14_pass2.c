#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main(){
	FILE *fint,*ftab,*flen,*fsym, *fout, *fobj;
	int op1[10],txtlen,txtlen1,i,j=0,len;
	char add[5],symadd[5],op[5],start[10],temp[30],line[20],label[20],mne[10],operand[10],symtab[10],opmne[10];
	printf("23 Graison S\n");
	fint=fopen("intermediate.txt","r");
	flen=fopen("length.txt","r");
	ftab=fopen("optab.txt","r");
	fsym=fopen("symtab.txt","r");
	fout=fopen("output.txt","w");
	fobj=fopen("object_file.txt","w");
	fscanf(fint,"%s%s%s%s",add,label,mne,operand);
	if(strcmp(mne,"START")==0){
		strcpy(start,operand);
		fscanf(flen,"%d",&len);
	}
	fprintf(fobj,"H^%s^%s^%d\nT^00%s^%d^",label,start,len,start,len);
	fprintf(fout, "%s\t%s\t%s\t%s\n",add,label,mne,operand );
	fscanf(fint,"%s%s%s%s",add,label,mne,operand);
	while(strcmp(mne,"END")!=0){
		fscanf(ftab,"%s%s",opmne,op);
		while(!feof(ftab)){
			if(strcmp(mne,opmne)==0){
				fclose(ftab);
				fscanf(fsym,"%s%s",symadd,symtab);
				while(!feof(fsym)){
					if(strcmp(operand,symtab)==0){
						fprintf(fobj,"%s%s^",op,symadd);
						fprintf(fout,"\n%s\t%s\t%s\t%s\t%s%s\n",add,label,mne,operand,op,symadd);
						break;
					}
					else
						fscanf(fsym,"%s%s",symadd,symtab);
				}
				break;
			}
			else
				fscanf(ftab,"%s%s",opmne,op);
		}
		if((strcmp(mne,"BYTE")==0)||(strcmp(mne,"WORD")==0)){
			if(strcmp(mne,"WORD")==0){
				fprintf(fobj,"00000%s^",operand);
				fprintf(fout,"\n%s\t%s\t%s\t%s\t00000%s\n",add,label,mne,operand,operand);
			}
			else{
				fprintf(fout,"\n%s\t%s\t%s\t%s\t",add,label,mne,operand);
				len=strlen(operand);
				for(i=2;i<len;i++){
					fprintf(fobj,"%d",operand[i]);
					fprintf(fout,"%d",operand[i]);
				}
				fprintf(fobj,"^");
				fprintf(fout, "\n");
			}
		}
		else if((strcmp(mne,"RESB")==0)||(strcmp(mne,"RESW")==0)){
			fprintf(fout,"\n%s\t%s\t%s\t%s\n",add,label,mne,operand);
		}
		fscanf(fint,"%s%s%s%s",add,label,mne,operand);
		ftab=fopen("optab.txt","r");
		fseek(ftab,SEEK_SET,0);
	}
	fprintf(fobj,"\b ");
	fprintf(fobj,"\nE^00%s\n",start);
	fprintf(fout,"\n%s\t%s\t%s\t%s\n",add,label,mne,operand);
	fclose(fint);
	fclose(ftab);
	fclose(fsym);
	fclose(flen);
}