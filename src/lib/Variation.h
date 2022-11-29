#include "Params.h"

#ifndef VARIATION_H
#define VARIATION_H

#define VARIATION_INPUTS(tag) \
    FLOAT((#tag " Variation"), (#tag " Pattern"), varPattern##tag, 1.0), \
    FLOAT((#tag " Variation"), (#tag " Max"), varMax##tag, 1.0, \
        int connectable = 0, string help = "Value when pattern is 1.0"), \
    FLOAT((#tag " Variation"), (#tag " Mid"), varMid##tag, 0.5, \
        int connectable = 0, string help = "Value when pattern is 0.5"), \
    FLOAT((#tag " Variation"), (#tag " Min"), varMin##tag, 0.0, \
        int connectable = 0, string help = "Value when pattern is 0.0")

float Variation(float value, float min, float mid, float max, float pattern)
{
    float coords[5] = {min, min, mid, max, max};
    return value * spline("linear", pattern, coords);
}

#define VARIATION_SET(value, tag) \
    Variation(value, varMin##tag, varMid##tag, varMax##tag, varPattern##tag)

#endif // VARIATION_H