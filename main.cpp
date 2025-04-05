#include "CuentaBancaria.h"

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    CuentaBancaria cuenta1(1000.0, "123456789");
    CuentaBancaria cuenta2(500.0, "987654321");

    cout << "Saldo inicial de cuenta1: " << cuenta1.obtenerSaldo() << endl;
    cout << "Saldo inicial de cuenta2: " << cuenta2.obtenerSaldo() << endl;

    // Depositar dinero
    cout << "Saldo después de depositar: " << (cuenta2.depositar(1000.0)).obtenerSaldo() << endl;

    // Retirar dinero
    cout << "Saldo después de retirar: " << (cuenta1.retirar(200.0)).obtenerSaldo() << endl;

    // Bloquear retiros
    cuenta2.bloquearRetiros();

    cuenta2.retirar(200.0); // Intentar retirar después de bloquear

    // Retirar mas de la cuenta
    cuenta1.retirar(1000.0); // Intentar retirar más de lo que hay en la cuenta
    return 0;
}