﻿#include "lambertian.h"
#include "Utilities/Constants.h"
Lambertian::Lambertian():BRDF(),kd(0),cd(0)
{

}

Lambertian::Lambertian(const Lambertian &lambertian):BRDF(lambertian),kd(lambertian.kd),cd(lambertian.cd)
{

}

Lambertian::Lambertian(Lambertian &&lambertian):BRDF(lambertian),kd(lambertian.kd),cd(lambertian.cd)
{

}

RGBColor Lambertian::f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const
{
    return kd*cd*invPI;
}

RGBColor Lambertian::sampleF(const ShadeRec &sr, Vector3D &wo, const Vector3D &wi) const
{
    return RGBColor();
}

RGBColor Lambertian::rho(const ShadeRec &sr, const Vector3D &wo) const
{
    return kd*cd;
}
