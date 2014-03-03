#include "TreeViewer.h"
#include "tree/Tree.h"
#include <memory>
#include <iostream>
using namespace std;

int main() {
    //unique_ptr<TreeViewer> viewer(new TreeViewer());

    //unique_ptr<TreeGenerator> gen;
    //auto tree = gen->generate(2);
    auto tree = Tree();

    for (int i=0; i<2; i++) {
        tree.grow();
    }

    tree.print();
    //while(true) {
    //    viewer->draw(tree.get());
    //}
}
