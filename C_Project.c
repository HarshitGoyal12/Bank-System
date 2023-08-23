#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

struct Customer{
    char Username[26];
    char Password[26];
    char FName[50];
    char LName[50];
    char Father_Name[100];
    int age;
    char Sex[26];
    char Occupation[26];
    char Nationality[26];
    char Category[26];
    char Aadhar[13];
    char PAN[10];
    char Mobile[15];
    char Email[50];
    char Residence[200];
    char District[26];
    char State[26];
    char PIN[10];
    char Country[26];
    char Account_Type[10];
    time_t Opening_Date;
};
typedef struct Customer cust;

struct Manager{
    char Name[100];
    char Username[26];
    char Password[26];
};
typedef struct Manager mngr;

struct Transaction{
    char Username_from[26];
    char Username_to[26];
    float amount;
    time_t Date_Time;
};
typedef struct Transaction money;

void gotoxy(int x, int y);
void Welcome_Screen();
void Bank_Label();
void Customer_Manager_Clarification();
void Customer_New_Existing();
void Create_Customer_Account();
void Customer_Login();
void Customer_Menu(cust c);
void View_Profile(cust c);
void Modify_Profile(cust c);
void Check_Balance(cust c);
void Deposit_Money(cust c);
void Withdraw_Money(cust c);
void Transfer_Money(cust c);
void Loan_Application(cust c);
void Mini_Statement(cust c);
void Change_Password(cust c);
void Manager_Login();
void Manager_Menu(mngr m);
void List_Accounts();
void Manager_View_Profile(mngr m);


int main(){
    Welcome_Screen();
    Bank_Label();
    Customer_Manager_Clarification();
}

void Customer_Manager_Clarification(){

    cust_mngr_ask: Bank_Label();
    printf("I am a:");
    gotoxy(10,12);
    printf("1. Customer");
    gotoxy(10,14);
    printf("2. Manager");
    gotoxy(10,16);
    printf("3. Exit");
    gotoxy(0,20);
    int cust_mngr_clarity;
    printf("Please select any of the above choices: ");
    scanf("%d",&cust_mngr_clarity);
    char Garbage=getchar();
    gotoxy(10,22);
    switch(cust_mngr_clarity){
        case 1: Customer_New_Existing();
                break;
        case 2: Manager_Login();
                break;
        case 3: exit(0);
                break;
        default: {
            printf("Invalid Input! Press Enter to re-enter your choice!");
            getch();
            goto cust_mngr_ask;
        }
    }
}

void Customer_New_Existing(){
    new_existing: Bank_Label();
    printf("I am a:");
    gotoxy(10,13);
    printf("1. Existing Customer");
    gotoxy(10,15);
    printf("2. New Customer");
    gotoxy(10,17);
    printf("3. Exit");
    gotoxy(0,21);
    int new_existing_clarity;
    printf("Please select any of the above choices: ");
    scanf("%d",&new_existing_clarity);
    char Garbage=getchar();
    gotoxy(10,23);
    switch(new_existing_clarity){
        case 1: Customer_Login();
                break;
        case 2: Create_Customer_Account();
                break;
        case 3: exit(0);
                break;
        default: printf("Invalid Input! Press Enter to re-enter your choice.");
                 getch();
                 goto new_existing;
    }
}

