#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

class Nodo(){

    pair<char,int> ci;
    vector<Nodo*> hijos;

};

vector<vector<int>> armarMatriz(string nombreTXT){

    vector<vector<int>> mat;

    ifstream archivo(nombreTXT);

    if(!archivo){
        return mat;
    }

    string linea;

    while(getline(archivo,linea)){
        cout<<linea<<endl;
    }

    archivo.close();

    return mat;

}

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

    cout<<"Hello World"<<endl;

    vector<vector<int>> matAdy = armarMatriz("ejemplos.txt");

    cout<<"A"<<endl;

    return 0;

}