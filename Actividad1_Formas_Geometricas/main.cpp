#include <iostream>
#include "forma.cpp"
using namespace std;

int main() {
    int opcion;
    string color; 
    do {
        cout << "Bienvenido, seleccione una figura geometrica:" << endl;
        cout << "1. Rectangulo" << endl;
        cout << "2. Cuadrado" << endl;
        cout << "3. Triangulo" << endl;
        cout << "4. Circulo" << endl;
        cout << "5. Trapecio" << endl;
        cout << "6. Paralelogramo" << endl;
        cout << "7. Cilindro" << endl;
        cout << "8. Esfera" << endl;
        cout << "9. Manejar el color de tu figura" << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese su opcion 1-10: ";
        cin >> opcion;

        double ancho, altura;

        switch(opcion) {
            case 1: {
                cout << "Escribe la base del rectangulo: ";
                cin >> ancho;
                cout << "Escribe la Altura del rectangulo: ";
                cin >> altura;
                cout << "Escribe el color del rectangulo: ";
                cin >> color;
                printf("\n");
                Rectangulo forma1(ancho,altura,color);
                cout << "El area del rectangulo es: " << forma1.calcularArea() << endl;
                cout << "El perimetro del rectangulo es: " << forma1.calcularPerimetro() << endl;
                cout << "El color del rectangulo es: " << forma1.getColor() << endl;
                printf("\n");
                break;
            }
            case 2:{
                cout << "Escribe el lado del Cuadrado: ";
                cin >> ancho;
                cout << "Escribe el color del Cuadrado: ";
                cin >> color;
                printf("\n");
                Cuadrado forma2(ancho,altura,color);
                cout << "El area del Cuadrado es: " << forma2.calcularArea() << endl;
                cout << "El perimetro del Cuadrado es: " << forma2.calcularPerimetro() << endl;
                cout << "El color del Cuadrado es: " << forma2.getColor() << endl;
                printf("\n");
            }
                break;
            case 3:{
                double lado1,lado2,lado3;
                cout << "Escribe el lado inferior del trinagulo: ";
                cin >> lado1;
                cout << "Escribe el lado izquierdo del trinagulo: ";
                cin >> lado2;
                cout << "Escribe el lado derecho del trinagulo: ";
                cin >> lado3;
                cout << "Escribe el color del trinagulo: ";
                cin >> color;
                printf("\n");
                Triangulo forma3(ancho,altura,color,lado1,lado2,lado3);
                cout << "El area del trinagulo es: " << forma3.calcularArea() << endl;
                cout << "El perimetro del trinagulo es: " << forma3.calcularPerimetro() << endl;
                cout << "El color del trinagulo es: " << forma3.getColor() << endl;
                printf("\n");
                break;
            }
            case 4:{
                double radio;
                cout << "Escribe el radio del Circulo: ";
                cin >> radio;
                cout << "Escribe el color del Circulo: ";
                cin >> color;
                Circulo forma4(ancho,altura,color,radio);
                printf("\n");
                cout << "El area del Circulo es: " << forma4.calcularArea() << endl;
                cout << "El perimetro del Circulo es: "<< forma4.calcularPerimetro() << endl;
                cout << "El color del Circulo es: "<< forma4.getColor() << endl;
                printf("\n");
                break;
            }
            case 5:{
                double baseMenor,baseMayor,lado1,lado2;
                cout << "Escribe la base menor del Trapecio: ";
                cin >> baseMenor;
                cout << "Escribe la base mayor del Trapecio: ";
                cin >> baseMayor;
                cout << "Escribe el lado izquierdo del Trapecio: ";
                cin >> lado1;
                cout << "Escribe el lado derecho del Trapecio: ";
                cin >> lado2;
                cout << "Escribe el color del Trapecio: ";
                cin >> color;
                Trapecio forma5(ancho,altura,color,baseMenor,baseMayor,lado1,lado2);
                printf("\n");
                cout << "El area del Trapecio es: " << forma5.calcularArea() << endl;
                cout << "El perimetro del Trapecio es: "<< forma5.calcularPerimetro() << endl;
                cout << "El color del Trapecio es: "<< forma5.getColor() << endl;
                printf("\n");
                break;
            }
            case 6:{
                double lado1;
                cout << "Escribe la base del Paralelogramo: ";
                cin >> ancho;
                cout << "Escribe la altura del Paralelogramo: ";
                cin >> altura;
                cout << "Escribe el lado del Paralelogramo: ";
                cin >> lado1;
                cout << "Escribe el color del Paralelogramo: ";
                cin >> color;
                printf("\n");
                Paralelogramo forma6(ancho,altura,color,lado1);
                cout << "El area del Cuadrado es: " << forma6.calcularArea() << endl;
                cout << "El perimetro del Cuadrado es: " << forma6.calcularPerimetro() << endl;
                cout << "El color del Cuadrado es: " << forma6.getColor() << endl;
                printf("\n");
                break;
            }
            case 7:{
                double radio;
                cout << "Escribe la altura del Cilindro: ";
                cin >> altura;
                cout << "Escribe el radio del Cilindro: ";
                cin >> radio;
                cout << "Escribe el color del Cilindro: ";
                cin >> color;
                printf("\n");
                Cilindro forma7(ancho,altura,color,radio);
                cout << "El area del Cilindro es: " << forma7.calcularArea() << endl;
                cout << "El volumen del Cilindro es: " << forma7.calcularVolumen() << endl;
                cout << "El color del Cilindro es: " << forma7.getColor() << endl;
                printf("\n");
                break;
            }
            case 8:{
                double radio;
                cout << "Escribe el radio del Esfera: ";
                cin >> radio;
                cout << "Escribe el color del Esfera: ";
                cin >> color;
                printf("\n");
                Esfera forma8(ancho,altura,color,radio);
                cout << "El area del Esfera es: " << forma8.calcularArea() << endl;
                cout << "El volumen del Esfera es: " << forma8.calcularVolumen() << endl;
                cout << "El color del Esfera es: " << forma8.getColor() << endl;
                printf("\n");
                break;
            }
            case 9: {
                Rectangulo col(ancho,altura,color);
                int opcionCambiar;
                do {
                    cout << "1. Ver el color de tu figura: "<< endl;
                    cout << "2. Cambiar el color de tu figura: "<< endl;
                    cout << "3. Salir"<< endl;
                    cout << "Ingrese su opcion: ";
                    cin >> opcionCambiar;
                    if (opcionCambiar == 1){
                        cout << "\nEl color que tiene tu figura por el momento es: " << col.getColor() << endl << endl;;
                    } else if (opcionCambiar == 2){
                        string colorCambiar;
                        cout << "\nIngesa el color por el cual quieres cambiar: ";
                        cin >> colorCambiar;
                        printf("\n");
                        col.setColor(colorCambiar);
                    } else {
                        break;
                    }
                }while(opcionCambiar != 3);
            }
            break;
            case 10: 
                cout << "Se acabo por hoy..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese un numero entre 1 y 10." << endl;
                break;
        }
        
    } while(opcion != 10);
    


    return 0;
}