#include "directshader.h"
#include "../core/utils.h"

DirectShader::DirectShader() :
    hitColor(Vector3D(1, 0, 0))
{ }

DirectShader::DirectShader(Vector3D hitColor_, Vector3D bgColor_) :
    Shader(bgColor_), hitColor(hitColor_)
{ }

Vector3D DirectShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    if (Utils::hasIntersection(r, objList))
        return hitColor;
    else
        return bgColor;
}
