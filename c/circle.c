// made by pawan kumar
// an easy approach to C graphics via terminal
// directly usable through include file via #include circle.c

// colour_code is from 0 to 255
// search on Google for ANSI colour code for detailed info

// functions are here
// circle_empty -> for empty circle case
// syntax -> circle_empty(radius, row, column, colour_code);

// circle_fill -> for filled circle case
// syntax -> circle_fill(radius, row, column, colour_code);

#include <stdio.h>

void circle_empty(int radius, int row, int column, int colour_code){
    // security
    if((row - radius) < 1 || (column - radius) < 1){
        printf("error: circle is getting out of terminal\n");
        return;
    } else if(row < 0 || column < 0 || radius < 0){
        printf("row, column, or radius can't be less than 1\n");
        return;
    } else if(colour_code < 0 || colour_code > 255){
        printf("colour code should be between 0 to 255\n");
        return;
    }

    // main code -
    int i, j;
    int distance;
    printf("\033[48;5;%dm", colour_code);
    for(i = -radius; i <= radius; i++){
        for(j = -radius; j <= radius; j++){
            distance = i*i + j*j;
            if(distance >= radius*radius - radius && distance <= radius*radius + radius){
                printf("\033[%d;%dH ", row + i, column + j);
            }
        }
    }
    printf("\033[0m");
    fflush(stdout);
}

void circle_fill(int radius, int row, int column, int colour_code){
    // security -
    if((row - radius) < 1 || (column - radius) < 1){
        printf("error: circle is getting out of terminal\n");
        return;
    } else if(row < 0 || column < 0 || radius < 0){
        printf("row, column, or radius can't be less than 1\n");
        return;
    } else if(colour_code < 0 || colour_code > 255){
        printf("colour code should be between 0 to 255\n");
        return;
    }

    // main code -
    int i, j;
    int distance;
    printf("\033[48;5;%dm", colour_code);
    for(i = -radius; i <= radius; i++){
        for(j = -radius; j <= radius; j++){
            distance = i*i + j*j;
            if(distance <= radius*radius){
                printf("\033[%d;%dH ", row + i, column + j);
            }
        }
    }
    printf("\033[0m");
    fflush(stdout);
}
