#ifndef MATH_H
#define MATH_H

float Math_SafeDivide(float num, float den)
{
    return (den == 0.0) ? 0.0 : (num / den);
}

color Math_RemapColor(color inputRGB,
                 float inputMin, float inputMax,
                  float outputMin, float outputMax)
{
    float scale = Math_SafeDivide((outputMax - outputMin), (inputMax - inputMin));
    return color(outputMin) + (clamp(inputRGB, color(inputMin), color(inputMax)) - color(inputMin)) * color(scale);
}

float Math_RemapFloat(float inputF,
                 float inputMin, float inputMax,
                  float outputMin, float outputMax)
{
    float scale = Math_SafeDivide((outputMax - outputMin), (inputMax - inputMin));
    return outputMin + (clamp(inputF, inputMin, inputMax) - inputMin) * scale;
}

point Math_RotateX(float sinAng, float cosAng, point Q)
{
    return point(Q[0],
                 (cosAng * Q[1]) - (sinAng * Q[2]),
                 (sinAng * Q[1]) + (cosAng * Q[2]));
}
point Math_RotateX(float angle, point Q)
{
    if (angle != 0.0)
    {
        float cosAng, sinAng;
        sincos(radians(angle), sinAng, cosAng);
        return Math_RotateX(sinAng, cosAng, Q);
    }
    else
    {
        return Q;
    }
}

point Math_RotateY(float sinAng, float cosAng, point Q)
{
    return point((sinAng * Q[2]) + (cosAng * Q[0]),
                 Q[1],
                 (cosAng * Q[2]) - (sinAng * Q[0]));
}
point Math_RotateY(float angle, point Q)
{
    if (angle != 0.0)
    {
        float cosAng, sinAng;
        sincos(radians(angle), sinAng, cosAng);
        return Math_RotateY(sinAng, cosAng, Q);
    }
    else
    {
        return Q;
    }
}

point Math_RotateZ(float sinAng, float cosAng, point Q)
{
    return point((cosAng * Q[0]) - (sinAng * Q[1]),
                 (sinAng * Q[0]) + (cosAng * Q[1]),
                 Q[2]);
}
point Math_RotateZ(float angle, point Q)
{
    if (angle != 0.0)
    {
        float cosAng, sinAng;
        sincos(radians(angle), sinAng, cosAng);
        return Math_RotateZ(sinAng, cosAng, Q);
    }
    else
    {
        return Q;
    }
}

#endif // MATH_H