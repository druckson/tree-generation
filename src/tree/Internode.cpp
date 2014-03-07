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

void Internode::draw(Affine3f transform, MeshCollection *meshes) {
    auto tip = transform*Translation3f(1.0f, 0.0f, 0.0f);
    meshes->AddCylinder(0.02f, 10,
        transform*Eigen::Vector3f(0.0f, 0.0f, 0.0f), 
        tip*Eigen::Vector3f(0.0f, 0.0f, 0.0f));

    if (this->child) {
        this->child->draw(tip, meshes);
    }
}

void Internode::print() {
    cout << "Internode: " << sizeof(*this) << endl;
    if (this->child) {
        this->child->print();
    }
}
