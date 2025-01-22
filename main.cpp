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

void anadirNodo(Nodo* raiz, Nodo* anadir){

    raiz->hijos.push_back(anadir);

}

//dijkstra: modifica el vector "menorCamino", y crea el arbol de Shortest Path, camino más corto
void dijkstra(vector<int>& menorCamino, vector<vector<int>>& matAdy,Nodo* raiz){

    stack<int> cola;
    vector<int> visitados(matAdy.size(), false);

    cola.push(0);
    menorCamino[0] = 0;

    while(!cola.empty()){

        int actual = cola.top();
        cola.pop();
        visitados[actual] = true;
        Nodo* actual;

        for(int i= 0; i<matAdy[actual].size();i++){

            if(actual!=0){
                if(matAdy[actual][i] != 0 && matAdy[actual][i] + menorCamino[actual] < menorCamino[i]){

                    menorCamino[i] = menorCamino[actual] + matAdy[actual][i];
                    if(visitados[i] == false) {cola.push(i);}

                }    
            } else {

                if(matAdy[actual][i] != 0){
                    menorCamino[i] = matAdy[actual][i];
                    if(visitados[i] == false){cola.push(i);}
                }

            }
            

        }


    }



    
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

    vector<int> menorCamino(matAdy.size(), 2147483647);
    
    Nodo* raiz = new Nodo();


    dijkstra(menorCamino, matAdy, raiz);

    cout<<"¿Donde deseas ir?"<<endl;

    for(int k = 0; k<menorCamino.size();k++){

    
        char caracter = k+65;

        cout<<caracter;
        if(k!=menorCamino.size()-1){cout<<",";}

    }    

    cout<<endl;


    return 0;

}