//
//  MathVector.h
//  Project2
//
//  Created by Maddie Carlson on 10/19/22.
//

#ifndef MathVector_h
#define MathVector_h

#include <stdio.h>
#include <string>
#include <vector>

class MathVector {
public:
    MathVector( int numElements );
    ~MathVector( ) { elements.clear(); };
    bool readElements( std::string str );
    // creates a csv of this vector
    std::string toString( );
protected:
    int numElements;
    std::vector<double> elements;
};

#endif /* MathVector_h */
