#include "Input.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Input :: Input () : MathVector(2) {
    MathVector input(2);
}

Input :: Input (double v, double delta) : MathVector(2) {
    MathVector input(2);
    elements.at(0) = v;
    elements.at(1) = delta;
}

double Input :: getV () {
    return elements.at(0);
}

double Input :: getDeltaDot () {
    return elements.at(1);
}
