#include "Tree.h"
#include <iostream>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;

Tree::Tree() {
    this->shoot.reset(new Bud());
}

void Tree::draw(MeshCollection *meshes) {
    this->shoot->draw(Affine3f::Identity(), meshes);
}

void Tree::grow() {
    auto part = this->shoot->grow();
    if (part != this->shoot.get()) {
        this->shoot.reset(part);
    }
}

void Tree::print() {
    cout << "Tree: " << sizeof(*this) << endl;
    if (this->shoot) {
        this->shoot->print();
    }
}
