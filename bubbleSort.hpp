#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
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
        aux = random() % 100 + 1;
        vet.push_back(aux);
    }
    

    for(double i = 0, k = 0 ; i < vet.size(); i++){       
        if (k == 2) {
            //cout << setprecision(4) << vet.at(i) << "\t\t" << endl;
            printf("%.4lf\t\t\n", vet.at(i)); 
            k = 0;
        }else{
            //cout << setprecision(4) << vet.at(i) << "\t\t";
            printf("%.4lf\t\t", vet.at(i)); 
            k++;
        }
    }

    double teste = 0;

    asm("lea rax, %[vet];"
        "xor r10, r10;"
        "for1:;"
            
            "xor r11, r11;"
            "xor r12, r12;"
            "mov rbx, rax;"
            "mov r12, r10;"
            "shl r12, 3;"
            "add rbx, r12;"
            "mov r11, r10;"
            "for2:;"
            
                "movsd xmm1, [rbx+r11*8];"
                "mov r12, r11;"
                "inc r12;"
                "movsd xmm2, [rbx+r12*8];"
                "movsd xmm3, xmm1;"
                "comisd xmm1, xmm2;"
            
                    "jb continue;"
                    "flag:;"
                    "movsd [rbx+r11*8], xmm2;"
                    "movsd [rbx+r12*8], xmm3;"
                
                    "continue:;"
            
            "add rbx, 8;"
            "inc r11;"
            "cmp r11d, %[qts];"
            "jle for2;"

        "inc r10;"
        "cmp r10d, %[qts];"
        "jl for1;"
        :
        :[vet] "m" (vet.at(0)), [teste] "m"(teste), [qts] "m" (qts)
        :"cc");

   cout << endl << endl << endl;

   for(double i = 0, k = 0 ; i < vet.size(); i++){       
        if (k == 2) {
            //cout << setprecision(4) << vet.at(i) << "\t\t" << endl;
            printf("%.4lf\t\t\n", vet.at(i)); 
            k = 0;
        }else{
            //cout << setprecision(4) << vet.at(i) << "\t\t";
            printf("%.4lf\t\t", vet.at(i)); 
            k++;
        }
    }   
}
