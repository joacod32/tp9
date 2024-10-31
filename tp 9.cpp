#include <iostream>
#include <string>
using namespace std;


struct Alumno {
    string nombre;
    string apellido;
    string curso;
    string materia;
    int notas[2];
    float notaFinal;
    string condicion;
};


void Inicializar(Alumno &alumno) {
    cout << "Ingrese el nombre del alumno: ";
    cin >> alumno.nombre;
    cout << "Ingrese el apellido del alumno: ";
    cin >> alumno.apellido;
    cout << "Ingrese el curso: ";
    cin >> alumno.curso;
    cout << "Ingrese la materia: ";
    cin >> alumno.materia;
    for (int i = 0; i < 2; i++) {
        cout << "Ingrese la calificación del cuatrimestre " << i + 1 << ": ";
        cin >> alumno.notas[i];
    }
}


float calcularPromedio(Alumno &alumno) {
    float suma = 0;
    for (int i = 0; i < 2; i++) {
        suma += alumno.notas[i];
    }
    alumno.notaFinal = suma / 2;
    return alumno.notaFinal;
}


void calcularCondicion(Alumno &alumno) {
    bool promociona = true;
    bool recupera = false;

   
    for (int i = 0; i < 2; i++) {
        if (alumno.notas[i] < 5) {
            alumno.condicion = "Reprobado (debe recursar)";
            return;
        } else if (alumno.notas[i] < 7) {
            promociona = false;
            recupera = true;
        }
    }

    if (alumno.notaFinal >= 7) {
        alumno.condicion = "Pasa de año";
    } else if (promociona) {
        alumno.condicion = "Promocionado";
    } else if (recupera) {
        alumno.condicion = "Recupera cuatrimestres";
    }
}


void Imprimir(const Alumno &alumno) {
    cout << "\nResultados:\n";
    cout << "Alumno: " << alumno.nombre << " " << alumno.apellido << endl;
    cout << "Curso: " << alumno.curso << endl;
    cout << "Materia: " << alumno.materia << endl;
    cout << "Promedio: " << alumno.notaFinal << endl;
    cout << "Condición: " << alumno.condicion << endl;
}

int main() {
    Alumno alumno;

    Inicializar(alumno);
    calcularPromedio(alumno);
    calcularCondicion(alumno);
    Imprimir(alumno);

    return 0;
}

