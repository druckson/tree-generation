#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree() {
    this->shoot = unique_ptr<ITreePart>(new Bud());
}

void Tree::draw() {
    this->shoot->draw();
}

void Tree::grow() {
    auto part = this->shoot->grow();
    if (part != this->shoot.get()) {
        this->shoot.reset(part);
    }
}

void Tree::print() {
    cout << "Tree: " << sizeof(*this) << endl;
    this->shoot->print();
}
