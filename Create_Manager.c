#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

struct Manager{
    char Name[100];
    char Username[26];
    char Password[26];
};
typedef struct Manager mngr;

int main(){
    printf("Press Enter to start the presentation...");
    getch();
    mngr m;
    printf("\n\nPlease enter the following credentials:\n");
    printf("Username: ");
    gets(m.Username);
    printf("Password: ");
    gets(m.Password);
    printf("Name: ");
    gets(m.Name);
    
    FILE *fp;
    fp=fopen("Managers.bin","ab");
    fwrite(&m,sizeof(m),1,fp);
    fclose(fp);

    
}