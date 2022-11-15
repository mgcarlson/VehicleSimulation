#include "MathVector.h"
#include "Vehicle.h"
#include "Director.h"
#include "State.h"
#include "Project2.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void Project2 :: ReadFile(string inputFileName, string outputFileName) {
    std::string line{};
    string type;
    char dummy;
    double w, x, y, delta, theta, Dt;
    MathVector inputValsCheck(2);
    vector <double> inputVals1;
    double t = 0.000;

    // Open the source CSV file
    ifstream myFile; // On the stack
    myFile.open(inputFileName);

    ofstream outP;
    outP.open(outputFileName);

    myFile >> type;
    myFile >> w;

    myFile.clear();

    myFile >> type;
    myFile >> x >> dummy >> y >> dummy >> delta >> dummy >> theta;
    State state1(x, y, delta, theta);
    State *currentState = new State(x, y, delta, theta);
    
    Vehicle myVehicle(state1, w);

    myFile.clear();

    myFile >> type;
    myFile >> Dt;
    myFile.clear();

    while (std::getline(myFile, line)) {
        std::istringstream iss(line);
        
        if (!inputValsCheck.readElements(line)) {
            outP << "Unable to read line [" << line << "] (expected 2 elements)" << endl;
            break;
        }
        
        else {
            while (std::getline(iss, line, ',')) {
                double numdouble = std::stod(line);
                inputVals1.push_back(numdouble);
            }
            
            Input input(double(inputVals1.at(0)), double(inputVals1.at(1)));
                   
            outP << std::setprecision(3) << t << "," << currentState->getX() << "," << currentState->getY() << "," << currentState->getDelta() << "," << currentState->getTheta() << "," << input.getV() << "," << input.getDeltaDot() << endl;
                   
            currentState->setX((myVehicle.update(&input, 0.100))->getX());
            currentState->setY((myVehicle.update(&input, 0.100))->getY());
            currentState->setDelta((myVehicle.update(&input, 0.100))->getDelta());
            currentState->setTheta((myVehicle.update(&input, 0.100))->getTheta());
            
                   t = t + 0.100;
        }
        
    }
}

/*void Project2 :: CreateDirector(vector<double> inputVals) {

}

void Project2 :: CreateVehicle(vector<double> state, vector<double> inputVals) {

}*/
