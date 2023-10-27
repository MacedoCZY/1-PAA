#include <iostream>
#include <vector>
using namespace  std;

class BubbleSort{
    
    public:
        void classic();
};

void BubbleSort::classic(){
    int qts = 0;
    cout << "Size vector: ";
    cin >> qts;
    std::vector<double> vet;
    vet.reserve(qts);

    double aux = 0;
    for(int i = 0; i < qts; i++){
        cin >> aux;
        vet.push_back(aux);
    }
    asm("mov rax, %[vet];"
        :
        :[vet] "m" (vet)
        :"cc");
}
