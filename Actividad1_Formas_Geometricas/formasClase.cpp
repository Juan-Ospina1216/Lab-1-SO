#include <string>
#include <iostream>
using namespace std;

// Clase Forma General
class Forma {
private:
    double ancho;
    double altura;
    string color;

public:
    Forma(double ancho, double altura, string color); //Constructor
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;

    // Getters
    double getAncho();
    double getAltura();
    string getColor();
    // Setters
    void setColor(string nuevoColor);
    void setAncho(double nuevoAncho);
    void setAltura(double nuevaAltura);
};

// Clase Rectangulo
class Rectangulo : public Forma {
public:
    Rectangulo(double ancho, double altura, string color); //Constructor
    double calcularArea();
    double calcularPerimetro(); 
};

// Clase Circulo
class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double ancho, double altura, string color, double radio); //Constructor
    double calcularArea();
    double calcularPerimetro();
};

// Clase Cuadrado
class Cuadrado : public Forma {
public:
    Cuadrado(double ancho, double altura, string color); //Constructor
    double calcularArea();
    double calcularPerimetro();
};

// Clase Triangulo
class Triangulo : public Forma {
private:
    double lado1;
    double lado2;
    double lado3;
public:
    Triangulo(double ancho, double altura, string color,double lado1, double lado2, double lado3); //Constructor
    double calcularArea();
    double calcularPerimetro();
};

// Clase Trapecio
class Trapecio : public Forma {
private:
    double baseMenor;
    double baseMayor;
    double lado1;
    double lado2;
public:
    Trapecio(double ancho, double altura, string color, double baseMenor, double baseMayor, 
            double lado1, double lado2); //Constructor
    double calcularArea();
    double calcularPerimetro();
};

// Clase Paralelogramo
class Paralelogramo : public Forma {
private:
    double lado1;
public:
    Paralelogramo(double ancho, double altura, string color,double lado1); //Constructor
    double calcularArea();
    double calcularPerimetro();
};

// Clase Cilindro
class Cilindro : public Forma {
private:
    double radio;
public:
    Cilindro(double ancho, double altura, string color,double radio); //Constructor
    double calcularArea();
    virtual double calcularVolumen();
    double calcularPerimetro();

    double getRadio();
    void setRadio(double radio);
};

// Clase Esfera
class Esfera : public Cilindro {
public:
    Esfera(double ancho, double altura, string color,double radio); //Constructor
    double calcularArea();
    double calcularVolumen();
    double calcularPerimetro();
};
