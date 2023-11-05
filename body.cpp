//g++ body.cpp -o exec.x -masm=intel
#include <stdio.h>
#include <iostream>
#include "bubbleSort.hpp"
#include <sys/stat.h>

int archSize(FILE *arch);

int main(int argc, char* argv[]){
    FILE *arch;
    arch = fopen(argv[1], "r");
	
    if(argc < 2){
        cout << "Erro args!" << endl;
    }else if(arch != NULL){
		BubbleSort bs(archSize(arch), arch);
		
		int choice = 0;
		cout << "1 - BubbleSort Classi\n2 - BubbleSort With Flag\n3 - Change file\n4 - Exit" << endl;
		cout << "Choice: ";
		while(cin >> choice){
			if(choice == 1 || choice == 2){
				cout << "Print y/n?" << endl;
				string cch;
				cin >> cch;
				if(cch == "y"){
					bs.setPrint(true);
				}else{
					bs.setPrint(false);
				}
			}
			if(choice == 1){
				bs.classic();
				rewind(arch);
			}else if(choice == 2){
				bs.flag();
				rewind(arch);
			}else if(choice == 3){
				cout << "Archive name: ";
				cin.get();
				string name;
				getline(cin, name);
				arch = fopen(name.c_str(), "r");
				if(arch != NULL){
					bs.setArch(arch, archSize(arch));
					cout << "Archive changed" << endl;
				}else{
					arch = fopen(argv[1], "r");
					cout << "Erro archive not found" << endl;
				}
			}else if(choice == 4){
				fclose(arch);
				break;
			}else{
				cout << "Erro in choice" << endl;
			}
			cout << "1 - BubbleSort Classi\n2 - BubbleSort With Flag\n3 - Change file\n4 - Exit" << endl;
			cout << "Choice: ";
			choice = 0;
		}
				
    }else{
        cout << "Erro open archive!" << endl;
    }
}

int archSize(FILE *arch){
	char chr;
	int size = 0;
	while(fread(&chr , sizeof(char), 1, arch)){
		if(chr == '\n'){
			size++;
		}
	}
	
	rewind(arch);
	return size;
}