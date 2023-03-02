// Fundamental data structure & algorithm
// HW1_02_24_2023
// C language, Encoding = UTF-8
// written by 醫工三 b812109032 許家齊

#include <stdio.h>
#include <assert.h>
// declare functions
void decimal_to_binary(int num);
void decimal_to_hexadecimal(int num);
void print_binary(int num);
void print_hexadecimal(int num);

// main function
void main(){
    int dec = 0;
    printf("Please enter an decimal integer between 0 to 255\n");
    while (scanf("%d", &dec) != 1) {// make sure the input was an integer
        printf("Input errors, please re-enter :");
        // clear input buffer
        while (getchar() != '\n');
    }
    assert(dec >= 0 && dec <= 255);// check the integer range
    printf("Decimal = %d\n", dec);
    print_binary(dec);
    print_hexadecimal(dec);
}


void decimal_to_binary(int num) {
    if (num > 1) {
        decimal_to_binary(num / 2);
    }
    printf("%d", num % 2);// print remainder
}


void decimal_to_hexadecimal(int num) {
    if (num > 15) {
        decimal_to_hexadecimal(num / 16);
    }
    int remainder = num % 16;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + remainder - 10);
    }
}

// print binary 
void print_binary(int num){
    printf("Binary = ");
    decimal_to_binary(num);
    printf("\n");
}

// print hexadecimal
void print_hexadecimal(int num){
    printf("Hexadecimal = ");
    decimal_to_hexadecimal(num);
    printf("\n");
}