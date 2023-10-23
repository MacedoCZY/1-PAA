#include <iostream>

using namespace  std;

class BubbleSort{
    
    public:
        void classic();
};

void BubbleSort::classic(){
    int var;
    asm("mov rax, %[var];"
        :
        :[var] "m" (var)
        :"cc");
}
