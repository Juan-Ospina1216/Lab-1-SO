#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#define MAX_SIZE 1000
#define MAX_LINEA 1000

using namespace std;

void load(string registro, int*acum);
void agregar_registros();
void show(int pc, int alu, int acum, string registro);
void storage(int acum, string registro);
void incremento(int x, string registro, int acum);
void pause(int pc, int alu, int acum);
void set(string registro, string valor);
void add(int*alu, int*acum, string valor1, string valor2, string valor3);
void execute(const vector<vector<string> >& instrucciones);
void lecturaArchivo();

map<string, int> registros;
map<string, string> registros2;

vector<int> mem = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(){
	
	agregar_registros();
	lecturaArchivo();
	
	return 0;
}

void agregar_registros(){
	registros["D0"] = 0; registros["D1"] = 1; registros["D2"] = 2; registros["D3"] = 3; registros["D4"] = 4; registros["D5"] = 5;
	registros["D6"] = 6; registros["D7"] = 7; registros["D8"] = 8; registros["D9"] = 9;  
	registros2["MAR"] = ""; registros2["MDR"] = ""; registros2["ICR"] = ""; registros2["ACC"] = ""; registros2["UC"] = "";
}	

void load(string registro, int*acum){
	
	registros2["MAR"] = to_string(registros[registro]);
	int ind = stoi(registros2["MAR"]);
	registros2["MDR"] = to_string(mem[ind]);
	*acum = stoi(registros2["MDR"]);
}

void show(int pc, int alu, int acum, std::string registro){
	string mostrar; 
	char primer_caracter = registro[0];
	if(primer_caracter == 'D'){
		int ind = registros[registro];
		mostrar = to_string(mem[ind]);
	}
	else if(registro == "ACC"){
		mostrar = to_string(acum);
	}
	else{
		mostrar = registros2[registro];
	}
	
	cout << mostrar << endl;
	
}

void storage(int acum, string registro){
	
	int indice = registros[registro];
	mem[indice] = acum;
}

void incremento(int x, string registro, int acum){
	int indice = registros[registro];
	mem[indice] = acum + x;
}

void pause(int pc, int alu, int acum){
	cout << "MEM: ";
	for(int i = 0; i < 10; i++){
		cout << mem[i] << " ";
	}
	cout << endl;
	
	cout << "MAR ";
	show(pc, alu, acum, "MAR");
	
	cout << "MDR ";
	show(pc, alu, acum, "MDR");
	
	cout << "ACC ";
	show(pc, alu, acum, "ACC");
	
	cout << "ICR ";
	show(pc, alu, acum, "ICR");
	
	cout << "UC ";
	show(pc, alu, acum, "UC"); 
}

void set(string registro, string valor){
    int indice = registros[registro];
    mem[indice] = stoi(valor);
}

void add(int*alu, int*acum, string valor1, string valor2, string valor3){
	*alu = *acum;
	if(valor2 == "NULL" && valor3 == "NULL"){
		int indice = registros[valor1];
		registros2["MAR"] = to_string(indice);
		registros2["MDR"] = to_string(mem[indice]);
		*acum = mem[indice];
		*alu += *acum;
		*acum = *alu;
	}
	else if(valor2 != "NULL" && valor3 == "NULL"){
		
		for(int i = 0; i < 2; i++){
			string ind;
			if(i == 0){ ind = valor1; }
			else{ ind = valor2;}
			int indice = registros[ind];
			registros2["MAR"] = to_string(indice);
			registros2["MDR"] = to_string(mem[indice]);
			*acum = mem[indice];
			*alu += *acum;
			*acum = *alu;	
		}
		
	}else if (valor2 != "NULL" && valor3 != "NULL"){
		for(int i = 0; i < 2; i++){
			string ind;
			if(i == 0){ ind = valor1; }
			else{ ind = valor2;}
			int indice = registros[ind];
			registros2["MAR"] = to_string(indice);
			registros2["MDR"] = to_string(mem[indice]);
			*acum = mem[indice];
			*alu += *acum;
			*acum = *alu;	
		}
		int j = registros[valor3];
		mem[j] = *acum;
	}
}

void execute(const vector<vector<string> >& instrucciones)  {
	int pc = 10;
	int acum = 0, alu = 0;
	size_t j = 0;
	
	do{
		registros2["MAR"] = to_string(pc);
		registros2["MDR"] = instrucciones[j][0] + " " + instrucciones[j][1];
		registros2["ICR"] = registros2["MDR"];
		pc ++;
		registros2["UC"] = registros2["ICR"];
		
		if (instrucciones[j][0] == "LDR"){
			load(instrucciones[j][1], &acum);
		}
		else if(instrucciones[j][0] == "SHW"){
			show(pc, alu, acum, instrucciones[j][1]);
		}
		else if(instrucciones[j][0] == "STR"){
			storage(acum, instrucciones[j][1]);
		}
		else if(instrucciones[j][0] == "INC"){
			incremento(1, instrucciones[j][1], acum);
		}
		else if(instrucciones[j][0] == "DEC"){
			incremento(-1, instrucciones[j][1], acum);
		}
		else if(instrucciones[j][0] == "PAUSE"){
			pause(pc, alu, acum);
		}
		else if(instrucciones[j][0] == "ADD"){
			add(&alu, &acum, instrucciones[j][1], instrucciones[j][2], instrucciones[j][3]);
		}
		else if(instrucciones[j][0] == "SET"){
			set(instrucciones[j][1], instrucciones[j][2]);
		}
		j++;
	}while(instrucciones[j][0] != "END" && j < instrucciones.size());
	
}

void lecturaArchivo() {
    char lista[MAX_SIZE][MAX_LINEA];
    int iterador = 0;

    FILE *archivo = fopen("entrada.txt", "r");
    if (archivo == NULL) {
        perror("Fallo el intento de abrir el archivo");
    }

    char linea[MAX_LINEA];
    while (fgets(linea, sizeof(linea), archivo) && iterador < MAX_SIZE) {
        strncpy(lista[iterador], linea, MAX_LINEA - 1);
        lista[iterador][MAX_LINEA - 1] = '\0'; 
        iterador++;
    }

    fclose(archivo);

    vector< vector<string> > instrucciones;
    
    for (int i = 0; i < iterador; i++) {
        istringstream iss(lista[i]);
        string palabra;
        vector<string> partes;

        while (iss >> palabra) {
            partes.push_back(palabra);
        }

        instrucciones.push_back(partes);
    }

    execute(instrucciones);
}
