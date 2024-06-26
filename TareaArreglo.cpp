#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int facturaNumero = 0;
    int totalGaleria = 0, totalPalco = 0;
    double dineroGaleria = 0.0, dineroPalco = 0.0;
    double totalDinero = 0.0;
    int cantidadGeneral = 0;

    while (true) {
        facturaNumero++;
        string cedula, nombre;
        int tipoCliente, tipoTiquete, cantidadTiquetes;
        double montoPorTiquete, montoVenta, descuento, subtotal, impuesto, totalAPagar;

        cout << "Ingrese la cedula del cliente: ";
        cin >> cedula;
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, nombre);

        do {
            cout << "Ingrese el tipo de cliente (1=Niño o adulto mayor, 2=Adulto): ";
            cin >> tipoCliente;
        } while (tipoCliente != 1 && tipoCliente != 2);

        do {
            cout << "Ingrese el tipo de tiquete (1=Tiquete Galería, 2=Tiquete Palco): ";
            cin >> tipoTiquete;
        } while (tipoTiquete != 1 && tipoTiquete != 2);

        cout << "Ingrese la cantidad de tiquetes: ";
        cin >> cantidadTiquetes;

        if (tipoTiquete == 1) {
            montoPorTiquete = 6000.0;
            totalGaleria += cantidadTiquetes;
        } else {
            montoPorTiquete = 12000.0;
            totalPalco += cantidadTiquetes;
        }

        montoVenta = cantidadTiquetes * montoPorTiquete;

        if (tipoCliente == 1) {
            descuento = montoVenta * 0.30;
        } else {
            descuento = 0.0;
        }

        subtotal = montoVenta - descuento;
        impuesto = subtotal * 0.13;
        totalAPagar = subtotal + impuesto;

        if (tipoTiquete == 1) {
            dineroGaleria += totalAPagar;
        } else {
            dineroPalco += totalAPagar;
        }

        totalDinero += totalAPagar;
        cantidadGeneral += cantidadTiquetes;

        cout << fixed << setprecision(2);
        cout << "\nNumero de factura: " << facturaNumero << endl;
        cout << "Cedula del cliente: " << cedula << endl;
        cout << "Nombre del cliente: " << nombre << endl;
        cout << "Tipo de cliente: " << (tipoCliente == 1 ? "Niño o adulto mayor" : "Adulto") << endl;
        cout << "Tipo de tiquete: " << (tipoTiquete == 1 ? "Galería" : "Palco") << endl;
        cout << "Cantidad de tiquetes: " << cantidadTiquetes << endl;
        cout << "Monto unitario por tiquete: " << montoPorTiquete << " colones" << endl;
        cout << "Monto de venta: " << montoVenta << " colones" << endl;
        cout << "Descuento: " << descuento << " colones" << endl;
        cout << "Subtotal de venta: " << subtotal << " colones" << endl;
        cout << "Impuesto de venta: " << impuesto << " colones" << endl;
        cout << "Total a pagar: " << totalAPagar << " colones" << endl;

        char continuar;
        cout << "\n¿Desea registrar otra venta? (S/N): ";
        cin >> continuar;
        if (continuar == 'N' || continuar == 'n') {
            break;
        }
    }

    cout << "\nEstadísticas de ventas:\n";
    cout << "Cantidad de entradas Tiquetes Galería: " << totalGaleria << endl;
    cout << "Acumulado Dinero por Tiquetes Galería: " << dineroGaleria << " colones" << endl;
    cout << "Cantidad de entradas Tiquetes Palco: " << totalPalco << endl;
    cout << "Acumulado Dinero por Tiquetes Palco: " << dineroPalco << " colones" << endl;
    cout << "Cantidad General de Entradas: " << cantidadGeneral << endl;
    cout << "Acumulado General Dinero por Entradas: " << totalDinero << " colones" << endl;
    if (facturaNumero > 0) {
        cout << "Promedio General por Ventas: " << totalDinero / facturaNumero << " colones" << endl;
    }

    return 0;
}

