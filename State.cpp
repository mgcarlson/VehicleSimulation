
#include <vector>
#include <string>
#include "State.h"
using namespace std;

State :: State () : MathVector(4){
    MathVector state(4);
}

State :: State (double x, double y, double delta, double theta) : MathVector(4) {
    MathVector state(4);
    elements.push_back(x);
    elements.push_back(y);
    elements.push_back(delta);
    elements.push_back(theta);
}

double State :: getX( ) {
    return elements.at(0);
}

double State :: getY( ) {
    return elements.at(1);
}

double State :: getDelta( ) {
    return elements.at(2);
}

double State :: getTheta( ) {
    return elements.at(3);
}

void State :: setX (double newX) {
    elements.at(0) = newX;
}

void State :: setY (double newY) {
    elements.at(1) = newY;
}

void State :: setDelta (double newDelta) {
    elements.at(2) = newDelta;
}

void State :: setTheta (double newTheta) {
    elements.at(3) = newTheta;
}


