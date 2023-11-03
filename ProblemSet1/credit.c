#include <cs50.h>
#include <stdio.h>

int getLength(long Number);
long getInverse(long Number , int length);
int getSum(long Number , int length);
void check(long Number , int sum , int length);

int main(void)
{
    long Number;
    do{
        Number = get_long("Number:");
    }while(Number <= 0);

    int length = getLength(Number); //get the length of the digit number

    long inverse = getInverse(Number , length);

    int sum = getSum(inverse , length);  //caculate the sum

    check(Number , sum , length); // check the answer

    //printf("lenegth = %d\ninverse = %ld\nsum = %d\n", length,inverse,sum);
}

int getLength(long Number){
    int length = 0;
    while(Number != 0){
        length++;
        Number /= 10;
    }
    return length;
}

long getInverse(long Number , int length){
    long inverse = 0;
    for(int i = 0; i < length; i++){
        inverse += Number % 10;
        Number /= 10;
        inverse *= 10;
    }
    inverse /= 10;
    return inverse;
}

int getSum(long inverseNumber , int length){
    int sum = 0;
    int multiplyResult= 0;
    while(inverseNumber != 0){
        multiplyResult = 2 * (int)(inverseNumber % 10); //get the multiply number
        if(multiplyResult >= 10){
            sum = sum + 1 + multiplyResult % 10; // 10<= multiplyResult <= 18
        }
        else{
            sum += multiplyResult;
        }
        inverseNumber /= 10;
        sum += (int)(inverseNumber % 10); //get the not multiply number
        inverseNumber /= 10;
    }
    return sum;
}

void check(long Number , int sum , int length){
    for(int i = 0; i < length - 2; i++){
        Number /= 10;
    }
    int first2Number = (int)(Number);
    //printf("first2Number = %d\n",first2Number);
    if(length < 13 || length > 16){
        printf("INVALID\n");
    }
    else if(sum % 10 != 0){
        printf("INVALID\n");
    }
    else if((first2Number == 34 || first2Number == 37) && length == 15){
        printf("AMEX\n");
    }
    else if(first2Number >= 51 && first2Number <= 55 && length == 16){
        printf("MASTERCARD\n");
    }
    else if((first2Number >= 40 && first2Number <= 49) && (length == 13 || length == 16)){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}
