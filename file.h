#include<stdio.h>

int main(){
 FILE *fp;
char str;
 fp=fopen("input.txt","w+");
 while(!feof(fp)==0)
 {
     str=getc(fp);
     
 }

}