#ifndef SHAPES_H
#define SHAPES_H
#include "Vec3.h"
#include <memory>
#include <vector>
#include <math.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

void draw(vector<Vec3> vertices) {
    GLuint buf = 0;

    cout << "Draw1" << endl;
    glGenBuffers(1, &buf);
    cout << "Draw2" << endl;

    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, buf);
    cout << "Draw3" << endl;
    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size(),
        &vertices[0],
        GL_STATIC_DRAW);
    cout << "Draw4" << endl;
    glVertexPointer(3, GL_FLOAT, sizeof(Vec3), 0);
    cout << "Draw5" << endl;

    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size());
}

void cylinder(float radius, int segments, Vec3 p1, Vec3 p2) {
    int pointCount = (segments+1)*2;
    vector<Vec3> points(pointCount);
    Vec3 rel = p2 - p1;

    cout << "Cylinder1" << endl;
    
    for (int i=0; i<segments+1; i++) {
        float angle = 2.0f*M_PI*(float)i/(float)segments;
        points[i*2] =   Vec3(0, sin(angle), cos(angle));
        points[i*2+1] = Vec3(0, sin(angle), cos(angle));
    }
    cout << "Cylinder2" << endl;

    draw(points);
}
#endif
