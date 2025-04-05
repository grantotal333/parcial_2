#include "CuentaBancaria.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<CuentaBancaria> cuentas;
    vector<float> saldos;
    vector<float> ingresos;
    vector<float> egresos;


    // Inicializar cuentas
    
    cuentas.push_back(CuentaBancaria(1000.0, "123456789"));
    cuentas.push_back(CuentaBancaria(500.0, "987654321"));
    cuentas.push_back(CuentaBancaria(2000.0, "111222333"));

    // ingresos
    ingresos.push_back(1000.0);
    ingresos.push_back(2000.0);
    ingresos.push_back(3000.0);
    // egresos
    egresos.push_back(500.0);
    egresos.push_back(1000.0);
    egresos.push_back(1500.0);

    // Realizar operaciones
    saldos.push_back(((cuentas[0].depositar(ingresos[0])).retirar(egresos[0])).obtenerSaldo());
    saldos.push_back(((cuentas[1].depositar(ingresos[1])).retirar(egresos[1])).obtenerSaldo());
    saldos.push_back(((cuentas[2].depositar(ingresos[2])).retirar(egresos[2])).obtenerSaldo());;



    std::ofstream archivo("reporte.txt");
    if (!archivo) {
        std::cout << "Error al abrir el archivo de reporte." << std::endl;
        return 1;
    }
    for (size_t i = 0; i < cuentas.size(); i++) {
        archivo << "Cuenta " << i + 1 << " = " << cuentas[i].obtenerSaldo() << endl;
    }
    for (size_t i = 0; i < ingresos.size(); i++) {
        archivo << "Ingresos " << i + 1 << " = " << ingresos[i] << endl;
    }
    for (size_t i = 0; i < egresos.size(); i++) {
        archivo << "Egresos " << i + 1 << " = " << egresos[i] << endl;
    }
    for (size_t i = 0; i < saldos.size(); i++) {
        archivo << "Saldo final " << i + 1 << " = " << saldos[i] << endl;
    }
    archivo.close();

    std::cout << "Reporte generado correctamente en reporte.txt" << std::endl;
    return 0;
}
