#ifndef MESH_H
#define MESH_H
#include <iostream>
#include <vector>
#include "../Vec3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

class Mesh {
    GLuint format;
    GLuint mesh;
    vector<Vec3> vertices;
    bool dirty;

    void SendData() {
        glBufferData(
            GL_ARRAY_BUFFER,
            this->vertices.size()*sizeof(Vec3),
            &this->vertices[0],
            GL_STATIC_DRAW);
    }
public:
    Mesh(GLuint format) {
        this->format = format;
        this->vertices = vector<Vec3>();
        this->dirty = false;
        glGenBuffers(1, &this->mesh);
    }

    void AddVertex(Vec3 vertex) {
        this->vertices.push_back(vertex);
        this->dirty = true;
    }

    void draw() {
        glEnableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, this->mesh); 

        if (this->dirty) {
            this->SendData();
            this->dirty = false;
        }
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, this->mesh); 
        glVertexPointer(3, GL_FLOAT, sizeof(Vec3), 0);
        glDrawArrays(this->format, 0, 3*this->vertices.size());
    }
};
#endif
