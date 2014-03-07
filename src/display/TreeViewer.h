#ifndef TREEVIEWER_H
#define TREEVIEWER_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../tree/Tree.h"
#include <iostream>
#include <math.h>
using namespace std;

void error_callback(int i, const char *message) {
    cout << "Error: " << message << endl;
}

class TreeViewer {
    GLFWwindow *window;
    int width, height;
    float angle;
    unique_ptr<MeshCollection> meshes;
public:
    TreeViewer() {
        angle = 0;
        glfwSetErrorCallback(&error_callback);
        glfwInit();
        this->window = glfwCreateWindow(800, 600, "Tree Generator", NULL, NULL);
        if (!this->window) {
            cout << "Failed to create window" << endl;
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(this->window);
        glewInit();

        glfwGetFramebufferSize(this->window, &this->width, &this->height);
        glViewport(0, 0, this->width, this->height);
    }

    ~TreeViewer() {
        glfwTerminate();
    }

    void AddTree(Tree *tree) {
        this->meshes.reset(new MeshCollection());
        tree->draw(this->meshes.get());
    }

    void draw() {
        this->angle += 0.003;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluPerspective(10.0f, (float)width/(float)height, 1, 100);
        gluLookAt( 5.0f, 90*sin(angle),  60*cos(angle),
                    5.0f,  0.0f,  0.0f,
                    1.0f,  0.0f,  0.0f);

        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        this->meshes->draw();

        glFlush();
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
};

#endif
