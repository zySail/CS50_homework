#include <cs50.h>
#include <stdio.h>

int getLength(long Number);
int getSum(long Number , int length);
void check(long Number , int sum , int length);

int main(void)
{
    long Number;
    do{
        Number = get_long("Number:");
    }while(Number <= 0);

    int length = getLength(Number); //get the length of the digit number

    int sum = getSum(Number , length);  //caculate the sum

    check(Number , sum , length); // check the answer

    //printf("lenegth = %d\nsum = %d\n", length , sum);
}

int getLength(long Number){
    int length = 0;
    while(Number != 0){
        length++;
        Number /= 10;
    }
    return length;
}

int getSum(long Number , int length){
    int sum = 0;
    int multiplyResult= 0;
    while(Number != 0){
        sum += (int)(Number % 10); //get the not multiply number
        Number /= 10;
        multiplyResult = 2 * (int)(Number % 10); //get the multiply number
        if(multiplyResult >= 10){
            sum = sum + 1 + multiplyResult % 10; // 10 <= multiplyResult <= 18
        }
        else{
            sum += multiplyResult;
        }
        Number /= 10;
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
