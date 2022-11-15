#include <vector>
#include <string>
#include <iostream>
#include "MathVector.h"
#include "Input.h"
#include "State.h"
#include "Vehicle.h"
#include "Project2.h"
using namespace std;


int main(int argc, const char * argv[]) {
    Project2 method;
    
    if(argc < 3) {
        cout << "./project2 inputFile outputFile" << endl;
        exit(0);
    }
        
    method.ReadFile(argv[1], argv[2]);

    
    return 0;
}
