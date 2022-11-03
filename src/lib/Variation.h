#ifndef VARIATION_H
#define VARIATION_H

#define VARIATION_PARAMS(PREFIX, GROUP) \
    float PREFIX##VarPattern = 0.5 \
    [[ \
        string page = GROUP "Variation" \
    ]], \
    float PREFIX##VarMax = 1.0 \
    [[ \
        int connectable = 0, \
        string help = "Value whwen pattern is 1", \
        string page = GROUP "Variation", \
    ]], \
    float PREFIX##VarMid = 1.0 \
    [[ \
        int connectable = 0, \
        string help = "Value when pattern is 0.5", \
        string page = GROUP "Variation" \
    ]], \
    float PREFIX##VarMin = 1.0 \
    [[ \
        int connectable = 0, \
        string help = "Value when pattern is 0.0", \
        string page = GROUP "Variation" \
    ]]

float VariationVary(float min, float mid, float max, float pattern)
{
    float coords[5] = {min, min, mid, max, max};
    return spline("linear", pattern, coords);
}

#endif // VARIATION_H