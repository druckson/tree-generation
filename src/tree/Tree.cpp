#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree() {
    this->shoot.reset(new Bud());
}

void Tree::draw(MeshCollection *meshes) {
    this->shoot->draw(meshes);
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
