#include "Vehicle.h"
#include <vector>
#include <string>
#include <math.h>
using namespace std;

Vehicle :: Vehicle () {
    state->setX(0);
    state->setY(0);
    state->setDelta(0);
    state->setTheta(0);
}

Vehicle :: Vehicle ( State x0, double wheelbaseInp ) {
    state->setX(x0.getX());
    state->setY(x0.getY());
    state->setDelta(x0.getDelta());
    state->setTheta(x0.getTheta());
    wheelbase = wheelbaseInp;
}

double Vehicle :: getWheelbase () {
    return wheelbase;
}

State* Vehicle :: update(Input* u, double ts = 0.100) {

    state->setX( double(state->getX() + ts * u->getV() * cos(state->getDelta()) * cos(state->getTheta())) );
    state->setY( double(state->getY() + ts * u->getV() * cos(state->getDelta()) * sin(state->getTheta())) );
    state->setDelta( double(state->getDelta() + ts * u->getDeltaDot()) );
    state->setTheta( double(state->getTheta() + ts * u->getV() * (1/wheelbase) * sin(state->getDelta())));

    return state;
}
