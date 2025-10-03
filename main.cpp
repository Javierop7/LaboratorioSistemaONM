#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;


double promedioAnual(double v[], int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
    }
    return suma / n;
}


double promedioNacional(double s[], double g[], double n[], int tam) {
    double suma = 0;
    for (int i = 0; i < tam; i++) suma += s[i] + g[i] + n[i];
    return suma / (3 * tam);
}


int mesMasCaliente(double v[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[pos]) pos = i;
    }
    return pos;
}


double promedioPicos(double s[], double g[], double n[], int tam) {
    double maxS = s[0], maxG = g[0], maxN = n[0];
    for (int i = 1; i < tam; i++) {
        if (s[i] > maxS) maxS = s[i];
        if (g[i] > maxG) maxG = g[i];
        if (n[i] > maxN) maxN = n[i];
    }
    return (maxS + maxG + maxN) / 3.0;
}


string deptoMayorPromedio(double promS, double promG, double promN) {
    if (promS >= promG && promS >= promN) return "Santander";
    else if (promG >= promS && promG >= promN) return "Guajira";
    else return "Narino";
}


void maximaGlobal(double s[], double g[], double n[], int tam, string meses[]) {
    double maxTemp = s[0];
    string depto = "Santander";
    int mes = 0;


    for (int i = 0; i < tam; i++) {
        if (s[i] > maxTemp) {
            maxTemp = s[i];
            depto = "Santander";
            mes = i;
        }
    }

    for (int i = 0; i < tam; i++) {
        if (g[i] > maxTemp) {
            maxTemp = g[i];
            depto = "Guajira";
            mes = i;
        }
    }

    for (int i = 0; i < tam; i++) {
        if (n[i] > maxTemp) {
            maxTemp = n[i];
            depto = "Narino";
            mes = i;
        }
    }

    cout << "Temperatura maxima anual global: " << maxTemp << " " << char(176) << "C en "
        << depto << " durante " << meses[mes] << endl;
}


double desviacionEstandar(double v[], int n) {
    double prom = promedioAnual(v, n);
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += pow(v[i] - prom, 2);
    }
    return sqrt(suma / n);
}


int main() {
    const int MESES = 12;
    string meses[MESES] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                           "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

    double santander[MESES] = { 22.1, 24.0, 25.3, 26.0, 27.2, 28.4, 28.8, 28.0, 27.0, 25.5, 23.4, 22.0 };
    double guajira[MESES] = { 29.0, 30.2, 31.1, 32.0, 33.0, 34.0, 34.5, 34.2, 33.1, 31.5, 30.0, 29.2 };
    double narino[MESES] = { 15.0, 15.5, 16.0, 16.2, 17.0, 17.5, 18.0, 18.1, 17.8, 16.9, 16.0, 15.3 };

    cout << fixed << setprecision(2);


    double promS = promedioAnual(santander, MESES);
    double promG = promedioAnual(guajira, MESES);
    double promN = promedioAnual(narino, MESES);

    cout << "Promedio anual Santander: " << promS << " " << char(176) << "C" << endl;
    cout << "Promedio anual Guajira: " << promG << " " << char(176) << "C" << endl;
    cout << "Promedio anual Narino: " << promN << " " << char(176) << "C" << endl << endl;


    cout << "Promedio Nacional: " << promedioNacional(santander, guajira, narino, MESES) << " " << char(176) << "C" << endl << endl;


    cout << "Mes mas caliente en Santander: " << meses[mesMasCaliente(santander, MESES)] << endl;
    cout << "Mes mas caliente en Guajira: " << meses[mesMasCaliente(guajira, MESES)] << endl;
    cout << "Mes mas caliente en Narino: " << meses[mesMasCaliente(narino, MESES)] << endl << endl;


    cout << "Promedio de los picos maximos: " << promedioPicos(santander, guajira, narino, MESES) << " " << char(176) << "C" << endl << endl;


    cout << "Departamento con mayor promedio: " << deptoMayorPromedio(promS, promG, promN) << endl << endl;


    maximaGlobal(santander, guajira, narino, MESES, meses);
    cout << endl;


    cout << "Desviacion estandar Santander: " << desviacionEstandar(santander, MESES) << endl;
    cout << "Desviacion estandar Guajira: " << desviacionEstandar(guajira, MESES) << endl;
    cout << "Desviacion estandar Narino: " << desviacionEstandar(narino, MESES) << endl;

    return 0;
}
