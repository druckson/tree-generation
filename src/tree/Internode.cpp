#include "Internode.h"
#include "../Vec3.h"
#include "../display/MeshCollection.h"
#include <iostream>
using namespace std;

ITreePart* Internode::grow() {
    if (this->child) {
        this->child->grow();
    }
    return this;
}

void Internode::draw(MeshCollection *meshes) {
    meshes->AddCylinder(0.1f, 10, Vec3(), Vec3());

    if (this->child) {
        this->child->draw(meshes);
    }
}

void Internode::print() {
    cout << "Internode: " << sizeof(*this) << endl;
    if (this->child) {
        this->child->print();
    }
}
