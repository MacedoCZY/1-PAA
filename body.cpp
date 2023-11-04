//g++ body.cpp -o exec.x -masm=intel
#include <stdio.h>
#include <iostream>
#include "bubbleSort.hpp"
#include <sys/stat.h>

int main(int argc, char* argv[]){
    BubbleSort bs;
    FILE *archive;
    archive = fopen(argv[1], "rt");
    
    if(argc < 2){
        cout << "Erro args!" << endl;
    }else if(archive != NULL){
        bs.classic();
    
    }else{
        cout << "Erro open archive!" << endl;
    }
}
