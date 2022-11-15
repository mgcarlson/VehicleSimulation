#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
using namespace std;

#include "MathVector.h"

MathVector :: MathVector(int num_Elements) {
    numElements = num_Elements;
    elements.assign(numElements, 0.00);
}

bool MathVector :: readElements(std::string str) {
    vector<string> elements;
    stringstream ss(str);
    for (int i = 0; std::getline(ss, str, ','); i++) {
        
            elements.at(i) = str;
        }

    if (elements.size() != numElements) {
        return false;
   }

    for(int i = 0; i < elements.size(); i ++) {
        for(int j = 0; j < elements.at(i).length(); j++){
            if(!isdigit(elements.at(i)[j])) {
                return false;
            }
        }
    }
    
    return true;
}
