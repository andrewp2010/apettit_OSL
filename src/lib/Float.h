#include "Params.h"

#ifndef FLOAT_H
#define FLOAT_H

#define FLOAT_DB 0.0

#define FLOAT_INPUTS \
    FLOAT("", inputF, FLOAT_DB, string label = "Float")

#define FLOAT_TAG_INPUTS(TAG) \
    FLOAT("", inputF_##TAG, FLOAT_DB, string label = "Float "#TAG)

#define FLOAT_OUTPUTS                 \
    OUT_FLOAT(resultF, 0.0),          \
    OUT_FLOAT(invertF, (1 - resultF))

#define FLOAT_OUTPUTS_SET \
    invertF = 1 - resultF

#define FLOAT_LAYER(LYR_NUM)                                                      \
    STRING(("Layer " #LYR_NUM), op##LYR_NUM, "Normal",                            \
        int connectable = 0, string label = "Operation", string widget = "popup", \
        string options = "Normal|Multiply|Screen|Add|Subtract|Overlay"),          \
    FLOAT(("Layer " #LYR_NUM), val##LYR_NUM, FLOAT_DB,                            \
        string label = "Value"),                                                  \
    FLOAT(("Layer " #LYR_NUM), wt##LYR_NUM, 1.0,                                  \
        string label = "Weight")

#define FLOAT_LAYER_OPERATION(LYR_NUM, result)                                       \
    if (numLyr >= LYR_NUM)                                                           \
        {                                                                            \
            float lyrVal = val##LYR_NUM;                                             \
            if (op##LYR_NUM == "Normal")                                             \
                lyrVal = lyrVal;                                                     \
            else if (op##LYR_NUM == "Multiply")                                      \
                lyrVal *= result;                                                    \
            else if (op##LYR_NUM == "Screen")                                        \
                lyrVal = 1.0 - (1.0 - result) * (1.0 - lyrVal);                      \
            else if (op##LYR_NUM == "Add")                                           \
                lyrVal += result;                                                    \
            else if (op##LYR_NUM == "Subtract")                                      \
                lyrVal = result - lyrVal;                                            \
            else if (op##LYR_NUM == "Overlay")                                       \
            {                                                                        \
                lyrVal = mix((2.0 * result * lyrVal),                                \
                (1.0 - (2.0 * (1.0 - result) * (1.0 - lyrVal))), step(0.5, lyrVal)); \
            }                                                                        \
            result = mix(result, lyrVal, wt##LYR_NUM);                               \
        }

#endif // FLOAT_H              