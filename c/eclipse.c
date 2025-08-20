// made by pawan kumar
// an easy approach to C terminal graphics
// directly usable through include file via #include ellipse.c

// colour_code is from 0 to 255
// search on Google for ANSI colour codes for detailed info

// WARNING: Terminal characters are not perfectly square, 
// so vertical and horizontal radii may need manual adjustment 
// to make the ellipse look proportional.

// functions are here:
// ellipse_empty -> draws an empty ellipse (outline only)
// syntax -> ellipse_empty(radius_ud, radius_lr, row, column, colour_code);

// ellipse_fill -> draws a filled ellipse
// syntax -> ellipse_fill(radius_ud, radius_lr, row, column, colour_code);

#include <stdio.h>

void ellipse_empty(int radius_ud, int radius_lr, int row, int column, int colour_code){
    if(row-radius_ud < 1 || column-radius_lr < 1){
        printf("Error: ellipse is getting out of terminal\n");
        return;
    }
    if(row < 0 || column < 0 || radius_ud < 0 || radius_lr < 0){
        printf("Error: row, column, or radius can't be less than 1\n");
        return;
    }
    if(colour_code < 0 || colour_code > 255){
        printf("Error: colour code should be between 0 to 255\n");
        return;
    }

    int i, j;
    double distance;
    printf("\033[48;5;%dm", colour_code); // ANSI background colour
    for(i = -radius_ud; i <= radius_ud; i++){
        for(j = -radius_lr; j <= radius_lr; j++){
            distance = ((double)i*i)/(radius_ud*radius_ud) + ((double)j*j)/(radius_lr*radius_lr);
            if(distance >= 0.85 && distance <= 1.15) // outline thickness
                printf("\033[%d;%dH ", row+i, column+j);
        }
    }
    printf("\033[0m"); // reset terminal style
    fflush(stdout);
}

void ellipse_fill(int radius_ud, int radius_lr, int row, int column, int colour_code){
    if(row-radius_ud < 1 || column-radius_lr < 1){
        printf("Error: ellipse is getting out of terminal\n");
        return;
    }
    if(row < 0 || column < 0 || radius_ud < 0 || radius_lr < 0){
        printf("Error: row, column, or radius can't be less than 1\n");
        return;
    }
    if(colour_code < 0 || colour_code > 255){
        printf("Error: colour code should be between 0 to 255\n");
        return;
    }

    int i, j;
    double distance;
    printf("\033[48;5;%dm", colour_code); // ANSI background colour
    for(i = -radius_ud; i <= radius_ud; i++){
        for(j = -radius_lr; j <= radius_lr; j++){
            distance = ((double)i*i)/(radius_ud*radius_ud) + ((double)j*j)/(radius_lr*radius_lr);
            if(distance <= 1.0) // fill inside ellipse
                printf("\033[%d;%dH ", row+i, column+j);
        }
    }
    printf("\033[0m"); // reset terminal style
    fflush(stdout);
}
