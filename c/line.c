// made by pawan kumar
// an easy approach to c graphics via terminal
// directly usable through include file via #include line.c

// colour_code can be from 0 to 255
// search on google for ANSI colour code for detailed info

// functions are here
// line_create -> for line drawing using DDA algorithm
// syntax -> line_create(x1, y1, x2, y2, colour_code);

#include <stdio.h>
#include <stdlib.h>

void line_create(int x1, int y1, int x2, int y2, int colour_code) {
    // security -
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        fprintf(stderr, "error: coordinates cannot be negative\n");
        return;
    }
    if (colour_code < 0 || colour_code > 255) {
        fprintf(stderr, "error: colour code should be between 0 and 255\n");
        return;
    }

    // main code -
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xi = dx / (float) steps;
    float yi = dy / (float) steps;

    float x = x1, y = y1;

    printf("\033[48;5;%dm", colour_code);

    for (int i = 0; i <= steps; i++) {
        printf("\033[%d;%dH ", (int)(y + 0.5), (int)(x + 0.5));
        x += xi;
        y += yi;
    }

    printf("\033[0m");
    fflush(stdout);
}
