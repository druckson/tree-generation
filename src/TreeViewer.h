#ifndef TREEVIEWER_H
#define TREEVIEWER_H
#include <GLFW/glfw3.h>
#include "tree/Tree.h"
#include <iostream>
using namespace std;

void error_callback(int i, const char *message) {
    cout << "Error: " << message << endl;
}

class TreeViewer {
    GLFWwindow *window;
public:
    TreeViewer() {
        glfwSetErrorCallback(&error_callback);
        glfwInit();
        this->window = glfwCreateWindow(800, 600, "Tree Generator", NULL, NULL);
        if (!this->window) {
            cout << "Failed to create window" << endl;
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(this->window);
    }

    ~TreeViewer() {
        glfwTerminate();
    }

    void draw(Tree *tree) {
        tree->draw();
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
};

#endif
