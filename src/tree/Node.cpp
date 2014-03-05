#include <memory>
#include <iostream>
#include "Node.h"
#include "Bud.h"
using namespace std;

Node::Node() {

}

Node::Node(ITreePart *branch1, ITreePart *branch2) {
    if (branch1) {
        this->primary.reset(branch1);
    }

    if (branch2) {
        this->secondary.reset(branch2);
    }
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

void Node::draw(MeshCollection *meshes) {
    if (this->primary) {
        this->primary->draw(meshes);
    }

    if (this->secondary) {
        this->secondary->draw(meshes);
    }
}

void Node::print() {
    cout << "Node: " << sizeof(*this) << endl;
    if (this->primary) {
        this->primary->print();
    }

    if (this->secondary) {
        this->secondary->print();
    }
}
