/**
 *@brief Esta es una clase de una cuenta bancaria. 
 *@author Juan Diego Molina y David Santiago Cardenas
 *@date 2025-04-04
 *
 *la clase `CuentaBancaria` representa una cuenta bancaria en cualquier banco.
 */ 
#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
/**
 *@class CuentaBancaria
 *@brief clase que representará el funcionamiento de una cuenta bancaria.
 */
class CuentaBancaria {
private:
    float saldo;//< Saldo de la cuenta.
    string numeroCuenta;//< numero de la cuenta
    int bloqueo = 0;//< Indicador de bloqueo de retiros.

public:
    // Constructor
    /** 
     * @brief Constructor de la clase CuentaBancaria.
     * @param saldo dinero que hay en la cuenta.
     * @param numeroCuenta identificación de la cuenta.
     * @param bloqueoRetiros condición presente cuando la cuenta no tiene saldo.
     */
    CuentaBancaria() : saldo(0.0), numeroCuenta("") {}
    /**
     * @brief Constructor de la clase CuentaBancaria. inicializa el saldo en 0.
     * @param numeroCuenta numero de la cuenta bancaria.
     */
    CuentaBancaria(float saldoInicial, string numeroCuenta) : saldo(saldoInicial), numeroCuenta(numeroCuenta) {}
    /**
     * @brief Deposita una cantidad de dinero en la cuenta.
     * @param ingresos cantidad de dinero a depositar.
     * @return nueva cuenta en el saldo actualizado.
     */
    // Sobrecarga de operadores
    CuentaBancaria depositar(float ingresos) const {
        return CuentaBancaria(saldo + ingresos, numeroCuenta);
    }
    /**
     * @brief retiro de una cantidad de la cuenta.
     * @param cuenta Cuenta desde donde se retirará.
     * @return Nueva cuenta con el saldo actualizado.
     * */
    CuentaBancaria retirar(float egresos) const {
        if (bloqueo > 0) {
            return CuentaBancaria(saldo, numeroCuenta);
        }
        else{
            if (saldo > egresos) {
                return CuentaBancaria(saldo - egresos, numeroCuenta);
            }
            else {
                return CuentaBancaria(0, numeroCuenta);
            }
        }
    }
    /**
     * @brief Bloqueo de cualquier retiro de la cuenta.
     */
    // Bloquear retiros
    void bloquearRetiros() {
        cout << "Retiros bloqueados en la cuenta: " << numeroCuenta << endl;
        bloqueo = 1;
    }
    /** 
     * @brief obtener el saldo de la cuenta.
     * @return saldo de la cuenta.
     */
    
    //getters
    float obtenerSaldo() const { return saldo; }
};
#endif