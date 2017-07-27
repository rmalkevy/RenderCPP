//
// Created by Mac on 22.07.17.
//

#ifndef RENDERCPP_RENDERFUNCTIONS_H
#define RENDERCPP_RENDERFUNCTIONS_H

#include "Render.h"
#include "Vec3d.h"

void	renderImage(Render &render);
void	renderPixel(Camera &camera,
                    std::list<IPrimitive*> &listObjects,
                    Vec3d rayOrig,
                    Vec3d rayDir);
void	tracingScreen(Window &window,
                      Camera &camera,
                      std::list<IPrimitive*> &listObjects );

inline double minDistance( double t0, double t1 )
{
    if (t0 < 0)
        t0 = t1;
    if (t0 > t1)
        t0 = t1;
    return ( t0 );
}

#endif //RENDERCPP_RENDERFUNCTIONS_H
