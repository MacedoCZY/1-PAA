#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
using namespace  std;

class BubbleSort{
    
    public:
        void classic();
        void flag();
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
    

    for(double i = 0, k = 0 ; i < qts; i++){       
        if (k == 5) {
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
            
            "inc r11;"
            "mov r12d, %[qts];"
            "dec r12;"
            "cmp r11d, r12d;"
            "jl for2;"

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

void BubbleSort::flag(){
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
    

    for(double i = 0, k = 0 ; i < qts; i++){       
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
        "for11:;"
            
            "xor r15, 15;"
            "xor r11, r11;"
            "xor r12, r12;"
            "mov rbx, rax;"
            "for22:;"
                
                "movsd xmm1, [rbx+r11*8];"
                "mov r12, r11;"
                "inc r12;"
                "movsd xmm2, [rbx+r12*8];"
                "movsd xmm3, xmm1;"
                "comisd xmm1, xmm2;"
            
                    "jb continue1;"
                    "inc r15;"
                    "movsd [rbx+r11*8], xmm2;"
                    "movsd [rbx+r12*8], xmm3;"
                
                    "continue1:;"
            
            "inc r11;"
            "mov r12d, %[qts];"
            "dec r12;"
            "cmp r11d, r12d;"
            "jl for22;"
        
        "cmp r15, 0x0;"
        "je finish;"
        "inc r10;"
        "cmp r10d, %[qts];"
        "jl for11;"
        "finish:;"
        :
        :[vet] "m" (vet.at(0)), [teste] "m"(teste), [qts] "m" (qts)
        :"cc");

   cout << endl << endl << endl;

   for(double i = 0, k = 0 ; i < vet.size(); i++){       
        if (k == 5) {
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

