#include <iostream>
#include <memory>
#include "Bud.h"
#include "Node.h"
#include "Internode.h"
using namespace std;

Bud::Bud() {

}

ITreePart* Bud::grow() {
    auto node = new Node(); 
    //auto internode = new Internode(); 
    //node->parent = internode;
    //internode->child.reset(node);
    //internode->parent = parent;
    //return internode;
    return node;
}

void Bud::draw() {

}

void Bud::print() {
    cout << "Bud: " << sizeof(*this) << endl;
}
