#include <memory>
#include <iostream>
#include "Node.h"
#include "Bud.h"
using namespace std;

Node::Node() {
    this->primary = unique_ptr<ITreePart>(new Bud());
    this->secondary = unique_ptr<ITreePart>(new Bud());
}

ITreePart* Node::grow() {
    if (this->primary) {
        auto new_primary = this->primary->grow();
        if (new_primary != this->primary.get()) {
            this->primary.reset(new_primary);
        }
    }

    if (this->secondary) {
        auto new_secondary = this->secondary->grow();
        if (new_secondary != this->secondary.get()) {
            this->secondary.reset(new_secondary);
        }
    }

    return this;
}

void Node::draw() {
    this->primary->draw();
    this->secondary->draw();
}

void Node::print() {
    cout << "Node: " << sizeof(*this) << endl;
    this->primary->print();
    this->secondary->print();
}
