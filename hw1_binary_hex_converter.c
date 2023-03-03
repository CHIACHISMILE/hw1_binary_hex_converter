// Fundamental data structure & algorithm
// HW1_02_24_2023
// C language, Encoding = UTF-8
// written by 醫工三 b812109032 許家齊

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// declare functions
void decimal_to_binary(int num);
void decimal_to_hexadecimal(int num);
void print_binary(int num);
void print_hexadecimal(int num);

// main function
int main(){
    // declare variable
    int dec;

    while (1) {
        printf("Please enter an integer between 0 and 255 (enter -1 to exit): ");
        if (scanf("%d", &dec) != 1) {
            // If the input is not an integer, clear the input buffer
            while (getchar() != '\n');
            printf("Input error! Please try again.\n");
            continue;
        }

        if (dec == -1) {
            printf("Exiting program...\n");
            break;
        }

        // assert(dec >= 0 && dec <= 255);
        if (dec >= 0 && dec <= 255) {
           break;
        } else {
            printf("Input error! Please try again.\n");
        }
    }
    printf("The integer you entered is: %d\n", dec);
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