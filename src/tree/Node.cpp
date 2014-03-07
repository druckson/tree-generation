#include <memory>
#include <iostream>
#include <math.h>
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

void Node::draw(Affine3f transform, MeshCollection *meshes) {
    float r = 2.0f*M_PI * (float)rand()/(float)RAND_MAX;

    Quaternionf rotate1;
    AngleAxisf rotate2(r, Vector3f(1.0f, 0.0f, 0.0f));
    if (this->primary) {
        rotate1.setFromTwoVectors(
            Vector3f(1.0f, 0.0f, 0.0f),
            Vector3f(0.8f, 0.2f, 0.0f));
        this->primary->draw(transform*rotate1*rotate2, meshes);
    }

    if (this->secondary) {
        rotate1.setFromTwoVectors(
            Vector3f(1.0f, 0.0f, 0.0f),
            Vector3f(0.8f,-0.2f, 0.0f));
        this->secondary->draw(transform*rotate1*rotate2, meshes);
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
