#include "formasClase.cpp"
#include <cmath> 

// Constructor de la forma en general
Forma::Forma(double ancho, double altura, string color){     //Constructor
    this->ancho = ancho;
    this->altura = altura;
    this->color = color;
} 

// Constructor de la forma Rectangulo
Rectangulo::Rectangulo(double ancho, double altura, string color) : Forma(ancho,altura,color) {}
double Rectangulo::calcularArea() {
    return getAncho() * getAltura();
}
double Rectangulo::calcularPerimetro() {
    return 2 * (getAncho() + getAltura());
}

// Constructor de la forma Circulo
Circulo::Circulo(double ancho, double altura, string color, double radio) : Forma(ancho,altura,color){
    this->radio = radio;
}
double Circulo::calcularArea(){
    return M_PI * pow(this->radio, 2);
}
double Circulo::calcularPerimetro(){
    return 2 * M_PI * this->radio;
}

// Constructor de la forma Cuadrado
Cuadrado::Cuadrado(double ancho, double altura, string color) : Forma(ancho,altura,color){}
double Cuadrado::calcularArea(){
    return pow(getAncho(), 2);
}
double Cuadrado::calcularPerimetro(){
    return 4 * getAncho();
}

// Constructor de la forma Triangulo
Triangulo::Triangulo(double ancho, double altura, string color,double lado1, double lado2, double lado3) : Forma(ancho,altura,color){
    this->lado1 = lado1;
    this->lado2 = lado2;
    this->lado3 = lado3;
}
double Triangulo::calcularArea(){
    return 0.5  * getAncho() * getAltura();
}
double Triangulo::calcularPerimetro(){
    return this->lado1 + this->lado2 + this->lado3;
}

// Constructor de la forma Trapecio
Trapecio::Trapecio(double ancho, double altura, string color, double baseMenor, double baseMayor, double lado1, double lado2) : Forma(ancho,altura,color){
    this->baseMenor = baseMenor;
    this->baseMayor = baseMayor;
    this->lado1 = lado1;
    this->lado2 = lado2;
}
double Trapecio::calcularArea(){
    return 0.5 * (this->baseMayor + this->baseMenor) * getAltura();
}
double Trapecio::calcularPerimetro(){
    return this->lado1 + this->lado2 + this->baseMayor + this->baseMenor;
}

// Constructor de la forma Paralelogramo
Paralelogramo::Paralelogramo(double ancho, double altura, string color, double lado1) : Forma(ancho,altura,color){
    this->lado1 = lado1;
}
double Paralelogramo::calcularArea(){
    return getAncho() * getAltura();
}
double Paralelogramo::calcularPerimetro(){
    return 2 * (getAncho() * this->lado1);
}

// Constructor de la forma Cilindro
Cilindro::Cilindro(double ancho, double altura, string color, double radio) : Forma(ancho,altura,color){
    this->radio = radio;
}
double Cilindro::calcularArea(){
    return 2 * M_PI * this->radio * (getAltura() + this->radio);
}
double Cilindro::calcularVolumen(){
    return M_PI * pow(this->radio,2) * getAltura();
}
double Cilindro::calcularPerimetro(){
    return 0.0;
}

// Constructor de la forma Esfera
Esfera::Esfera(double ancho, double altura, string color, double radio) : Cilindro(ancho,altura,color,radio){}
double Esfera::calcularArea(){
    return 4 * M_PI * pow(getRadio(),2);
}
double Esfera::calcularVolumen(){
    return 1.33 * M_PI * pow(getRadio(),3);
}
double Esfera::calcularPerimetro(){
    return 0.0;
}

// Getters
double Forma::getAncho(){
    return this->ancho;
}
double Forma::getAltura(){
    return this->altura;
}
string Forma::getColor() {
    return this->color;
}
double Cilindro::getRadio(){
    return this->radio;
}
// Setters
void Forma::setColor(string nuevoColor) {
    this->color = nuevoColor;
}
void Forma::setAncho(double nuevoAncho) {
    this->ancho = nuevoAncho;
}
void Forma::setAltura(double nuevaAltura) {
    this->altura = nuevaAltura;
}
void Cilindro::setRadio(double nuevoRadio) {
    this->radio = nuevoRadio;
}
