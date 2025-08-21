// made by pawan kumar
// an easy approach to c graphics via terminal
// directly usable through include file via #include line.cpp

// colour_code can be from 0 to 255
// search on google for ANSI colour code for detailed info

// functions are here
// line.create -> for line drawing using DDA algorithm
// syntax -> line.create(x1, y1, x2, y2, colour_code);

#include <iostream>

class graphics_by_pawan {
public:
    void create(int x1, int y1, int x2, int y2, int colour_code) {
        // security -
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
            std::cerr << "error: coordinates cannot be negative\n";
            return;
        }
        if (colour_code < 0 || colour_code > 255) {
            std::cerr << "error: colour code should be between 0 and 255\n";
            return;
        }

        //  main code -
        int dx = x2 - x1, dy = y2 - y1;
        int steps = (std::abs(dx) > std::abs(dy)) ? std::abs(dx) : std::abs(dy);

        float xi = dx / (float)steps;
        float yi = dy / (float)steps;

        float x = x1, y = y1;

        std::cout << "\033[48;5;" << colour_code << "m";

        for (int i = 0; i <= steps; i++) {
            std::cout << "\033[" << (int)(y + 0.5) << ";" << (int)(x + 0.5) << "H ";
            x += xi;
            y += yi;
        }

        std::cout << "\033[0m" << std::flush;
    }
} line;
