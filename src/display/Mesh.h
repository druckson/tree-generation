#ifndef MESH_H
#define MESH_H
#include <iostream>
#include <vector>
#include <Eigen/Geometry>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;
using namespace Eigen;

class Mesh {
    GLuint format;
    GLuint mesh;
    vector<Vector3f> vertices;
    bool dirty;

    void SendData() {
        glBufferData(
            GL_ARRAY_BUFFER,
            this->vertices.size()*sizeof(Vector3f),
            &this->vertices[0],
            GL_STATIC_DRAW);
    }
public:
    Mesh(GLuint format) {
        this->format = format;
        this->vertices = vector<Vector3f>();
        this->dirty = false;
        glGenBuffers(1, &this->mesh);
    }

    void AddVertex(Vector3f vertex) {
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
        glVertexPointer(3, GL_FLOAT, sizeof(Vector3f), 0);
        glDrawArrays(this->format, 0, this->vertices.size());
    }
};
#endif
