﻿#ifndef BRDF_H
#define BRDF_H
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Vector3D.h"
#include "Sampler/sampler.h"
class BRDF
{
public:
    BRDF();

    ~BRDF();

    virtual RGBColor f(const ShadeRec& sr,const Vector3D& wi,const Vector3D& wo) const =0;

    virtual RGBColor sampleF(const ShadeRec& sr,Vector3D& wi,const Vector3D& wo) const;

    virtual RGBColor sampleF(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;

    virtual RGBColor rho(const ShadeRec& sr,const Vector3D& wo) const=0;
protected:
    Sampler* sampler_ptr;
};

#endif // BRDF_H
