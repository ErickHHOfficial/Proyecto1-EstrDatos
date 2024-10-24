#include<iostream>
#include<string>
#include<string.h>           //libreria para uso del string
#include<random>             //libreria para uso del rand()
#include<ctime>             //libreria que apoya al generador de la "seed" inicial (srand())
using namespace std;

struct datosEs{               //Registro con los datos de los Estudiantes
    string nombre;
    string cedula;
    int mNacimiento;
    int anio;
    string carrera;
    float indice;
};

struct datosEs estudiantes[20];         //Arreglo del registro (nos permite guardar 20 registros diferentes)
const int numes = 20;

string nombre[20]{"Colón", "Guillermo", "Carlos", "Omar", "Erick", "Amy", "Estefany", "Hanna", "Caterina", "Luisa", 
                    "Winston", "Alex", "Jelena", "Jackeline", "William", "Pablo", "Andrea", "Samuel", "Ana", "Elim"};            //Arreglos con valores string genéricos para la creación de los campos
string apellido[20]{"Sánchez", "Bárcenas", "Castro", "Leng Leng", "Cedeño", "Franco", "Hou", "Navas", "Chen", "Saenz", 
                    "Mas", "Zhang", "Yuen", "Barranco", "Torres", "Deng", "Toruño", "Navarro", "Domingo", "Villalobos"};
string carrera[10]{"Desarrollo & Gestión de Soft.", "Ing. de Soft.", "Ing. Industrial", "Ing. en Alimentos", "Logística & Transporte Multimodal", 
                    "Ing. Civil", "Ing. Electromecánica", "Ciberseguridad", "Refrigeración & AC", "Ing. Marítima Portuaria"};

void datoPE(int i){                        //función que realiza la asignación de valores aleatorios al registro
    estudiantes[i].nombre = nombre[rand() % 20] + " " + apellido[rand() % 20];
    estudiantes[i].cedula = to_string(1 + (rand() % 10)) + "-" + to_string(1 + (rand() % 1999)) + "-" + to_string(1 + (rand() % 999));
    estudiantes[i].mNacimiento = 1 + (rand() % 12);
    estudiantes[i].anio = 1 + (rand() % 4);
    estudiantes[i].carrera = carrera[rand() % 10];
    estudiantes[i].indice = (float)rand() / RAND_MAX * (3.0 - 1.0) + 1.0;
};

bool compararPorIndice(datosEs estudiante1, datosEs estudiante2){ //Orden Descendente (por índice)
        return estudiante1.indice > estudiante2.indice; //básicamente, poner de primero al estudiante que tenga mayor índice
}

void OrdenarPorNotas(datosEs estudiantes[], int numEstudiantes){
    sort(estudiantes, estudiantes + numEstudiantes, compararPorIndice); //toma el rango de ordenar, y el dato personalizado de comparación (ordenar por índice, descendente)
}

string determinarMateria(int codmat){ //determina las materias en el orden que se agregaron originalmente a carrera[10]
    string materia;
    switch(codmat){
        case 1:
            materia = "Desarrollo & Gestión de Soft.";
            break;

        case 2:
            materia = "Ing. de Soft.";
            break;
        
        case 3:
            materia = "Ing. Industrial";
            break;
        
        case 4: 
            materia = "Ing. en Alimentos";
            break;
        
        case 5:
            materia = "Logística & Transporte Multimodal";
            break;
        
        case 6:
            materia = "Ing. Civil";
            break;

        case 7:
            materia = "Ing. Electromecánica";
            break;
        
        case 8:
            materia = "Ciberseguridad";
            break;
        
        case 9:
            materia = "Refrigeración & AC";
            break;
        
        case 10:
            materia = "Ing. Marítima Portuaria";
            break;
        default:
            cout << "incorrecto";
        
    }   
    return materia;
}   

void imprimirTop5SegunCarrera(int codmat){ //trata de encontrar los mejores estudiantes (si hay o no hay más de 5) en toda la lista de estudiantes SEGUN LA CARRERA INDICADA
    int conta = 1;
    while(conta <= 5){
        for(int i = 0; i < numes; i++){ //volver a imprimir
            if(estudiantes[i].indice >= 2.5 && estudiantes[i].carrera == determinarMateria(codmat)){
                cout << estudiantes[i].nombre << "  ";
                cout << estudiantes[i].mNacimiento << "  ";
                cout << estudiantes[i].carrera << "  "; //test
                cout << estudiantes[i].indice;
                cout << endl;
            }
            conta++;
        }
    }
}

void imprimirTop5(){ //trata de encontrar los mejores estudiantes (si hay o no hay más de 5) en toda la lista de estudiantes
    int conta = 1;
    while(conta <= 5){
        for(int i = 0; i < numes; i++){ //volver a imprimir
            if(estudiantes[i].indice >= 2.5){
                cout << estudiantes[i].nombre << "  ";
                cout << estudiantes[i].mNacimiento << "  ";
                cout << estudiantes[i].carrera << "  "; //test
                cout << estudiantes[i].indice;
                cout << endl;
            }
            conta++;
        }
    }
}

void imprimirTodos(){ //imprime a todos los estudiantes en la lista (test)

    for(int i = 0; i < numes; i++){ //volver a imprimir
        cout << estudiantes[i].nombre << "  ";
        cout << estudiantes[i].mNacimiento << "  ";
        cout << estudiantes[i].carrera << "  "; //test
        cout << estudiantes[i].indice;
        cout << endl;
    }
}

 int main(){

    int codmat = 0;
    int num = 0;
    srand((unsigned) time(NULL));

    for(int i = 0; i < 20; i++){     //ciclo FOR que llama a la función de asignación
        datoPE(i);
    }
    OrdenarPorNotas(estudiantes, numes);

    imprimirTodos();

    cout << endl;
    
    cout << "escriba 1 para Top 5 global, 2 para top 5 por carrera: ";
    cin >> num;
    cout << endl;
    
    switch(num){
        case 1:
            imprimirTop5();
            break;

        case 2:
            cout << "Introduzca codigo carrera: ";
            for(int x = 0; x < 10; x++){
                cout << (x+1) <<": " << carrera[x] <<endl;
            }
            cin >> codmat;
            imprimirTop5SegunCarrera(codmat);
            break;
    }
    return 0;
}