void Create_Customer_Account(){
    Bank_Label();
    cust c;
    printf("Username: ");
    gotoxy(8,11);
    printf("NOTE: Username is supposed to be of maximum 25 characters, with no spaces. ");
    gotoxy(11,10);
    scanf("%s",c.Username);
    gotoxy(0,13);
    printf("Password: ");
    gotoxy(8,14);
    printf("NOTE: Password is supposed to be of maximum 25 characters, with no spaces");
    gotoxy(11,13);
    for (int i = 0; i < 26; i++) {
        char ch = getch();
        if (ch != 13) {
            c.Password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
    Bank_Label();
    printf("First Name: ");
    scanf("%s",c.FName);
    printf("Last Name: ");
    scanf("%s",c.LName);
    char Garbage=getchar();
    printf("Father's Name: ");
    gets(c.Father_Name);
    printf("Age: ");
    scanf("%d",&c.age);
    Garbage=getchar();
    Gender: printf("Gender: 1. Male    2.Female    3.Others  :");
    int gender;
    scanf("%d",&gender);
    Garbage=getchar();
    switch(gender){
        case 1: strcpy(c.Sex,"Male");
                break;
        case 2: strcpy(c.Sex,"Female");
                break;
        case 3: strcpy(c.Sex,"Others");
                break;
        default: printf("Invalid Input! Press Enter to reenter the choice.");
                 getch();
                 goto Gender;
    }
    printf("Occupation: ");
    scanf("%s",c.Occupation);
    printf("Nationality: ");
    scanf("%s",c.Nationality);
    printf("Category: ");
    scanf("%s",c.Category);
    printf("Aadhar ID Number: ");
    scanf("%s",c.Aadhar);
    printf("PAN ID Number: ");
    scanf("%s",c.PAN);
    Garbage=getchar();
    Bank_Label();
    printf("Mobile Number: ");
    gets(c.Mobile);
    printf("E-Mail ID: ");
    gets(c.Email);
    printf("Permanent Address:-\n");
    printf("\tResidence Local address: ");
    gets(c.Residence);
    printf("\tDistrict: ");
    gets(c.District);
    printf("\tState: ");
    gets(c.State);
    printf("\tCountry: ");
    gets(c.Country);
    printf("\tPIN Number: ");
    gets(c.PIN);
    Acc_Type: Bank_Label();
    printf("Account Type:-\n\n\n");
    printf("\t1. Savings Account.");
    printf("\n\t\t$Rate of Interest is 6%%.\n\t\t$No minimum balance needs to be maintained.\n\t\t$Restriction on the number of withdrawls.\n\t\t$ATM Cards are provided if you want to avail.\n\t\t$Recommended for Students, Pensioners and Working Professionals.\n\n");
    printf("\t2. Current Account.");
    printf("\n\t\t$No Interest is Paid on these accounts.\n\t\t$Overdraft facility is available.\n\t\t$Doesn't have any fixed maturity period.\n\t\t$Recommended for Businesses and Institutions.\n");
    printf("Please select any one of the above choices: ");
    int Account_Type;
    scanf("%d",&Account_Type);
    Garbage=getchar();
    switch(Account_Type){
        case 1: strcpy(c.Account_Type,"Savings");
                break;
        case 2: strcpy(c.Account_Type,"Current");
                break;
        default: printf("Invalid Input! Press Enter to reenter the choice.");
                 getch();
                 goto Acc_Type;
                 break;
    }
    time(&c.Opening_Date);
    printf("\n\n\nYour data is being processed...Please Wait!");
    sleep(3);
    Bank_Label();
    gotoxy(30,20);
    printf("Congratulations %s, Your account at United Bank of India has been succesfuly created!",c.FName);
    if(strcmp(c.Account_Type,"Savings")==0){
        gotoxy(15,22);
        printf("You will be awarded 6%% Interest on your deposits and will be credited to your bank account on quarterly basis.");
    }

    FILE *fp;
    fp=fopen("Customers.bin","ab");
    if (fp==NULL){ 
        printf("Error in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    else{
        fwrite(&c,sizeof(c),1,fp);
        fclose(fp);
    }

    gotoxy(40,25);
    printf("Press Enter to Login!");
    getch();
    Customer_Login();
}

void Customer_Login(){
    Cust_Username: Bank_Label();
    cust c;
    char username[26]={};
    char password[26]={};
    gotoxy(60,20);
    printf("Enter Username: ");
    scanf("%s",username);
    gotoxy(60,22);
    printf("Enter Password: ");
    for(int i=0;i<26;i++){
        char ch=getch();
        if(ch!=13){
            password[i]=ch;
            ch='*';
            printf("%c",ch);
        }
        else
            break;
    }
    gotoxy(60,26);
    FILE *fp;
    fp=fopen("Customers.bin","rb");
    if (fp==NULL){ 
        printf("Error in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    while(fread(&c,sizeof(c),1,fp)){
        if(strcmp(username,c.Username)==0&&strcmp(password,c.Password)==0){
            printf("Login Successful! Press Enter to continue...");
            getch();
            fclose(fp);
            Customer_Menu(c);
        }
    }
    gotoxy(40,26);
    printf("Username or Password Invalid! Press Enter to re-enter your Username and Password!");
    getch();
    goto Cust_Username;

}

void Manager_Login(){
    Mngr_Username: Bank_Label();
    mngr m;
    char username[26]={};
    char password[26]={};
    gotoxy(60,20);
    printf("Enter Username: ");
    scanf("%s",username);
    gotoxy(60,22);
    printf("Enter Password: ");
    for(int i=0;i<26;i++){
        char ch=getch();
        if(ch!=13){
            password[i]=ch;
            ch='*';
            printf("%c",ch);
        }
        else
            break;
    }
    gotoxy(60,26);
    FILE *fp;
    fp=fopen("Managers.bin","rb");
    if (fp==NULL){ 
        printf("Error in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    while(fread(&m,sizeof(m),1,fp)){
        if(strcmp(username,m.Username)==0&&strcmp(password,m.Password)==0){
            printf("Login Successful! Press Enter to continue...");
            getch();
            Manager_Menu(m);
        }
    }
    fclose(fp);
    gotoxy(40,26);
    printf("Username or Password Invalid! Press Enter to re-enter your Username and Password.");
    getch();
    goto Mngr_Username;

}

void Customer_Menu(cust c){
    Cust_Menu: Bank_Label();
    printf("Name: %s %s\n\n\n",c.FName,c.LName);
    printf("Services Available: ");
    gotoxy(10,17);
    printf("1. View Profile.");
    gotoxy(10,19);
    printf("2. Check Balance.");
    gotoxy(10,21);
    printf("3. Deposit Money.");
    gotoxy(10,23);
    printf("4. Withdraw Money.");
    gotoxy(10,25);
    printf("5. Transfer Money.");
    gotoxy(10,27);
    printf("6. Loan Application.");
    gotoxy(10,29);
    printf("7. Display Mini-Statement.");
    gotoxy(10,31);
    printf("8. Change Password.");
    gotoxy(10,33);
    printf("9. Exit.");

    printf("\n\nPlease select your desired transaction: ");
    int Transaction;
    scanf("%d",&Transaction);
    char Garbage=getchar();

    switch(Transaction){
        case 1: View_Profile(c);
                break;
        case 2: Check_Balance(c);
                break;
        case 3: Deposit_Money(c);
                break;
        case 4: Withdraw_Money(c);
                break;
        case 5: Transfer_Money(c);
                break;
        case 6: Loan_Application(c);
                break;
        case 7: Mini_Statement(c);
                break;
        case 8: Change_Password(c);
                break;
        case 9: exit(0);
        default: {
            printf("Invalid Input! Press Enter to re-enter your choice!");
            getch();
            goto Cust_Menu;
        }
    }

}

void View_Profile(cust c){
    View_Profile_Label: Bank_Label();
    printf("1. Name: %s %s.\n",c.FName,c.LName);
    printf("2. Username: %s.\n",c.Username);
    printf("3. Father's Name: %s.\n",c.Father_Name);
    printf("4. Age: %d.\n",c.age);
    printf("5. Sex: %s.\n",c.Sex);
    printf("6. Occupation: %s.\n",c.Occupation);
    printf("7. Nationality: %s.\n",c.Nationality);
    printf("8. Category: %s.\n",c.Category);
    printf("9. Aadhar ID Number: %s.\n",c.Aadhar);
    printf("10. PAN ID Number: %s.\n",c.PAN);
    printf("11. Mobile Number: %s.\n",c.Mobile);
    printf("12. Email ID: %s.\n",c.Email);
    printf("13. Address: %s, %s, %s, %s, PIN Code: %s.\n",c.Residence,c.District,c.State,c.Country,c.PIN);
    printf("14. Account Type: %s.\n",c.Account_Type);
    printf("15. Opening Date: %s\n\n\n",ctime(&c.Opening_Date));

    printf("Please select your desired choice to proceed: \n\n");
    printf("\t\t1. Modify Profile.\n\n");
    printf("\t\t2. Return to Menu.\n\n");
    printf("\t\t3. Exit.\n\n");
    printf("Your choice: ");
    int View_Profile_Choices;
    scanf("%d",&View_Profile_Choices);
    char Garbage=getchar();

    switch(View_Profile_Choices){
        case 1: Modify_Profile(c);
                break;
        case 2: Customer_Menu(c);
                break;
        case 3: exit(0);
                break;
        default: {
            printf("Invalid Input! Press Enter to re-enter your choice!");
            getch();
            goto View_Profile_Label;
        }
    }

}

void Modify_Profile(cust c){
    Modify_Profile_Label: Bank_Label();
    printf("1. Name: %s %s.\n",c.FName,c.LName);
    printf("2. Username: %s.\n",c.Username);
    printf("3. Father's Name: %s.\n",c.Father_Name);
    printf("4. Age: %d.\n",c.age);
    printf("5. Sex: %s.\n",c.Sex);
    printf("6. Occupation: %s.\n",c.Occupation);
    printf("7. Nationality: %s.\n",c.Nationality);
    printf("8. Category: %s.\n",c.Category);
    printf("9. Aadhar ID Number: %s.\n",c.Aadhar);
    printf("10. PAN ID Number: %s.\n",c.PAN);
    printf("11. Mobile Number: %s.\n",c.Mobile);
    printf("12. Email ID: %s.\n",c.Email);
    printf("13. Address: %s, %s, %s, %s, PIN Code: %s.\n\n\n",c.Residence,c.District,c.State,c.Country,c.PIN);

    printf("\t\tNOTE: Only field number 6, 11 and 12 are allowed to be changed through online portal.\n\n\t\tPlease select the field, you want to change: ");
    int field;
    scanf("%d",&field);
    char Garbage=getchar();

    Bank_Label();
    switch(field){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
        case 13: {
            printf("\t\tThe field you have chosen cannot be changed through this online portal.\n\n\t  Please visit our nearest branch physically with proper documentation and valid proof of change.");
            break;
        }
        case 6: {
            printf("Current occupation: %s\n\n",c.Occupation);
            printf("Enter new occupation: ");
            char temp_occupation[26];
            gets(temp_occupation);
            if(strcmp(c.Occupation,temp_occupation)==0){
                printf("\n\t\tError! Your current occupation and new occupation are same, so this field is not being changed.");
            }
            else{
                strcpy(c.Occupation,temp_occupation);
                printf("\n\t\tCongrats! Change Successful\n\n\t   Your new occupation is %s.",c.Occupation);
            }
            break;
        }
        case 11: {
            printf("Current Mobile Number: %s\n\n",c.Mobile);
            printf("Enter new mobile number: ");
            char temp_mobile[15];
            gets(temp_mobile);
            if(strcmp(c.Mobile,temp_mobile)==0){
                printf("\n\t\tError! Your current mobile number and new mobile number are same, so this field is not being changed.");
            }
            else{
                strcpy(c.Mobile,temp_mobile);
                printf("\n\t\tCongrats! Change Successful\n\n\t   Your new mobile number is %s.",c.Mobile);
            }
            break;
        }
        case 12: {
            printf("Current Email ID: %s\n\n",c.Email);
            printf("Enter new Email ID: ");
            char temp_email[50];
            gets(temp_email);
            if(strcmp(c.Email,temp_email)==0){
                printf("\n\t\tError! Your current Email ID and new Email ID are same, so this field is not being changed.");
            }
            else{
                strcpy(c.Email,temp_email);
                printf("\n\t\tCongrats! Change Successful\n\n\t   Your new Email ID is %s.",c.Email);
            }
        }

    }

    cust temp;
    FILE *fp, *ft;
    fp=fopen("Customers.bin","rb");
    ft=fopen("temp.bin","ab");
    while(fread(&temp,sizeof(temp),1,fp)){
        if(strcmp(temp.Username,c.Username)!=0){
            fwrite(&temp,sizeof(temp),1,ft);
        }
        else{
            fwrite(&c,sizeof(c),1,ft);
        }
    }
    fclose(ft);
    fclose(fp);
    remove("Customers.bin");
    rename("temp.bin","Customers.bin");
    
    printf("\n\n\n\t\tPress Enter to View Profile!");
    getch();
    View_Profile(c);
    
}

void Check_Balance(cust c){
    Bank_Label();
    FILE *fp;
    float Current_Balance=0;
    fp=fopen("Money.bin","rb");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    money mo_temp;
    while(fread(&mo_temp,sizeof(mo_temp),1,fp)){
        if(strcmp(mo_temp.Username_to,c.Username)==0){
            Current_Balance += mo_temp.amount;
        }
        else if(strcmp(mo_temp.Username_from,c.Username)==0){
            Current_Balance -= mo_temp.amount;
        }
    }
    fclose(fp);
    gotoxy(60,12);
    printf("Username: %s",c.Username);
    gotoxy(60,15);
    printf("Your current balance is Rs %f.",Current_Balance);

    After_Check_Balance: printf("\n\n\n\n\t\tPlease select to proceed:-");
    printf("\n\n\n\t\t\t1. Return to Main Menu.");
    printf("\n\n\t\t\t2. Exit.");

    int choice;
    printf("\n\n\n\t\tYour Choice: ");
    scanf("%d",&choice);
    char Garbage=getchar();

    switch(choice){
        case 1: Customer_Menu(c);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
            getch();
            goto After_Check_Balance;
        }
    }    

}

void Deposit_Money(cust c){
    Bank_Label();
    money mo;
    strcpy(mo.Username_from,"Cash Deposit");
    strcpy(mo.Username_to,c.Username);
    printf("Username: %s\n\n\nPlease enter the amount you want to deposit: ",c.Username);
    scanf("%f",&mo.amount);
    time(&mo.Date_Time);

    FILE *fp;
    fp=fopen("Money.bin","ab");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    fwrite(&mo,sizeof(mo),1,fp);
    fclose(fp);

    
    float Current_Balance=0;
    fp=fopen("Money.bin","rb");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    money mo_temp;
    while(fread(&mo_temp,sizeof(mo_temp),1,fp)){
        if(strcmp(mo_temp.Username_to,c.Username)==0){
            Current_Balance += mo_temp.amount;
        }
        else if(strcmp(mo_temp.Username_from,c.Username)==0){
            Current_Balance -= mo_temp.amount;
        }
    }
    fclose(fp);

    gotoxy(70,18);
    printf("Amount deposited successfully!");
    gotoxy(70,20);
    printf("Current Balance: Rs %f",Current_Balance);

    After_Deposit: printf("\n\n\n\n\t\tPlease select to proceed:-");
    printf("\n\n\n\t\t\t1. Return to Main Menu.");
    printf("\n\n\t\t\t2. Exit.");

    int choice;
    printf("\n\n\n\t\tYour Choice: ");
    scanf("%d",&choice);
    char Garbage=getchar();

    switch(choice){
        case 1: Customer_Menu(c);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
            getch();
            goto After_Deposit;
        }
    }
    
}

void Withdraw_Money(cust c){
    Bank_Label();
    money mo;
    strcpy(mo.Username_to,"Cash Withdrawl");
    strcpy(mo.Username_from,c.Username);
    printf("Username: %s\n\n\nPlease enter the amount you want to withdraw: ",c.Username);
    scanf("%f",&mo.amount);
    FILE *fp;
    float Current_Balance=0;
    fp=fopen("Money.bin","rb");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    money mo_temp;
    while(fread(&mo_temp,sizeof(mo_temp),1,fp)){
        if(strcmp(mo_temp.Username_to,c.Username)==0){
            Current_Balance += mo_temp.amount;
        }
        else if(strcmp(mo_temp.Username_from,c.Username)==0){
            Current_Balance -= mo_temp.amount;
        }
    }
    fclose(fp);
    if(Current_Balance<mo.amount){
        printf("Your current balance is less than the amount you want to withdraw, therefore, this transaction cannot be processed.");
        goto After_Withdrawl;
    }
    time(&mo.Date_Time);
    Current_Balance-=mo.amount;

    fp=fopen("Money.bin","ab");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    fwrite(&mo,sizeof(mo),1,fp);
    fclose(fp);

    gotoxy(70,18);
    printf("Amount withdrawn successfully!");
    gotoxy(70,20);
    printf("Current Balance: Rs %f",Current_Balance);

    After_Withdrawl: printf("\n\n\n\n\t\tPlease select to proceed:-");
    printf("\n\n\n\t\t\t1. Return to Main Menu.");
    printf("\n\n\t\t\t2. Exit.");

    int choice;
    printf("\n\n\n\t\tYour Choice: ");
    scanf("%d",&choice);
    char Garbage=getchar();

    switch(choice){
        case 1: Customer_Menu(c);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
            getch();
            goto After_Withdrawl;
        }
    }
    
}

void Transfer_Money(cust c){
    Bank_Label();
    money mo;
    strcpy(mo.Username_from,c.Username);
    printf("Username: %s\n\n\nPlease enter the username of the person, to whom you want to transfer the money: ",c.Username);
    gets(mo.Username_to);
    printf("\n\nPlease enter the amount you want to transfer to %s: ",mo.Username_to);
    scanf("%f",&mo.amount);
    FILE *fp;
    float Current_Balance=0;
    fp=fopen("Money.bin","rb");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    money mo_temp;
    while(fread(&mo_temp,sizeof(mo_temp),1,fp)){
        if(strcmp(mo_temp.Username_to,c.Username)==0){
            Current_Balance += mo_temp.amount;
        }
        else if(strcmp(mo_temp.Username_from,c.Username)==0){
            Current_Balance -= mo_temp.amount;
        }
    }
    fclose(fp);
    if(Current_Balance<mo.amount){
        printf("\n\nOops! Your current balance is less than the amount you want to transfer, therefore, this transaction cannot be processed!");
        goto After_Transfer;
    }
    time(&mo.Date_Time);
    Current_Balance -= mo.amount;

    fp=fopen("Money.bin","ab");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    fwrite(&mo,sizeof(mo),1,fp);
    fclose(fp);

    printf("\n\n\n\t\tAmount transferred successfully!");
    printf("\n\n\t\tCurrent Balance: Rs %f",Current_Balance);

    After_Transfer: printf("\n\n\n\n\t\tPlease select to proceed:-");
    printf("\n\n\n\t\t\t1. Return to Menu.");
    printf("\n\n\t\t\t2. Exit.");

    int choice;
    printf("\n\n\n\t\tYour Choice: ");
    scanf("%d",&choice);
    char Garbage=getchar();

    switch(choice){
        case 1: Customer_Menu(c);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
            getch();
            goto After_Transfer;
        }
    }
    
}

void Loan_Application(cust c){
    Loan_Application: Bank_Label();
    printf("Type of Loan:-\n\n\n");
    printf("\t\t1. Car Loan.");
    printf("\n\n\t\t2. Home Loan");
    printf("\n\n\t\t3. Personal Loan.");
    printf("\n\n\t\t4. Student Loan.");
    printf("\n\n\nPlease enter your choice: ");
    int loan;
    scanf("%d",&loan);
    char Garbage=getchar();

    switch(loan){
        case 1: {
            Bank_Label();
            printf("Thank You for showing interest in taking car loan from United Bank of India!\n\nHere are some of the salient features:\n");
            printf("\n\t$ Lowest interest rates and EMI.");
            printf("\n\t$ Longest repayment tenure (7 Years).");
            printf("\n\t$ Financing of upto 90%% on the On-Road price of the vehicle.");
            printf("\n\t$ Optional Life Insurance cover.");
            printf("\n\t$ No advance EMI.");

            Car_Lon_Choice: printf("\n\n\nPlease select to proceed:\n");
            printf("\n\n\t1. Apply for Car Loan.");
            printf("\n\n\t2. Return to Menu.");
            printf("\n\n\t3. Exit.");
            printf("\n\n\nYour Choice: ");
            int Loan_Choice;
            scanf("%d",&Loan_Choice);
            Garbage=getchar();

            switch(Loan_Choice){
                case 1: {
                    Bank_Label();
                    printf("Please enter the principal amount you want to borrow: ");
                    float amount,roi;
                    int time;
                    scanf("%f",&amount);
                    Garbage=getchar();
                    Trm_Choice: Bank_Label();
                    printf("Please select the terms of loan:\n");
                    printf("\n\n\t1. Above 3 Years, Rate of Interest: 7.25%%.");
                    printf("\n\n\t2. Above 5 Years, Rate of Interest: 7.35%%.");
                    printf("\n\n\nYour Choice: ");
                    int Term_Choice;
                    scanf("%d",&Term_Choice);
                    Garbage=getchar();
                    switch(Term_Choice){
                        case 1: {
                            roi=7.25;
                            time=3;
                            break;
                        }
                        case 2: {
                            roi=7.35;
                            time=5;
                            break;
                        }
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Trm_Choice;
                        }
                    }
                    Bank_Label();
                    printf("Your loan application has been submitted for verification. You will be contacted by bank through E-mail for further processing.\n\nHere are the details of your Car Loan Application Request:-");
                    printf("\n\n\n\t\tUsername: %s",c.Username);
                    printf("\n\n\t\tPrincipal amount: %f",amount);
                    printf("\n\n\t\tRate of Interest: %f%%.",roi);
                    printf("\n\n\t\tTime Period: Above %d Years.",time);
                    printf("\n\n\nPress Enter to proceed...");
                    getch();
                    Car_pro_chice: printf("\n\n\nPlease select to proceed:");
                    printf("\n\n\t1. Return to Menu.");
                    printf("\n\t2. Exit.");
                    printf("\n\nYour choice: ");

                    int Car_Pro_Choice;
                    scanf("%d",&Car_Pro_Choice);
                    Garbage=getchar();
                    switch(Car_Pro_Choice){
                        case 1: Customer_Menu(c);
                                break;
                        case 2: exit(0);
                                break;
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Car_pro_chice;
                        }
                    }

                }
                case 2: Customer_Menu(c);
                        break;
                case 3: exit(0);
                        break;
                default: {
                    printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                    getch();
                    goto Car_Lon_Choice;
                }
            }
        }
        case 2: {
            Bank_Label();
            printf("Thank You for showing interest in taking home loan from United Bank of India!\n\nHere are some of the salient features:\n");
            printf("\n\t$ Lowest interest rates and processing fees.");
            printf("\n\t$ Repayment upto 30 Years.");
            printf("\n\t$ Home loan available as overdraft.");
            printf("\n\t$ Interest concessions for women borrowers.");
            printf("\n\t$ No hidden charges.");

            Home_Lon_Choice: printf("\n\n\nPlease select to proceed:\n");
            printf("\n\n\t1. Apply for Home Loan.");
            printf("\n\n\t2. Return to Menu.");
            printf("\n\n\t3. Exit.");
            printf("\n\n\nYour Choice: ");
            int Loan_Choice;
            scanf("%d",&Loan_Choice);
            Garbage=getchar();

            switch(Loan_Choice){
                case 1: {
                    Bank_Label();
                    Home_Trm_Choice: Bank_Label();
                    float roi;
                    printf("Please select the terms of loan:\n");
                    printf("\n\n\t1. Below Rs 30,00,000 loan, Rate of Interest: 6.7%%.");
                    printf("\n\n\t2. Above Rs 30,00,000 loan, Rate of Interest: 6.9%%.");
                    printf("\n\n\nYour Choice: ");
                    int Term_Choice;
                    scanf("%d",&Term_Choice);
                    Garbage=getchar();
                    switch(Term_Choice){
                        case 1: {
                            roi=6.7;
                            break;
                        }
                        case 2: {
                            roi=6.9;
                            break;
                        }
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Home_Trm_Choice;
                        }
                    }
                    Bank_Label();
                    double amount;
                    printf("Please enter the principal amount you want to borrow: ");
                    scanf("%lf",&amount);
                    Garbage=getchar();
                    if(Term_Choice==1 && amount>3000000){
                        printf("\n\nError! You have selected your loan term for principal below Rs 30,00,000 but you entered principal amount greater than Rs 30,00,000.");
                        printf("\n\nPress enter to choose loan term again...");
                        getch();
                        goto Home_Trm_Choice;
                    }
                    else if(Term_Choice==2 && amount<3000000){
                        printf("\n\nError! You have selected your loan term for principal above Rs 30,00,000 but you entered principal amount smaller than Rs 30,00,000.");
                        printf("\n\nPress enter to choose loan term again...");
                        getch();
                        goto Home_Trm_Choice;
                    }
                    
                    Bank_Label();
                    printf("Your loan application has been submitted for verification. You will be contacted by bank through E-mail for further processing.\n\nHere are the details of your Home Loan Application Request:-");
                    printf("\n\n\n\t\tUsername: %s",c.Username);
                    printf("\n\n\t\tPrincipal amount: %f",amount);
                    printf("\n\n\t\tRate of Interest: %f%%.",roi);
                    printf("\n\n\nPress Enter to proceed...");
                    getch();
                    Home_pro_chice: printf("\n\n\nPlease select to proceed:");
                    printf("\n\n\t1. Return to Menu.");
                    printf("\n\t2. Exit.");
                    printf("\n\nYour choice: ");

                    int Home_Pro_Choice;
                    scanf("%d",&Home_Pro_Choice);
                    Garbage=getchar();
                    switch(Home_Pro_Choice){
                        case 1: Customer_Menu(c);
                                break;
                        case 2: exit(0);
                                break;
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Home_pro_chice;
                        }
                    }

                }
                case 2: Customer_Menu(c);
                        break;
                case 3: exit(0);
                        break;
                default: {
                    printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                    getch();
                    goto Home_Lon_Choice;
                }
            }
        }
        case 3: {
            Bank_Label();
            printf("Thank You for showing interest in taking personal loan from United Bank of India!\n\nHere are some of the salient features:\n");
            printf("\n\t$ Lowest interest rates.");
            printf("\n\t$ Loans up to Rs 20,00,000.");
            printf("\n\t$ No Security, No Guarantor.");
            printf("\n\t$ Minimal documentation.");
            printf("\n\t$ Interest on daily reducing balance.");
            printf("\n\t$ No hidden charges.");

            Personal_Lon_Choice: printf("\n\n\nPlease select to proceed:\n");
            printf("\n\n\t1. Apply for Personal Loan.");
            printf("\n\n\t2. Return to Menu.");
            printf("\n\n\t3. Exit.");
            printf("\n\n\nYour Choice: ");
            int Loan_Choice;
            scanf("%d",&Loan_Choice);
            Garbage=getchar();

            switch(Loan_Choice){
                case 1: {
                    Principal: Bank_Label();
                    printf("Please enter the principal amount you want to borrow: ");
                    float amount,roi;
                    int time;
                    scanf("%f",&amount);
                    Garbage=getchar();
                    if(amount>2000000){
                        printf("\n\nOops! You can't take a personal loan of more than Rs 20,00,000.\n\nPress Enter to re-enter the principal amount...");
                        getch();
                        goto Principal;
                    }
                    Personal_Trm_Choice: Bank_Label();
                    printf("Please select the terms of loan:\n");
                    printf("\n\n\t1. Above 3 Years, Rate of Interest: 7.25%%.");
                    printf("\n\n\t2. Above 5 Years, Rate of Interest: 7.35%%.");
                    printf("\n\n\nYour Choice: ");
                    int Term_Choice;
                    scanf("%d",&Term_Choice);
                    Garbage=getchar();
                    switch(Term_Choice){
                        case 1: {
                            roi=7.25;
                            time=3;
                            break;
                        }
                        case 2: {
                            roi=7.35;
                            time=5;
                            break;
                        }
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Personal_Trm_Choice;
                        }
                    }
                    Bank_Label();
                    printf("Your loan application has been submitted for verification. You will be contacted by bank through E-mail for further processing.\n\nHere are the details of your Car Loan Application Request:-");
                    printf("\n\n\n\t\tUsername: %s",c.Username);
                    printf("\n\n\t\tPrincipal amount: %f",amount);
                    printf("\n\n\t\tRate of Interest: %f%%.",roi);
                    printf("\n\n\t\tTime Period: Above %d Years.",time);
                    printf("\n\n\nPress Enter to proceed...");
                    getch();
                    Personal_pro_chice: printf("\n\n\nPlease select to proceed:");
                    printf("\n\n\t1. Return to Menu.");
                    printf("\n\t2. Exit.");
                    printf("\n\nYour choice: ");

                    int Personal_Pro_Choice;
                    scanf("%d",&Personal_Pro_Choice);
                    Garbage=getchar();
                    switch(Personal_Pro_Choice){
                        case 1: Customer_Menu(c);
                                break;
                        case 2: exit(0);
                                break;
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Personal_pro_chice;
                        }
                    }

                }
                case 2: Customer_Menu(c);
                        break;
                case 3: exit(0);
                        break;
                default: {
                    printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                    getch();
                    goto Personal_Lon_Choice;
                }
            }
        }
        case 4: {
            Bank_Label();
            printf("Thank You for showing interest in taking a student loan from United Bank of India!\n\nHere are some of the salient features:\n");
            printf("\n\t$ Repayment will commence one year after completion of course.");
            printf("\n\t$ Loans to be repaid in 15 Years after commencement of repayment.");
            printf("\n\t$ Effective interest rate of 8.65%%.");

            Student_Lon_Choice: printf("\n\n\nPlease select to proceed:\n");
            printf("\n\n\t1. Apply for Student Loan.");
            printf("\n\n\t2. Return to Menu.");
            printf("\n\n\t3. Exit.");
            printf("\n\n\nYour Choice: ");
            int Loan_Choice;
            scanf("%d",&Loan_Choice);
            Garbage=getchar();

            switch(Loan_Choice){
                case 1: {
                    Bank_Label();
                    printf("Please enter the principal amount you want to borrow: ");
                    float amount,roi=8.65;
                    scanf("%f",&amount);
                    Garbage=getchar();
                    Student_Trm_Choice: Bank_Label();
                    Bank_Label();
                    printf("Your loan application has been submitted for verification. You will be contacted by bank through E-mail for further processing.\n\nHere are the details of your Car Loan Application Request:-");
                    printf("\n\n\n\t\tUsername: %s",c.Username);
                    printf("\n\n\t\tPrincipal amount: %f",amount);
                    printf("\n\n\t\tRate of Interest: %f%%.",roi);
                    printf("\n\n\nPress Enter to proceed...");
                    getch();
                    Student_pro_chice: printf("\n\n\nPlease select to proceed:");
                    printf("\n\n\t1. Return to Menu.");
                    printf("\n\t2. Exit.");
                    printf("\n\nYour choice: ");

                    int Student_Pro_Choice;
                    scanf("%d",&Student_Pro_Choice);
                    Garbage=getchar();
                    switch(Student_Pro_Choice){
                        case 1: Customer_Menu(c);
                                break;
                        case 2: exit(0);
                                break;
                        default: {
                            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                            getch();
                            goto Student_pro_chice;
                        }
                    }

                }
                case 2: Customer_Menu(c);
                        break;
                case 3: exit(0);
                        break;
                default: {
                    printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
                    getch();
                    goto Student_Lon_Choice;
                }
            }
        }
        default: {
            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice!");
            getch();
            goto Loan_Application;
        }
    }


}

