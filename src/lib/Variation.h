#include "Params.h"

#ifndef VARIATION_H
#define VARIATION_H

#define VARIATION_INPUTS(tag) \
    FLOAT((#tag " Variation"), varPattern##tag, 1.0, \
        string label = #tag " Pattern" ), \
    FLOAT((#tag " Variation"), varMax##tag, 1.0, \
        int connectable = 0, string help = "Value when pattern is 1.0", \
        string label = #tag " Max"), \
    FLOAT((#tag " Variation"), varMid##tag, 0.5, \
        int connectable = 0, string help = "Value when pattern is 0.5", \
        string label = #tag " Mid"), \
    FLOAT((#tag " Variation"), varMin##tag, 0.0, \
        int connectable = 0, string help = "Value when pattern is 0.0", \
        string label = #tag " Min")

float Variation(float value, float min, float mid, float max, float pattern)
{
    float coords[5] = {min, min, mid, max, max};
    return value * spline("linear", pattern, coords);
}

#define VARIATION_SET(value, tag) \
    Variation(value, varMin##tag, varMid##tag, varMax##tag, varPattern##tag)

#endif // VARIATION_H