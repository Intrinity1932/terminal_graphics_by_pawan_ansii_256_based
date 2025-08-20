// made by pawan kumar
// an easy approach to C++ terminal graphics
// directly usable through include file via #include eclipse.cpp

// colour_code is from 0 to 255
// search on Google for ANSI colour codes for detailed info

// WARNING: Terminal characters are not perfectly square, 
// so vertical and horizontal radii may need manual adjustment 
// to make the ellipse look proportional.

// functions are here:
// eclipse.empty -> draws an empty ellipse
// syntax -> eclipse.empty(radius_ud, radius_lr, row, column, colour_code);

// eclipse.fill -> draws a filled ellipse
// syntax -> eclipse.fill(radius_ud, radius_lr, row, column, colour_code);

#include <iostream>

class graphics_by_pawan {
public:
    void empty(int radius_ud, int radius_lr, int row, int column, int colour_code){
        // security
        if(row-radius_ud < 1 || column-radius_lr < 1){
            std::cerr << "Error: circle is getting out of terminal\n";
            return;
        }
        if(row < 0 || column < 0 || radius_ud < 0 || radius_lr < 0){
            std::cerr << "Error: row, column, or radius can't be less than 1\n";
            return;
        }
        if(colour_code < 0 || colour_code > 255){
            std::cerr << "Error: colour code should be between 0 to 255\n";
            return;
        }

        // main code
        int i, j;
        std::cout << "\033[48;5;" << colour_code << "m";
        for(i = -radius_ud; i <= radius_ud; i++){
            for(j = -radius_lr; j <= radius_lr; j++){
                double distance = (double)i*i / (radius_ud*radius_ud) + (double)j*j / (radius_lr*radius_lr);
                if(distance >= 0.85 && distance <= 1.15) // thin ring
                    std::cout << "\033[" << row+i << ";" << column+j << "H ";
            }
        }
        std::cout << "\033[0m" << std::flush;
    }

    void fill(int radius_ud, int radius_lr, int row, int column, int colour_code){
        // security
        if(row-radius_ud < 1 || column-radius_lr < 1){
            std::cerr << "Error: circle is getting out of terminal\n";
            return;
        }
        if(row < 0 || column < 0 || radius_ud < 0 || radius_lr < 0){
            std::cerr << "Error: row, column, or radius can't be less than 1\n";
            return;
        }
        if(colour_code < 0 || colour_code > 255){
            std::cerr << "Error: colour code should be between 0 to 255\n";
            return;
        }

        // main code
        int i, j;
        std::cout << "\033[48;5;" << colour_code << "m";
        for(i = -radius_ud; i <= radius_ud; i++){
            for(j = -radius_lr; j <= radius_lr; j++){
                double distance = (double)i*i / (radius_ud*radius_ud) + (double)j*j / (radius_lr*radius_lr);
                if(distance <= 1.0)
                    std::cout << "\033[" << row+i << ";" << column+j << "H ";
            }
        }
        std::cout << "\033[0m" << std::flush;
    }
} eclipse;