void Mini_Statement(cust c){
    Bank_Label();
    printf("Username: %s",c.Username);
    gotoxy(70,13);
    printf("Mini-Statement:-\n\n\n");
    FILE *fp;
    money temp;
    fp=fopen("Money.bin","rb");
    if (fp==NULL){ 
        printf("\n\nError in opening file! Press Enter to exit the program...");
        fclose(fp);
        getch();
        exit(0);
    }
    int i=1;
    float Current_Balance=0;
    while(fread(&temp,sizeof(temp),1,fp)){
        if(strcmp(temp.Username_from,c.Username)==0||strcmp(temp.Username_to,c.Username)==0){
            printf("%d\t%s\tto\t%s\t\t%f\t%s\n\n",i,temp.Username_from,temp.Username_to,temp.amount,ctime(&temp.Date_Time));
            i++;
        }
        if(strcmp(temp.Username_to,c.Username)==0){
            Current_Balance += temp.amount;
        }
        else if(strcmp(temp.Username_from,c.Username)==0){
            Current_Balance -= temp.amount;
        }
    }
    fclose(fp);

    printf("\nCurrent Balance = %f\n",Current_Balance);

    Mini_stmnt_choice: printf("\n\n\nPlease select to proceed:-");
    int Mini_Statement_Choice;
    printf("\n\n\t1. Return to Menu.");
    printf("\n\t2. Exit.");
    printf("\n\nYour Choice: ");
    scanf("%d",&Mini_Statement_Choice);
    char Garbage=getchar();

    switch(Mini_Statement_Choice){
        case 1: Customer_Menu(c);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\n\t\t\tInvalid Input! Press Enter to re-enter your choice...");
            getch();
            goto Mini_stmnt_choice;
        }
    }

}

