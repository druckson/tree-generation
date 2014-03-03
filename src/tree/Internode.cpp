#include "Internode.h"
#include <iostream>
using namespace std;

ITreePart* Internode::grow() {
    if (this->child) {
        this->child->grow();
    }
    return this;
}

void Internode::draw() {
   this->child->draw(); 
}

void Internode::print() {
    cout << "Internode: " << sizeof(*this) << endl;
    if (this->child) {
        this->child->print();
    }
}
