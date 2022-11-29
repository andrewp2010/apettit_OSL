#include "Math.h"
#include "Params.h"

#ifndef FLOAT_H
#define FLOAT_H

////////////////////////////////////////////////////////////////////////////////
// Input Macros
////////////////////////////////////////////////////////////////////////////////

#define FLOAT_INPUTS \
    FLOAT("", "Float", inputF, 0.0)

////////////////////////////////////////////////////////////////////////////////
// Input Tag Macros
////////////////////////////////////////////////////////////////////////////////

#define FLOAT_TAG_INPUTS(TAG) \
    FLOAT("", "Float "#TAG, inputF_##TAG, 0.0)

#define FLOAT_LAYER(LYR_NUM)                                                                      \
    STRING(("Layer " #LYR_NUM), "Operation", op##LYR_NUM, "Normal", int connectable = 0,          \
        string widget = "popup", string options = "Normal|Multiply|Screen|Add|Subtract|Overlay"), \
    FLOAT(("Layer " #LYR_NUM), "Value", val##LYR_NUM, 0.0)   ,                              \
    FLOAT(("Layer " #LYR_NUM), "Weight", wt##LYR_NUM, 1.0)

#define FLOAT_LAYER_OPERATION(LYR_NUM, result)         \
    if (numLyr >= LYR_NUM)                             \
        {                                              \
            float lyrVal = val##LYR_NUM;               \
            if (op##LYR_NUM == "Normal")               \
                lyrVal = lyrVal;                       \
            else if (op##LYR_NUM == "Multiply")        \
                lyrVal *= result;                      \
            else if (op##LYR_NUM == "Screen")          \
                lyrVal = Screen(result, lyrVal);       \
            else if (op##LYR_NUM == "Add")             \
                lyrVal += result;                      \
            else if (op##LYR_NUM == "Subtract")        \
                lyrVal = result - lyrVal;              \
            else if (op##LYR_NUM == "Overlay")         \
                lyrVal = Overlay(result, lyrVal);      \
            result = mix(result, lyrVal, wt##LYR_NUM); \
        }

////////////////////////////////////////////////////////////////////////////////
// Output Macros
////////////////////////////////////////////////////////////////////////////////

#define FLOAT_OUTPUTS                 \
    OUT_FLOAT(resultF, 0.0),          \
    OUT_FLOAT(invertF, (1 - resultF))

#define FLOAT_OUTPUTS_SET \
    invertF = 1 - resultF

#endif // FLOAT_H              