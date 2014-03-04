#ifndef VEC3_h
#define VEC3_h

class Vec3 {
public:
    float x, y, z;
    Vec3() {}

    Vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float operator*(Vec3 &o) {
        return x*o.x +
               y*o.y +
               z*o.z;
    }

    Vec3 operator*(float s) {
        return Vec3(
            x * s,
            y * s,
            z * s
        );
    }

    Vec3 operator/(float s) {
        return Vec3(
            x / s,
            y / s,
            z / s
        );
    }

    Vec3 operator+(Vec3 &o) {
        return Vec3(
            x + o.x,
            y + o.y,
            z + o.z
        );
    }

    Vec3 operator-(Vec3 &o) {
        return Vec3(
            x - o.x,
            y - o.y,
            z - o.z
        );
    }
};

#endif
