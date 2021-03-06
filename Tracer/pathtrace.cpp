#include "pathtrace.h"
#include "Utilities/Constants.h"
#include <QDebug>
PathTrace::PathTrace():Tracer()
{}

PathTrace::PathTrace(World* _worldPtr): Tracer(_worldPtr)
{}

RGBColor PathTrace::trace_ray(const Ray& ray, const int depth) const {
    if (depth > world_ptr->setting->maxDepth)
        return RGBColor();
    else {
        ShadeRec sr(world_ptr->hitObject(ray));

        if (sr.hit_an_object) {
            sr.depth = depth;
            sr.ray = ray;
            return (sr.material_ptr->pathShade(sr));
        }
        else
            return (world_ptr->setting->backergroundColor);
    }
}

RGBColor PathTrace::trace_ray(const Ray& ray, double& tmin, const int depth) const {
    if (depth > world_ptr->setting->maxDepth)
        return RGBColor();
    else {
        ShadeRec sr(world_ptr->hitObject(ray));

        if (sr.hit_an_object) {
            sr.depth 	= depth;
            sr.ray 		= ray;
            tmin		= sr.t;     // required for colored transparency
            return (sr.material_ptr->pathShade(sr));
        }
        else{
            tmin = kHugeValue;
            return (world_ptr->setting->backergroundColor);
        }
    }
}
