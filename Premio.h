//
// Created by Elizabeth Huang on 5/7/23.
//

#ifndef PREMIO_H
#define PREMIO_H
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::endl;

class Premio {
private:
    int valor;
    int ID;
    string desc;
    string tipo;
public:
    Premio(string, string, int, int);
    Premio(const Premio&);
    ~Premio();
    friend ostream& operator<< (ostream& os, const Premio* obj);
    friend bool operator== (const Premio& , const Premio* );
    friend bool operator> (const Premio& , const Premio* );


};


#endif
