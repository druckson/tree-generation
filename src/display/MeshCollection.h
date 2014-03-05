#ifndef MESHCOLLECTION_H
#define MESHCOLLECTION_H
#include <iostream>
#include <math.h>
#include <vector>
#include "Mesh.h"
#include <GL/gl.h>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;

class MeshCollection {
    vector<unique_ptr<Mesh>> meshes;
public:
    MeshCollection() {
        this->meshes = vector<unique_ptr<Mesh>>();
    }

    void AddCylinder(float radius, int segments, Vector3f p1, Vector3f p2) {
        unique_ptr<Mesh> mesh(new Mesh(GL_TRIANGLE_STRIP));

        float angle;
        int pointCount = (segments+1)*2;
        vector<Vector3f> points(pointCount);
        
        for (int i=0; i<segments+1; i++) {
            angle = 2.0f*M_PI*(float)i/(float)segments;
            mesh->AddVertex(Vector3f(0.0f, radius*sin(angle), radius*cos(angle)));
            mesh->AddVertex(Vector3f(1.0f, radius*sin(angle), radius*cos(angle)));
        }

        this->meshes.push_back(std::move(mesh));
    }

    void draw() {
        for (int i=0; i<this->meshes.size(); i++) {
            this->meshes[i]->draw();
        }
    }
};
#endif
