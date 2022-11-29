#ifndef MATH_H
#define MATH_H

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

float Overlay(float a, float b)
{
    return mix((2.0 * a * b), (1.0 - (2.0 * (1.0 - a) * (1.0 - b))), step(0.5, b));
}

float Remainder(float f)
{
    return f - floor(f);
}

float SafeDivide(float num, float den)
{
    return (den == 0.0) ? 0.0 : (num / den);
}

float Screen(float a, float b)
{
    return 1.0 - ((1.0 - a) * (1.0 - b));
}

color RemapColor(color inputRGB,
                 float inputMin, float inputMax,
                 float outputMin, float outputMax)
{
    float scale = SafeDivide((outputMax - outputMin), (inputMax - inputMin));
    return color(outputMin) + (clamp(inputRGB, color(inputMin), color(inputMax)) - color(inputMin)) * color(scale);
}

float RemapFloat(float inputF,
                 float inputMin, float inputMax,
                 float outputMin, float outputMax)
{
    float scale = SafeDivide((outputMax - outputMin), (inputMax - inputMin));
    return outputMin + (clamp(inputF, inputMin, inputMax) - inputMin) * scale;
}

point RotateX(float sinAng, float cosAng, point Q)
{
    return point(Q[0],
                 (cosAng * Q[1]) - (sinAng * Q[2]),
                 (sinAng * Q[1]) + (cosAng * Q[2]));
}
point RotateX(float angle, point Q)
{
    if (angle != 0.0)
    {
        float cosAng, sinAng;
        sincos(radians(angle), sinAng, cosAng);
        return RotateX(sinAng, cosAng, Q);
    }
    else
        return Q;
}

point RotateY(float sinAng, float cosAng, point Q)
{
    return point((sinAng * Q[2]) + (cosAng * Q[0]),
                 Q[1],
                 (cosAng * Q[2]) - (sinAng * Q[0]));
}
point RotateY(float angle, point Q)
{
    if (angle != 0.0)
    {
        float cosAng, sinAng;
        sincos(radians(angle), sinAng, cosAng);
        return RotateY(sinAng, cosAng, Q);
    }
    else
        return Q;
}

point RotateZ(float sinAng, float cosAng, point Q)
{
    return point((cosAng * Q[0]) - (sinAng * Q[1]),
                 (sinAng * Q[0]) + (cosAng * Q[1]),
                 Q[2]);
}
point RotateZ(float angle, point Q)
{
    if (angle != 0.0)
    {
        float cosAng, sinAng;
        sincos(radians(angle), sinAng, cosAng);
        return RotateZ(sinAng, cosAng, Q);
    }
    else
        return Q;
}

#endif // MATH_H