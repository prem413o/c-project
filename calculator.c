#include<stdio.h>
#include<math.h>
void print_menu();


int main(){

    int choice;
    double first,second, result;
    while(1) {
        print_menu();
        scanf("%d", &choice);
        if(choice==7){
            break;
        }

        printf("\nPlease enter first number:");
        scanf("%lf", &first);
        printf("Now, Enter second number:");
        scanf("%lf", &second);

        switch (choice)
        {
        case 1: //add
            result = first + second;
            break;
        case 2: //subtract
            result = first - second;
            break;
        case 3: //multiply
            result = first*second;
            break;
        case 4: //divide
            result = first / second;
            break;
        case 5: //moduluus
            result = (int)first % (int)second;
            break;
        case 6: //power 
            result = pow(first,second);
            break;
        default:
            break;
        }
        printf("\nResult of operation is: %.2lf",result);
    }
    

    return 0;
}
void print_menu(){
     printf("\nWelcome to Simple Calculator\n");
        printf("\nChoose one of the following option:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. divide\n");
        printf("5. Modulus\n");
        printf("6. power\n");
        printf("7.Exit");
        printf("\n Now enter your choice:");

}