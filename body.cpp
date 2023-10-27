//g++ body.cpp -o exec.x -masm=intel -lmysqlcppconn
#include <stdio.h>
#include <iostream>
#include "bubbleSort.hpp"

int main(){
    BubbleSort bs;
    bs.classic();
}
