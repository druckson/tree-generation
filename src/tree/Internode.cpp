#include "Internode.h"
#include "../display/MeshCollection.h"
#include <iostream>
#include <Eigen/Geometry>
using namespace std;

ITreePart* Internode::grow() {
    if (this->child) {
        this->child->grow();
    }
    return this;
}

void Internode::draw(MeshCollection *meshes) {
    meshes->AddCylinder(0.1f, 10, 
        Eigen::Vector3f(), Eigen::Vector3f());

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
