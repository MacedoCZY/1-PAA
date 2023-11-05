#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <limits.h>
#include <chrono>

using namespace  std;

class BubbleSort{
    public:
		int qts;
		FILE *archive;
		bool prt = false;
		
    public:
		BubbleSort(int size, FILE *arch){
			qts = size;
			archive = arch;
		}
		void setArch(FILE *arch){
			archive = arch;
		}
		void setPrint(bool print){
			prt = print;
		}
        void classic();
        void flag();
};

void BubbleSort::classic(){
    std::vector<double> vet;
    vet.reserve(qts);
	
	double aux = 0;
	while(!feof(archive)){
		fscanf(archive, "%le", &aux);
		//cout << aux << endl;
		vet.push_back(aux);
	}
    
	
	cout << qts << " " << vet.size() << endl;
	if(prt == true){
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
		cout << endl << endl;
    }
	
	auto inicio = std::chrono::high_resolution_clock::now();
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
        :[qts] "m" (qts), [vet] "m" (vet.at(0))
        :"cc");
	auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    
	if(prt == true){
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
		cout << endl << endl;
	}
	
	long long seconds = std::chrono::duration_cast<std::chrono::seconds>(resultado).count();
	cout << seconds << " sec" << endl;
	
	vet.erase(vet.begin(), vet.end());
	vet.shrink_to_fit();
}

void BubbleSort::flag(){
    std::vector<double> vet;
    vet.reserve(qts);
	
	int aux = 0;
	while(!feof(archive)){
		fscanf(archive, "%d", &aux);
		 vet.push_back(aux);
	}
    
	if(prt == true){
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
		cout << endl << endl;
	}
	
	auto inicio = std::chrono::high_resolution_clock::now();
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
        :[vet] "m" (vet.at(0)), [qts] "m" (qts)
        :"cc");
		
	auto resultado = std::chrono::high_resolution_clock::now() - inicio;
	
	if(prt == true){
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
	   cout << endl << endl;
	}
	
	long long seconds = std::chrono::duration_cast<std::chrono::seconds>(resultado).count();
	cout << seconds <<  " sec" << endl << endl;

	vet.erase(vet.begin(), vet.end());
	vet.shrink_to_fit();
}