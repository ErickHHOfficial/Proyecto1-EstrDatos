#include<iostream>
#include<string.h>           //libreria para uso del string
#include<random>             //libreria para uso del rand()
#include<ctime>              //libreria que apoya al generador de la "seed" inicial (srand())
using namespace std;

struct datosEs{               //Registro con los datos de los Estudiantes
    string nombre;
    string cedula;
    int mNacimiento;
    int anio;
    string carrera;
    float indice;
};

struct datosEs estudiantes[20];          //Arreglo del registro (nos permite guardar 20 registros diferentes)

string nombre[10]{"Colón", "Guillermo", "Carlos", "Omar", "Erick", "Amy", "Estefany", "Hanna", "Caterina", "Luisa"};            //Arreglos con valores string genéricos para la creación de los campos
string apellido[10]{"Sánchez", "Bárcenas", "Castro", "Leng Leng", "Cedeño", "Franco", "Hou", "Navas", "Chen", "Saenz"};
string carrera[10]{"Desarrollo & Gestión de Soft.", "Ing. de Soft.", "Ing. Industrial", "Ing. en Alimentos", "Logística & Transporte Multimodal", 
                    "Ing. Civil", "Ing. Electromecánica", "Ciberseguridad", "Refrigeración & AC", "Ing. Marítima Portuaria"};

void datoPE(int i){                        //función que realiza la asignación de valores aleatorios al registro
    estudiantes[i].nombre = nombre[rand() % 10] + " " + apellido[rand() % 10];
    estudiantes[i].cedula = to_string(1 + (rand() % 10)) + "-" + to_string(1 + (rand() % 1999)) + "-" + to_string(1 + (rand() % 999));
    estudiantes[i].mNacimiento = 1 + (rand() % 12);
    estudiantes[i].anio = 1990 + (rand() % 18);
    estudiantes[i].carrera = carrera[rand() % 10];
    estudiantes[i].indice = (float)rand() / RAND_MAX * (3.0 - 1.0) + 1.0;
};

 int main(){

    srand((unsigned) time(NULL));

    for(int i = 0; i < 20; i++){       //ciclo FOR que llama a la función de asignación
        datoPE(i);
    }

return 0;
 }
