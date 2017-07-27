//
// Created by Mac on 27.07.17.
//

#include <algorithm>
#include "includes/Vec3d.h"
#include "includes/Camera.h"

Vec3d calulatePhongColor(Camera &camera, )
{
    Vec3d diffuse(0);
    Vec3d specular(0);
    for (uint32_t i = 0; i < lights.size(); ++i) {
        Vec3d lightDir;
        Vec3d lightIntensity;
        IsectInfo isectShad;
        lights[i]->illuminate(hitPoint, lightDir, lightIntensity, isectShad.tNear);

        bool vis = !trace(hitPoint + hitNormal * options.bias, -lightDir, objects, isectShad, kShadowRay);

        // compute the diffuse component
        diffuse += vis * isect.hitObject->albedo * lightIntensity * std::max(0.f, hitNormal.dotProduct(-lightDir));

        // compute the specular component
        // what would be the ideal reflection direction for this light ray
        Vec3f R = reflect(lightDir, hitNormal);
        specular += lightIntensity * vis * std::pow(std::max(0.f, R.dotProduct(-dir)), isect.hitObject->n);
    }
    hitColor = diffuse * isect.hitObject->Kd + specular * isect.hitObject->Ks;


    return hitColor;
}