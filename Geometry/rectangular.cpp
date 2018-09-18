﻿#include "rectangular.h"
#include "Sampler/sampler.h"
const double Rectangular::kEpsilon = 0.001;
Rectangular::Rectangular():Geometry(),
          p0(-1, 0, -1),
          a(0, 0, 2), b(2, 0, 0),
          a_len_squared(4.0),
          b_len_squared(4.0),
          normal(0, 1, 0),
          area(4.0),
          inv_area(0.25),
          sampler_ptr(NULL)
{

}

Rectangular::Rectangular(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b)
    :	Geometry(),
        p0(_p0),
        a(_a),
        b(_b),
        a_len_squared(a.len_squared()),
        b_len_squared(b.len_squared()),
        area(a.length() * b.length()),
        inv_area(1.0 / area),
        sampler_ptr(nullptr)
{
    normal = a ^ b;
    normal.normalize();
}

Rectangular::Rectangular(const Point3D& _p0,const Vector3D& _a,const Vector3D& _b,const Normal& _normal):Geometry(),
    p0(_p0),a(_a),b(_b),normal(_normal),a_len_squared(a.len_squared()),b_len_squared(b.len_squared()),
    area(a.length()*b.length()),inv_area(1.0/area),sampler_ptr(nullptr)
{
    normal.normalize();
}

bool Rectangular::hit(const Ray &ray, double &tmin, ShadeRec &sr) const
{
    double t = (p0 - ray.origin) * normal / (ray.direction * normal);

    if (t <= kEpsilon)
        return (false);

    Point3D p = ray.origin + t * ray.direction;
    Vector3D d = p - p0;

    double ddota = d * a;

    if (ddota < 0.0 || ddota > a_len_squared)
        return (false);

    double ddotb = d * b;

    if (ddotb < 0.0 || ddotb > b_len_squared)
        return (false);

    tmin 				= t;
    sr.normal 			= normal;
    sr.local_hit_point 	= p;

    return (true);
}

bool Rectangular::shadowHit(const Ray &ray, double &tmin) const
{
    double t = (p0 - ray.origin) * normal / (ray.direction * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.origin + t * ray.direction;
    Vector3D d = p - p0;

    double ddota = d * a;

    if (ddota < 0.0 || ddota > a_len_squared)
        return (false);

    double ddotb = d * b;

    if (ddotb < 0.0 || ddotb > b_len_squared)
        return (false);

    tmin 				= t;

    return true;
}

void Rectangular::setSampler(Sampler *sampler)
{
    sampler_ptr=sampler;
}

Point3D Rectangular::sampler()
{
    Point2D sample_point=sampler_ptr->sampleUnitSquare();
    return p0+sample_point.x*a+sample_point.y*b;
}

float Rectangular::pdf(ShadeRec &sr)
{
    return inv_area;
}

Normal Rectangular::getNormal(const Point3D &p) const
{
    return normal;
}
