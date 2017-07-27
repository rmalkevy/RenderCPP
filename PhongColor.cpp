//
// Created by Mac on 27.07.17.
//

#include <algorithm>

Vec3f castRay(...)
{
    ...
    if (trace(orig, dir, objects, isect)) {
        ...
        switch (isect.hitObject->type) {
            case kPhong:
            {
                Vec3f diffuse = 0, specular = 0;
                for (uint32_t i = 0; i < lights.size(); ++i) {
                    Vec3f lightDir, lightIntensity;
                    IsectInfo isectShad;
                    lights[i]->illuminate(hitPoint, lightDir, lightIntensity, isectShad.tNear);

                    bool vis = !trace(hitPoint + hitNormal * options.bias, -lightDir, objects, isectShad, kShadowRay);

                    // compute the diffuse component
                    diffuse += vis * isect.hitObject->albedo * lightIntensity * std::max(0.f, hitNormal.dotProduct(-lightDir));

                    // compute the specular component
                    // what would be the ideal reflection direction for this light ray
                    Vec3f R = reflect(lightDir, hitNormal);
                    specular += vis * lightIntensity * std::pow(std::max(0.f, R.dotProduct(-dir)), isect.hitObject->n);
                }
                hitColor = diffuse * isect.hitObject->Kd + specular * isect.hitObject->Ks;
                break;
            }
            default:
                break;
        }
    }
    else {
        ...
    }

    return hitColor;
}