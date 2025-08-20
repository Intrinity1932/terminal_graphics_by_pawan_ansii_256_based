// made by pawan kumar
// an easy aproach to c graphics via terminal
// directly usable through include file via #include circle.cpp

// colour_code is from 0 to 255
// search on google for ansii colour code for detailed info

// functions are here
// circle.empty -> for empty circle case
// synatax -> circle.empty(radius, row, column, colour_code);

// circle.fill -> for filled circle case
// synatax -> circle.fill(radius, row, column, colour_code);


#include <iostream>

class graphics_by_pawan{
public:
    void empty(int radius, int row, int column, int colour_code){
        
        // security -
        if((row - radius)<1 || (column - radius)<1){
            std::cerr << "error: circle is getting out of terminal";
            return;
        }else if(row<0 || column<0 || radius<0){
            std::cerr << "row or column or radius can't be less than 1";
            return;
        }else if(colour_code<0 || colour_code>255){
            std::cerr << "colour code should be betwen 0 to 255" << "\n";
            return;
        }

        // main code -
        int distance, i, j;
        std::cout << "\033[48;5;" << colour_code << "m";
        for(i = -radius; i <= radius; i++) {
            for(j = -radius; j <= radius; j++){
                distance = i*i + j*j;
                if (distance >= radius*radius - radius && distance <= radius*radius + radius){
                    std::cout << "\033[" << row+i << ";" << column+j << "H ";}
                }
            }
        std::cout << "\033[0m" << std::flush;
    }

    void fill(int radius, int row, int column, int colour_code){

        // security -
        if((row - radius)<1 || (column - radius)<1){
            std::cerr << "error: circle is getting out of terminal";
            return;
        }else if(row<0 || column<0 || radius<0){
            std::cerr << "row or column or radius can't be less than 1";
            return;
        }else if(colour_code<0 || colour_code>255){
            std::cerr << "colour code should be betwen 0 to 255" << "\n";
            return;
        }

        // main code -
        int distance, i, j;
        std::cout << "\033[48;5;" << colour_code << "m";
        for(i = -radius; i <= radius; i++) {
            for(j = -radius; j <= radius; j++){
                distance = i*i + j*j;
                if (distance <= radius*radius){
                    std::cout << "\033[" << row+i << ";" << column+j << "H ";}
                }
            }
        std::cout << "\033[0m" << std::flush;
    }
}circle;