void Change_Password(cust c){
    ch_pass: Bank_Label();
    char Old_Password[26]={};
    char New_Password[26]={};
    char Confirm_New_Password[26]={};
    printf("Please enter your old password: ");
    for (int i = 0; i < 26; i++) {
        char ch = getch();
        if (ch != 13) {
            Old_Password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
    if(strcmp(Old_Password,c.Password)!=0){
        printf("\n\n\t\tOops! You entered incorrect password!");
        chice: printf("\n\n\nPlease select to proceed:");
        printf("\n\n\n\t1. Re-enter Old Password.");
        printf("\n\n\t2. Return to Menu");
        printf("\n\n\t3. Exit.");
        printf("\n\n\nYour choice: ");
        int pass_choice;
        scanf("%d",&pass_choice);
        switch(pass_choice){
            case 1: goto ch_pass;
                    break;
            case 2: Customer_Menu(c);
                    break;
            case 3: exit(0);
                    break;
            default: {
                printf("Invalid Input! Press Enter to re-enter your choice!");
                getch();
                goto chice;
            }
        }
    }
    nw_pass: Bank_Label();
    printf("New password: ");
    for (int i = 0; i < 26; i++) {
        char ch = getch();
        if (ch != 13) {
            New_Password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
    printf("\n\n\nConfirm Password: ");
    for (int i = 0; i < 26; i++) {
        char ch = getch();
        if (ch != 13) {
            Confirm_New_Password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
    if(strcmp(New_Password,Confirm_New_Password)!=0){
        printf("\n\n\tOops! Confirm Password doesn't match with the provisional new password!");
        printf("\n\n\tPress Enter to re-enter your password...");
        getch();
        goto nw_pass;
    }
    strcpy(c.Password,New_Password);
    cust temp;
    FILE *fp, *f_temp;
    fp=fopen("Customers.bin","rb");
    f_temp=fopen("temp.bin","ab");
    while(fread(&temp,sizeof(temp),1,fp)){
        if(strcmp(temp.Username,c.Username)){
            fwrite(&c,sizeof(c),1,f_temp);
        }
        fwrite(&temp,sizeof(temp),1,f_temp);
    }
    fclose(fp);
    fclose(f_temp);
    remove("Customers.bin");
    rename("temp.bin","Customers.bin");

    printf("\n\n\n\n\t\tPassword changed successfully!");
    YourChoice: printf("\n\n\nPlease select to proceed:-");
    printf("\n\n\n\t1. Return to Menu.");
    printf("\n\n\t2. Exit.");
    printf("\n\n\nYour Choice: ");
    int yr_choice;
    scanf("%d",&yr_choice);
    switch(yr_choice){
        case 1: Customer_Menu(c);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("Invalid Input! Press Enter to re-enter your choice...");
            getch();
            goto YourChoice;
        }
    }
}

void Manager_Menu(mngr m){
    Mngr_Choice: Bank_Label();
    printf("Name: %s %s\n\n\n",m.Name);
    printf("Services Available: ");
    gotoxy(10,17);
    printf("\n\n\n\t\t1. List all Customers.");
    printf("\n\n\t\t2. Exit.");

    int Manager_Choice;
    printf("\n\n\nYour Choice: ");
    scanf("%d",&Manager_Choice);
    char Garbage=getchar();

    switch(Manager_Choice){
        case 1: List_Accounts(m);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice...");
            getch();
            goto Mngr_Choice;
        }
    }

}

void List_Accounts(mngr m){
    List: Bank_Label();
    printf("Following customers are present in United Banks of India:-\n\n\n");
    FILE *fp;
    fp=fopen("Customers.bin","rb");
    cust temp;
    int i=1;
    while(fread(&temp,sizeof(temp),1,fp)){
        printf("%d. Name: %s %s * Age: %d * Mobile: %s * Email: %s * Account Type: %s * Opening Date: %s\n\n",i, temp.FName, temp.LName, temp.age, temp.Mobile, temp.Email, temp.Account_Type, ctime(&temp.Opening_Date));
        i++;
    }
    fclose(fp);

    printf("\n\n\nPlease select to proceed:-");
    printf("\n\n\t1. View Complete Profile.");
    printf("\n\n\t2. Exit.");
    printf("\n\n\nYour Choice: ");

    int List_Choice;
    scanf("%d",&List_Choice);
    char Garbage= getchar();

    switch(List_Choice){
        case 1: Manager_View_Profile(m);
                break;
        case 2: exit(0);
                break;
        default: {
            printf("\n\nInvalid Input! Press Enter to re-enter your choice...");
            getch();
            goto List;
        }
    }
}

void Manager_View_Profile(mngr m){
    Mngr_vw_pro: Bank_Label();
    printf("Following customers are present in United Banks of India:-\n\n\n");
    FILE *fp;
    fp=fopen("Customers.bin","rb");
    cust temp;
    int i=1;
    while(fread(&temp,sizeof(temp),1,fp)){
        printf("%d. Name: %s %s * Age: %d * Mobile: %s * Email: %s * Opening Date: %s\n\n",i, temp.FName, temp.LName, temp.age, temp.Mobile, temp.Email, ctime(&temp.Opening_Date));
        i++;
    }//(i-1) is the total number of customers.
    fclose(fp);
    printf("\n\n\nPlease enter the serial number corresponding to the customer whose profile you want to view: ");
    int serial_no;
    scanf("%d",&serial_no);
    if(serial_no>(i-1)||serial_no<1){
        printf("\n\n\n\t\tInvalid Input! Press Enter to re-enter your choice...");
        getch();
        goto Mngr_vw_pro;
    }
    else{
        int j=1;
        fopen("Customers.bin","rb");
        while(fread(&temp,sizeof(temp),1,fp)){
            if(serial_no==j){
                fclose(fp);
                s_no: Bank_Label();
                printf("1. Name: %s %s.\n",temp.FName,temp.LName);
                printf("2. Username: %s.\n",temp.Username);
                printf("3. Father's Name: %s.\n",temp.Father_Name);
                printf("4. Age: %d.\n",temp.age);
                printf("5. Sex: %s.\n",temp.Sex);
                printf("6. Occupation: %s.\n",temp.Occupation);
                printf("7. Nationality: %s.\n",temp.Nationality);
                printf("8. Category: %s.\n",temp.Category);
                printf("9. Aadhar ID Number: %s.\n",temp.Aadhar);
                printf("10. PAN ID Number: %s.\n",temp.PAN);
                printf("11. Mobile Number: %s.\n",temp.Mobile);
                printf("12. Email ID: %s.\n",temp.Email);
                printf("13. Address: %s, %s, %s, %s, PIN Code: %s.\n",temp.Residence,temp.District,temp.State,temp.Country,temp.PIN);
                printf("14. Account Type: %s.\n",temp.Account_Type);
                printf("15. Opening Date: %s",ctime(&temp.Opening_Date));

                printf("\n\n\nPlease select to proceed:-");
                printf("\n\n\t\t1. Remove this Customer.");
                printf("\n\n\t\t2. List all Customers.");
                printf("\n\n\t\t3. Exit.");
                printf("\n\n\nYour Choice: ");

                int s_choice;
                scanf("%d",&s_choice);
                char Garbage=getchar();

                switch(s_choice){
                    case 1: {
                        my_chice: Bank_Label();
                        gotoxy(50,15);
                        printf("Are you sure you want to remove this customer?");
                        gotoxy(60,18);
                        printf("1. Yes");
                        gotoxy(70,18);
                        printf("2. No");
                        gotoxy(50,21);
                        printf("Your Choice: ");
                        
                        int my_choice;
                        scanf("%d",&my_choice);
                        Garbage=getchar();

                        switch(my_choice){
                            case 1: {
                                FILE *f_temp;
                                fp=fopen("Customers.bin","rb");
                                f_temp=fopen("temp.bin","ab");
                                cust temp2;
                                while(fread(&temp2,sizeof(temp2),1,fp)){
                                    if(strcmp(temp.Username,temp2.Username)==0){
                                        continue;
                                    }
                                    fwrite(&temp2,sizeof(temp2),1,f_temp);
                                }
                                fclose(f_temp);
                                fclose(fp);
                                remove("Customers.bin");
                                rename("temp.bin","Customers.bin");
                                fp=fopen("Money.bin","rb");
                                f_temp=fopen("temp.bin","ab");
                                money mo_temp;
                                while(fread(&mo_temp,sizeof(mo_temp),1,fp)){
                                    if((strcmp(temp.Username,mo_temp.Username_from)==0 && strcmp("Cash Withdrawl",mo_temp.Username_to)==0)||(strcmp(temp.Username,mo_temp.Username_to)==0 && strcmp("Cash Deposit",mo_temp.Username_from)==0)){
                                        continue;
                                    }
                                    fwrite(&mo_temp,sizeof(mo_temp),1,f_temp);
                                }
                                fclose(fp);
                                fclose(f_temp);
                                remove("Money.bin");
                                rename("temp.bin","Money.bin");
                                Bank_Label();
                                printf("Account removed successfully!");
                                printf("\n\n\nPress Enter to again list all the customers...");
                                getch();
                                List_Accounts(m);
                            }
                            case 2: goto s_no;
                                    break;
                            default: {
                                printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice...");
                                getch();
                                goto my_chice;
                            }
                        }
                        break;
                    }
                    case 2: List_Accounts(m);
                            break;
                    case 3: exit(0);
                            break;
                    default: {
                        printf("\n\n\t\tInvalid Input! Press Enter to re-enter your choice...");
                        getch();
                        goto s_no;
                    }
                }
                break;
            }
            j++;
        }
    }
    
}

void Bank_Label(){
    system("cls");
    gotoxy(70,2);
    printf("United Bank of India");
    gotoxy(71,3);
    printf("It begins with you!");
    gotoxy(0,10);
}

void Welcome_Screen(){
    system("cls");
    gotoxy(70,11);
    printf("United Bank of India");
    gotoxy(71,12);
    printf("It begins with you!");
    gotoxy(70,25);
    printf("Platform developed by:");
    gotoxy(75,27);
    printf("1. Baibhav Kumar");
    gotoxy(75,29);
    printf("2. Harshit Goyal");
    gotoxy(75,31);
    printf("3. Abhay Rajput");
    gotoxy(0,35);
    printf("Loading");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(2);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
 
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}