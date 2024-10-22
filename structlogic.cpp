//programa de prueba que crea una estructura de estudiantes (únicamente 3, por el momento)
//y la ordena solamente por índice

//la intención es unificar junto con el resto del trabajo cuando esté listo

#include <iostream>
#include <algorithm>
using namespace std;

struct Estudiante{
    string nombre;
    string cedula;
    int mesnac;
    int anonac;
    string carrera;
    int indice; //test
};

bool compararPorIndice(Estudiante estudiante1, Estudiante estudiante2){ //Orden Descendente (por índice)
        return estudiante1.indice > estudiante2.indice; //básicamente, poner de primero al estudiante que tenga mayor índice
    }

void OrdenarPorNotas(Estudiante estudiantes[], int numEstudiantes){
    sort(estudiantes, estudiantes + numEstudiantes, compararPorIndice); //toma el rango de ordenar, y el dato personalizado de comparación (ordenar por índice, descendente)
}

int main(){
    const int n = 3;
    Estudiante est[n];

    est[0].nombre = "Leng Leng";
    est[0].cedula = "8-1029-2134";
    est[0].mesnac = 2;
    est[0].anonac = 2002;
    est[0].carrera = "Sist";
    est[0].indice = 1;

    est[1].nombre = "Wixston";
    est[1].cedula = "8-1022-222";
    est[1].mesnac = 6;
    est[1].anonac = 2005;
    est[1].carrera = "Ciencias";
    est[1].indice = 3;

    est[2].nombre = "Erick";
    est[2].cedula = "4-233-123";
    est[2].mesnac = 5;
    est[2].anonac = 1940;
    est[2].carrera = "Anciano";
    est[2].indice = 2;

    for(int i = 0; i < n; i++){ //imprimir cada elemento de la estructura 
        cout << est[i].nombre << "  ";
        cout << est[i].mesnac << "  ";
        cout << est[i].indice;

        cout << endl;
    }

    OrdenarPorNotas(est, n);
    cout << "----DESPUES DE ORDENAR-----" << endl;

    for(int i = 0; i < n; i++){ //volver a imprimir
        cout << est[i].nombre << "  ";
        cout << est[i].mesnac << "  ";
        cout << est[i].indice;

        cout << endl;
 
    } //la estructura se ordenó!
}