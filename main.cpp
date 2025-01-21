#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

class Nodo{

    pair<char,int> ci;
    vector<Nodo*> hijos;

};



void imprimirMatriz(vector<vector<int>> mat){

    for(int i = 0; i<mat.size(); i++){
        for(int j = 0; j<mat[0].size();j++){

            cout<<mat[i][j]<<",";


        }
        cout<<endl;
    }

}

void dijkstra(vector<int>& menorCamino, vector<vector<int>>& matAdy,Nodo* raiz){
    return;
}

int main(){

    string nombreTXT;

    cout<<"Ingrese el nombre de el Archivo"<<endl;
    cin>>nombreTXT;

    ifstream archivo(nombreTXT);
    int opcion = 2;

    while(!archivo){


        if(opcion == 2) {cout<<"El archivo no existe"<<endl;}
        cout<<"1.- Salir\n2.-Volver a intentar"<<endl;
        
    
        cin>>opcion;
        
        if(opcion==1){

            return 0;

        } else if(opcion == 2){

            cin>>nombreTXT;
            archivo.close();
            archivo.open(nombreTXT);

        } else {
            
            cout<<"Opcion incorrecta"<<endl;

        }

        

    }

    string linea;

    int n;
    
    archivo>>n;

    getline(archivo,linea);

    vector<vector<int>> matAdy(n, vector<int>(n, 0));

    int x = 0;
    int y = 0;

    int i = 0;

    while(getline(archivo,linea)){

        string numero = "";
        x=0;
        i=0;
        while(i!=linea.size()){

            while(i<linea.size() && linea[i]!=','){

            numero += linea[i];
            i++;

            }

        if(i<linea.size() && linea[i]==','){i++;}
        int numeroM = stoi(numero);
        cout<<numeroM<<endl;
        numero = "";
        matAdy[y][x] = numeroM;
        x++;
        }
        y++;
    }

    archivo.close();

    imprimirMatriz(matAdy);

    return 0;

}