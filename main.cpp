#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

class Nodo{

    public:
    pair<char,int> ci;
    vector<Nodo*> hijos;
    Nodo(char caracter, int peso){
        this->ci.first=caracter;
        this->ci.second=peso;
    }

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

    if(raiz==nullptr || anadir == nullptr){return;}
    raiz->hijos.push_back(anadir);

}

void imprimirArbolMasCorto(Nodo * raiz){

    if(raiz==nullptr){return;}

    cout<<raiz->ci.first<<", "<<raiz->ci.second<<endl;

    if(raiz->hijos.size()==0){
        cout<<"FINAL"<<endl;
    }

    for(int i = 0; i<raiz->hijos.size();i++){
        imprimirArbolMasCorto(raiz->hijos[i]);
    }


}


Nodo* buscarNodo(Nodo* raiz,char caracter, int camino){

    if(raiz==nullptr){return nullptr;}
    if(raiz->ci.first==caracter && raiz->ci.second==camino){return raiz;}

    Nodo* temp;

    for(int i = 0; i<raiz->hijos.size();i++){

        temp = buscarNodo(raiz->hijos[i],caracter,camino);
        if(temp!=nullptr){return temp;}

    }

    return nullptr;

}


/**
dijkstra: modifica el vector "menorCamino", y crea el arbol de Shortest Path, camino más corto.
En este caso el algoritmo recorre un nodo, calcula los caminos de sus vecinos e itera
sobre el vecino más cercano. Existian otros metodos con "cola de prioridad", sin embargo,
el metodo que vimos en clase no se parecia a ese algoritmo, el algoritmo que estoy implementando
me parece mas adecuado y aplica lo visto durante el curso
**/
void dijkstra(vector<int>& menorCamino, vector<vector<int>>& matAdy,Nodo* raiz){

    queue<int> cola;
    queue<Nodo*> colaNodos;
    colaNodos.push(raiz);
    vector<int> visitados(matAdy.size(), false);

    cola.push(0);
    menorCamino[0] = 0;

    while(!cola.empty()){

        int actual = cola.front();
        cola.pop();
        Nodo* actualNodo = colaNodos.front();
        colaNodos.pop();
        visitados[actual] = true;
        int menor = 2147483647;
        int indiceMenor = -1;

        for(int ady = 0; ady<matAdy.size();ady++){

            if(matAdy[actual][ady] != 0){

                int suma = matAdy[actual][ady] + menorCamino[actual];

                    char caracter = ady+65;
                    anadirNodo(actualNodo,new Nodo(ady+65,suma));


                if(suma < menorCamino[ady]){
                    menorCamino[ady]=suma;
                    
                }

            }
   
        }
        
        for(int i = 0;i<menorCamino.size();i++){
            
            if(menorCamino[i] < menor && visitados[i] == false){
                menor = menorCamino[i];
                indiceMenor = i;
            }

        }

        if(indiceMenor != -1) {
            cola.push(indiceMenor);
            colaNodos.push(buscarNodo(raiz,indiceMenor+65,menorCamino[indiceMenor]));

        }

    }
        
}

int main(){

    string nombreTXT;

    cout<<"Ingrese el nombre de el Archivo"<<endl;

    getline(cin,nombreTXT);

    ifstream archivo(nombreTXT);
    string opcion = "2";

    while(!archivo){


        if(opcion == "2") {cout<<"El archivo no existe"<<endl;}
        cout<<"1.- Salir\n2.-Volver a intentar"<<endl;
        
    
        getline(cin,opcion);

        if(opcion=="1"){

            return 0;

        } else if(opcion == "2"){

            getline(cin,nombreTXT);
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
    
    Nodo* raiz = new Nodo(65,0);


    dijkstra(menorCamino, matAdy, raiz);


    

    cout<<endl;

    for(int k = 0; k<menorCamino.size();k++){
        cout<<menorCamino[k]<<",";
    }    

    cout<<endl;

    imprimirArbolMasCorto(raiz);

    cout<<"¿Donde deseas ir?"<<endl;


    for(int k = 0; k<menorCamino.size();k++){

    
        char caracter = k+65;

        cout<<caracter;
        if(k!=menorCamino.size()-1){cout<<",";}

    }

    cout<<endl;

    string objetivo;

    getline(cin,objetivo);

    while(objetivo.size() >= 2 || objetivo[0]<=64 || objetivo[0] >= 91 || objetivo[0] > matAdy.size() + 64){

        cout<<"Opción invalida, porfavor ingrese el Nodo objetivo con el formato, 'A' , 'B', 'C' , etc."<<endl;

        getline(cin,objetivo);

    }



    return 0;

}