#include "phong.h"

#include <iostream>

Phong::Phong()
{ }

Vector3D Phong::getReflectance(const Vector3D& n, const Vector3D& wo,
    const Vector3D& wi) const {
    //r(wi,wo)=kd(wi·n)+ks(wo·wr)^n
    double kd;
    double ks;
    double refx = ks * (wo.x * wi.x) + ks * pow((wo.x * wi.x), n.x);
    double refy = ks * (wo.y * wi.y) + ks * pow((wo.y * wi.y), n.y);
    double refz = ks * (wo.z * wi.z) + ks * pow((wo.z * wi.z), n.z);
    Vector3D refl = Vector3D(refx, refy, refz);


    return refl;
}

double Material::getIndexOfRefraction() const
{
    std::cout << "Warning! Calling \"Material::getIndexOfRefraction()\" for a non-transmissive material"
              << std::endl;

    return -1;
}
