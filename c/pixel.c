// made by pawan kumar
// an easy aproach to c graphics via terminal
// directly usable through include file via #include pixel.cpp

// colour_code can be from 0 to 255
// search on google for ansii colour code for detailed info

// functions are here
// pixel_single -> for single pixel case
// synatax -> pixel_single(row, collumnn, colour_code);

// pixel_adjustable -> for adjustable size of pixel
// synatx -> pixel_adjustable(row_1, collumn_1, row_2, collumn_2, colour_code);

#include <stdio.h>

void pixel_single(int , int, int);
void pixel_adjustable(int , int, int, int, int);

void pixel_single(int row, int column, int colour_code){
        // secuirity
        if(colour_code<0 || colour_code>255){
            printf("colour code should be betwen 0 to 255\n");
            return;
        }else if(row<1 || column<1){
            printf("row or collumn can't be less than 1\n");
            return;
        }
        // main code
        printf("\033[%d;%dH", row, column);
        printf("\033[48;5;%dm \033[0m", colour_code);
        fflush(stdout);
        return;
    }

void pixel_adjustable(int row_1, int column_1, int row_2, int column_2, int colour_code){
    // security
    if(colour_code<0 || colour_code>255){
        printf("colour code should be betwen 0 to 255\n");
        return;
    }else if(row_1<1 || column_1<1){
        printf("row or collumn can't be less than 1\n");
        return;
    }else if(row_2<row_1 || column_2<column_1){
        printf("row_1 and collumn_1 should be always less than row_2 amd collumn_2\n");
        return;
    }
    // main code
    printf("\033[%d;%dH", row_1, column_1);
    printf("\033[48;5;%dm", colour_code);
    for(int i=row_1; i<=row_2; i++){
        printf("\033[%d;%dH", i, column_1);
        for(int j=column_1; j<=column_2; j++)
            printf(" ");
    }
    printf("\033[0m");
    fflush(stdout);
    return;
}
