#include <cstdlib>
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
        //cin >> aux;
        aux = random();
        vet.push_back(aux);
    }
    

    for(int i = 0, k = 0 ; i < vet.size(); i++){
        
        if (k == 2) {
            cout << vet.at(i) << "\t\t" << endl;
            k = 0;
        }else{
            cout << vet.at(i) << "\t\t";
            k++;
        }
    }

    double jegue = 0;
    

    asm("lea rax, %[vet];"
        "mov rbx, [rax+8];"
        "mov %[jegue], rbx;"
        :
        :[vet] "m" (vet.at(0)), [jegue] "m"(jegue) 
        :"cc");

    cout << jegue << endl;


}
