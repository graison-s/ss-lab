#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{  
        FILE *f1,*f2,*f3,*f4,*f5;
        int lc,sa,val;
        char opcode[20],label[20],operand[20],op[20],lc1[20],label1[20];
        printf("23 Graison S\n");
        f1=fopen("input.txt","r");
        f3=fopen("symtab.txt","w");
        f4=fopen("intermediate.txt","w");
        f5=fopen("length.txt","w");
        fscanf(f1,"%s %s %s",label,opcode,operand);
        if(strcmp(opcode,"START")==0){
                if(strcmp(operand,"-") != 0){
                        sa = atoi(operand);
                        lc = sa;
                }
                else{
                        sa = 0;
                        lc = 0;
                }
                fprintf(f4,"-\t%s\t%s\t%s\n",label,opcode,operand);
        }
        fscanf(f1,"%s %s %s",label,opcode,operand);
        while(!feof(f1)){
                fprintf(f4,"\n%d\t%s\t%s\t%s\n",lc,label,opcode,operand);
                if(strcmp(label,"-")!=0){
                        /*f5=fopen("symtab.txt","r");
                        fscanf(f5,"%s %s",lc1,label1);
                        int f=0;
                        while(!feof(f5)){
                                if(strcmp(label,label1) == 0)
                                        f=1;
                        }
                        fclose(f5);
                        if(f==1){
                                printf("\nError!! Duplicate label.");exit(0);
                        }
                        else*/
                                fprintf(f3,"\n%d\t%s\n",lc,label);
                }
                f2=fopen("optab.txt","r");
                fscanf(f2,"%s %d",op,&val);
                while(!feof(f2)){
                        if(strcmp(opcode,op)==0){
                                lc=lc+3;
                                break;
                        }
                        fscanf(f2,"%s %d",op,&val);
                }
                fclose(f2);
                if(strcmp(opcode,"WORD")==0){
                        lc=lc+3;
                }
                else if(strcmp(opcode,"BYTE")==0){
                        if(op[0]=='X'){
                                lc=lc+1;
                        }
                        else{
                                lc=lc+strlen(operand)-2;
                        }
                }
                else if(strcmp(opcode,"RESB")==0){
                        lc = lc+atoi(operand);;
                }
                else if(strcmp(opcode,"RESW")==0){
                        lc=lc+(3*atoi(operand));
                }
                fscanf(f1,"%s %s %s",label,opcode,operand);
        }
        if(strcmp(opcode,"END")==0){
                fprintf(f5,"%d\n",lc-sa);
        }
        fclose(f1);
        fclose(f3);
        fclose(f4);
        fclose(f5);
}