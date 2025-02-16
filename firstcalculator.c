#include<stdio.h>
#include<math.h>
void print_menu();
double division(double,double);
double modulus(int , int );

int main(){
    int choice;
    double first,second,result;
    while(1){
        print_menu();
        scanf("%d", &choice);
        if(choice==7){
            break;
        }
        if(choice<1 || choice>7){
            fprintf(stderr,"invalid menu choice");
            continue;
        }


        printf("\nPlease Enter first number:");
        scanf("%lf", &first);
        printf("Now,Enter second number:");
        scanf("%lf", &second);

        switch(choice)
        {
        case 1:
             result = first + second;
            break;
        case 2://subtract
            result = first - second;
            break;
        case 3://multiply
            result = first*second;
            break;
        case 4://divide
            result = division(first, second);
            break;
        case 5://modulus
            result =modulus(first, second);
            break;
        case 6://power
            result = pow(first,second);
            break;
        
        }
        if(!isnan(result)){
        printf("\nResult of this operation is: %.2lf", result);
        }

    }
   
    return 0;

}
double modulus(int  a, int b){
    if(b==0){
        fprintf(stderr, "invalid argument for Modulus");
        return -1;
    }else{
        return a % b;
        }
}

double division(double a , double b){
    if(b==0){
        fprintf(stderr, "invalid argument for Division");
        return NAN;
    }else{
        return a/b;
    }

}
void print_menu(){
    printf("\n\n-----------------------------\n");
    printf("Welcome to Simple calculator\n");
    printf("Choose one of the following\n");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");

    printf("\n5. Modulus");
    printf("\n6. power");
    printf("\n7. Exit");
    printf("\nNow Enter your choice:");

}