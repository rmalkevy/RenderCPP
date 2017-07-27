//
// Created by Mac on 27.07.17.
//

#include <algorithm>
#include "includes/Vec3d.h"
#include "includes/Camera.h"

Vec3d calulatePhongColor(Camera &camera, Vec3d hitColor)
{
    Vec3d diffuse(0);
    Vec3d specular(0);
    Vec3d hitPoint = camera.hitPoint;
    Vec3d hitNormal = camera.hitNormal;

    for (uint32_t i = 0; i < lights.size(); ++i) {
        Vec3d lightDir;
        Vec3d lightIntensity;
        IsectInfo isectShad;
        lights[i]->illuminate(hitPoint, lightDir, lightIntensity, isectShad.tNear);

        bool vis = !trace(hitPoint + hitNormal * options.bias, -lightDir, objects, isectShad, kShadowRay);

        // compute the diffuse component
        diffuse += vis * isect.hitObject->albedo * lightIntensity * std::max(0.f, hitNormal.dot(-lightDir));

        // compute the specular component
        // what would be the ideal reflection direction for this light ray
        Vec3d R = reflect(lightDir, hitNormal);
        specular += lightIntensity * vis * std::pow(std::max(0.f, R.dot(-camera.getDirection())), isect.hitObject->n);
    }
    hitColor = diffuse * isect.hitObject->Kd + specular * isect.hitObject->Ks;


    return hitColor;
}