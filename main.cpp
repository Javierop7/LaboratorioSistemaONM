#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// ---------------- FUNCIONES ----------------

// Promedio anual de un departamento
double promedioAnual(double v[], int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
    }
    return suma / n;
}

// Promedio nacional
double promedioNacional(double s[], double g[], double n[], int tam) {
    double suma = 0;
    for (int i = 0; i < tam; i++) suma += s[i] + g[i] + n[i];
    return suma / (3 * tam);
}

// Mes más caliente de un departamento
int mesMasCaliente(double v[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[pos]) pos = i;
    }
    return pos; // retorna la posición (0 = enero, 11 = diciembre)
}

// Promedio de los picos
double promedioPicos(double s[], double g[], double n[], int tam) {
    double maxS = s[0], maxG = g[0], maxN = n[0];
    for (int i = 1; i < tam; i++) {
        if (s[i] > maxS) maxS = s[i];
        if (g[i] > maxG) maxG = g[i];
        if (n[i] > maxN) maxN = n[i];
    }
    return (maxS + maxG + maxN) / 3.0;
}

// Departamento con mayor promedio
string deptoMayorPromedio(double promS, double promG, double promN) {
    if (promS >= promG && promS >= promN) return "Santander";
    else if (promG >= promS && promG >= promN) return "Guajira";
    else return "Nariño";
}

// Temperatura máxima anual global
void maximaGlobal(double s[], double g[], double n[], int tam) {
    double maxTemp = s[0];
    string depto = "Santander";
    int mes = 0;

    // Santander
    for (int i = 0; i < tam; i++) {
        if (s[i] > maxTemp) {
            maxTemp = s[i];
            depto = "Santander";
            mes = i;
        }
    }
    // Guajira
    for (int i = 0; i < tam; i++) {
        if (g[i] > maxTemp) {
            maxTemp = g[i];
            depto = "Guajira";
            mes = i;
        }
    }
    // Nariño
    for (int i = 0; i < tam; i++) {
        if (n[i] > maxTemp) {
            maxTemp = n[i];
            depto = "Nariño";
            mes = i;
        }
    }

    cout << "Temperatura maxima anual global: " << maxTemp << " °C en "
        << depto << ", mes " << (mes + 1) << endl;
}

// Desviacion estandar (poblacional)
double desviacionEstandar(double v[], int n) {
    double prom = promedioAnual(v, n);
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += pow(v[i] - prom, 2);
    }
    return sqrt(suma / n);
}

// ---------------- MAIN ----------------
int main() {
    const int MESES = 12;
    double santander[MESES] = { 22.1, 24.0, 25.3, 26.0, 27.2, 28.4, 28.8, 28.0, 27.0, 25.5, 23.4, 22.0 };
    double guajira[MESES] = { 29.0, 30.2, 31.1, 32.0, 33.0, 34.0, 34.5, 34.2, 33.1, 31.5, 30.0, 29.2 };
    double narino[MESES] = { 15.0, 15.5, 16.0, 16.2, 17.0, 17.5, 18.0, 18.1, 17.8, 16.9, 16.0, 15.3 };

    // 1. Promedio anual
    double promS = promedioAnual(santander, MESES);
    double promG = promedioAnual(guajira, MESES);
    double promN = promedioAnual(narino, MESES);

    cout << fixed << setprecision(2);
    cout << "Promedio Santander: " << promS << " °C" << endl;
    cout << "Promedio Guajira: " << promG << " °C" << endl;
    cout << "Promedio Nariño: " << promN << " °C" << endl;

    // 2. Promedio nacional
    cout << "Promedio Nacional: " << promedioNacional(santander, guajira, narino, MESES) << " °C" << endl;

    // 3. Mes más caliente
    cout << "Mes mas caliente Santander: " << (mesMasCaliente(santander, MESES) + 1) << endl;
    cout << "Mes mas caliente Guajira: " << (mesMasCaliente(guajira, MESES) + 1) << endl;
    cout << "Mes mas caliente Nariño: " << (mesMasCaliente(narino, MESES) + 1) << endl;

    // 4. Promedio de los picos
    cout << "Promedio de los picos: " << promedioPicos(santander, guajira, narino, MESES) << " °C" << endl;

    // 5. Departamento con mayor promedio
    cout << "Departamento con mayor promedio: " << deptoMayorPromedio(promS, promG, promN) << endl;

    // 6. Temperatura máxima global
    maximaGlobal(santander, guajira, narino, MESES);

    // 7. Desviaciones estándar
    cout << "Desviacion estandar Santander: " << desviacionEstandar(santander, MESES) << endl;
    cout << "Desviacion estandar Guajira: " << desviacionEstandar(guajira, MESES) << endl;
    cout << "Desviacion estandar Nariño: " << desviacionEstandar(narino, MESES) << endl;

    return 0;
}
