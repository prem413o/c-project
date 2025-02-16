#include<stdio.h>
#include<string.h>
void create_account();
void Deposit_money();
void Withdraw_money();
void check_balance();

typedef struct bank{
    long int acc_no;
    char name[100];
    float balance;
}Bank;

int main(){
    int choice;
    while(1){
    printf("\n***BANK MANAGEMENT SYSTEM***");
    printf("\n1. Create account");
    printf("\n2. Deposit money");
    printf("\n3. Withdraw money");
    printf("\n4. Check balance");
    printf("\n5. Exit");
    printf("\nNow choose the following option: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1://create account
        create_account();
        break;
    case 2://deposit money
        Deposit_money();
        break;
    case 3://withdraw money
        Withdraw_money();
        break;
    case 4://check balance
        check_balance();
        break;
    case 5://exit
        printf("\nClosing the bank, thank you for visiting.");
        return 0;
        break;
    default:
        printf("\nInvalid choise, Please try again later.");
        break;
    }


    }
    return 0;
}

void create_account(){
    Bank acc;
    FILE *file;
    file = fopen("Account.dat", "ab+");
    if(file==NULL){
        printf("\nunable to open file");
        return;
    }
    printf("\nEnter your name: ");
    getchar();
    fgets(acc.name,sizeof(acc.name),stdin);
    size_t len=strlen(acc.name);
    if(len >0 && acc.name[len - 1]=='\n'){
        acc.name[len -1] ='\0';
    }
    printf("Enter your account number: ");
    scanf("%ld", &acc.acc_no);
    fwrite(&acc.name,sizeof(acc), 1,file);
    acc.balance=0;

    fclose(file);
    printf("\nSuccessfully created your account!! ");
    printf("your intitial balance is %.2f", acc.balance);
}
void Deposit_money(){
   Bank acc_d;
   long int accno;
   float money;
   FILE *file;
   file = fopen("Account.dat", "rb+");
   if(file==NULL){
    printf("\nUnable to open file!!");
    return;
   }
   printf("\nEnter your account number: ");
   scanf("%ld", &accno);
   printf("Enter the amount you wish to deposit Rs.");
   scanf("%f", &money);
   
   while (fread(&acc_d,sizeof(acc_d),1,file))
   {
    if(accno ==acc_d.acc_no){
        acc_d.balance += money;
        fseek(file, -sizeof(acc_d), SEEK_CUR);
        
        fwrite(&acc_d,sizeof(acc_d),1,file);
        printf("\nSuccessfully deposited money Rs.%f and your current balance is %.2f",money,acc_d.balance);
        fclose(file);
        return;
    }
   }
   fclose(file);
   printf("\nEntered account number %ld is not found in our file", accno);
   
}
void Withdraw_money(){
    printf("withdraw money");
}
void check_balance(){
    Bank acc_r;
    long int no;
    FILE *file;
    file = fopen("Account.dat", "rb");
    if(file ==NULL){
        printf("\numble to open file");
        return;
    }
    printf("\nEnter your account number: ");
    scanf("%ld", &no);
    while(fread(&acc_r,sizeof(acc_r),1,file)){
        if(no==acc_r.acc_no){
            printf("\nYour current balance is %.2f", acc_r.balance);
            fclose(file);
            return;
        }
    
    }
    fclose(file);
    printf("\nthe account doesnot found %ld in our recored", no);

}
