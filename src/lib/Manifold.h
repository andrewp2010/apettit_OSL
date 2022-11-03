#include "Params.h"
#include "Math.h"

#ifndef MANIFOLD_H
#define MANIFOLD_H

struct Manifold {
    point Q;
    normal QN;
    float Qradius;
};

void Manifold_Construct(point P, normal N, output Manifold M)
{
    M.Q = P;
    M.QN = N;
    M.Qradius = 0.0;
}

#define MANIFOLD_ZERO() { point(0.0), normal(0.0, 0.0, 1), 0.0 }

#define MANIFOLD_XFORM_PARAMS()                                                 \
    POINT("Transform", origin, point(0.0),                                      \
        string help = "Origin around which the scaling and rotation happens."), \
    FLOAT("Transform", frequency, 1.0,                                          \
        string help = "Frequency is the uniform scale of the transformation."), \
    VEC("Transform", scale, vector(1.0),                                        \
        string help = "Non-uniform scale."),                                    \
    FLOAT("Transform", offset, 0.0,                                             \
        string help = "Amount to offset along the offsetVector."),              \
    VEC("Transform", offsetVector, vector(0.0),                                 \
        string help = "Defines the direction along which to transform."),       \
    POINT("Transform", rotation, point(0.0),                                    \
        string help = "Rotation in degrees for each axis.")

void Manifold_Xform(output Manifold manifold,
                        point origin,
                        float frequency,
                        vector scale,
                        float offset,
                        vector offsetVector,
                        point rotation)
{
    manifold.Q -= origin;

    #define ROTATE(angle, axis)                                           \
        if (abs(angle) > 0.0)                                             \
        {                                                                 \
            float cosAng, sinAng;                                         \
            sincos(-radians(angle), sinAng, cosAng);                      \
            manifold.Q = Math_Rotate##axis(sinAng, cosAng, manifold.Q);   \
            manifold.QN = Math_Rotate##axis(sinAng, cosAng, manifold.QN); \
        } 

    ROTATE(rotation[0], X)
    ROTATE(rotation[1], Y)
    ROTATE(rotation[2], Z)
    #undef ROTATE
    manifold.QN = normalize(manifold.QN);

    vector scaleFactor = vector(Math_SafeDivide(frequency, scale[0]),
                                Math_SafeDivide(frequency, scale[1]),
                                Math_SafeDivide(frequency, scale[2]));
    manifold.Q *= scaleFactor;

    manifold.Q += origin;
    manifold.Q += offsetVector * offset;

    // Only the scale matters for the radius
    // We no longer re-calculate the radius here, since the node that created
    // the Manifold had options fot the radius which we don't know
    manifold.Qradius *= max(abs(scaleFactor[0]),
                            max(abs(scaleFactor[1]),
                                    abs(scaleFactor[2])));
}

#define MANIFOLD_OUTPUT()                                                           \
    OUT_STRUCT(Manifold, resultManifold, MANIFOLD_ZERO(), string label = "Manifold"), \
    OUT_POINT(resultPoint, point(0, 0, 0)),                                         \
    OUT_FLOAT(resultS, 0),                                                          \
    OUT_FLOAT(resultT, 0),                                                          \
    OUT_FLOAT(resultRadius, 0),                                                     \
    OUT_NORMAL(resultN, normal (0, 0, 0)),                                          \
    OUT_FLOAT(resultX, 0),                                                          \
    OUT_FLOAT(resultY, 0),                                                          \
    OUT_FLOAT(resultZ, 0)

void Manifold_Set_Outputs(Manifold resultManifold,
                              output float resultS,
                              output float resultT,
                              output point resultPoint,
                              output normal resultNormal,
                              output float resultRadius,
                              output float resultX,
                              output float resultY,
                              output float resultZ)
{
    resultS = resultManifold.Q[0];
    resultT = resultManifold.Q[1];
    resultPoint = resultManifold.Q;
    resultNormal = resultManifold.QN;
    resultRadius = resultManifold.Qradius;
    resultX = resultManifold.Q[0];
    resultY = resultManifold.Q[1];
    resultZ = resultManifold.Q[2];
}

#define MANIFOLD_SET_OUTPUTS()             \
    Manifold_Set_Outputs(resultManifold,   \
                             resultS,      \
                             resultT,      \
                             resultPoint,  \
                             resultN,      \
                             resultRadius, \
                             resultX,      \
                             resultY,      \
                             resultZ)

#define MANIFOLD_TRANSFORM()         \
    Manifold_Xform(resultManifold,   \
                       origin,       \
                       frequency,    \
                       scale,        \
                       offset,       \
                       offsetVector, \
                       rotation);

#endif //MANIFOLD_H