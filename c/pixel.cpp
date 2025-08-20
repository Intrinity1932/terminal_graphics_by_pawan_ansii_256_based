// made by pawan kumar
// an easy aproach to c graphics via terminal
// directly usable through include file via #include pixel.cpp

// colour_code can be from 0 to 255
// search on google for ansii colour code for detailed info

// functions are here
// pixel.single -> for single pixel case
// synatax -> pixel.single(row, collumnn, colour_code);

// pixel.adjustable -> for adjustable size of pixel
// synatx -> pixel.adjustable(row_1, collumn_1, row_2, collumn_2, colour_code);

#include <iostream>

class graphics_by_pawan{
public:

    void single(int row, int column, int colour_code){
        // secuirity
        if(colour_code<0 || colour_code>255){
            std::cerr << "colour code should be betwen 0 to 255" << "\n";
            return;
        }else if(row<1 || column<1){
            std::cerr << "row or collumn can't be less than 1" << "\n";
            return;
        }
        // main code
        std::cout << "\033[" << row << ";" << column << "H";
        std::cout << "\033[48;5;" << colour_code << "m " << "\033[0m" << std::flush;
        return;
    }

    void adjustable(int row_1, int column_1, int row_2, int column_2, int colour_code){
        // security
        if(colour_code<0 || colour_code>255){
            std::cerr << "colour code should be betwen 0 to 255" << "\n";
            return;
        }else if(row_1<1 || column_1<1){
            std::cerr << "row or collumn can't be less than 1" << "\n";
            return;
        }else if(row_2<row_1 || column_2<column_1){
            std::cerr << "row_1 and collumn_1 should be always less than row_2 amd collumn_2" << "\n";
            return;
        }
        // main code
        std::cout << "\033[" << row_1 << ";" << column_1 << "H";
        std::cout << "\033[48;5;" << colour_code << "m";
        for(int i=row_1; i<=row_2; i++){
            std::cout << "\033[" << i << ";" << column_1 << "H";
            for(int j=column_1; j<=column_2; j++)
                std::cout << " ";
        }
        std::cout << "\033[0m" << std::flush;
        return;
    }
}pixel;
