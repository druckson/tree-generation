#include "Internode.h"
#include "../Vec3.h"
#include "../shapes.h"
#include <iostream>
using namespace std;

ITreePart* Internode::grow() {
    if (this->child) {
        this->child->grow();
    }
    return this;
}

void Internode::draw() {
    cylinder(1.0f, 8, Vec3(), Vec3());

    if (this->child) {
        this->child->draw(); 
    }
}

void Internode::print() {
    cout << "Internode: " << sizeof(*this) << endl;
    if (this->child) {
        this->child->print();
    }
}
