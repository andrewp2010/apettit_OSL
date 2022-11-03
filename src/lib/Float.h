#include "Params.h"

#ifndef FLOAT_H
#define FLOAT_H

#define FLOAT_LAYER(lyrNum)                                                       \
    STRING(("Layer" #lyrNum), op##lyrNum, "Normal",                               \
        int connectable = 0, string label = "Operation", string widget = "popup", \
        string options = "Normal|Multiply|Screen|Add|Subtract|Overlay"),          \
    FLOAT(("Layer" #lyrNum), v##lyrNum, 1.0,                                      \
        string label = "Value"),                                                  \
    FLOAT(("Layer" #lyrNum), wt##lyrNum, 1.0,                                     \
        string label = "Weight")

#define FLOAT_LAYER_OPERATION(lyrNum, result)                                        \
    if (numLyr >= lyrNum)                                                            \
        {                                                                            \
            float lyrVal = v##lyrNum;                                                \
            if (op##lyrNum == "Normal")                                              \
            {                                                                        \
                lyrVal = lyrVal;                                                     \
            }                                                                        \
            else if (op##lyrNum == "Multiply")                                       \
            {                                                                        \
                lyrVal *= result;                                                    \
            }                                                                        \
            else if (op##lyrNum == "Screen")                                         \
            {                                                                        \
                lyrVal = 1.0 - (1.0 - result) * (1.0 - lyrVal);                      \
            }                                                                        \
            else if (op##lyrNum == "Add")                                            \
            {                                                                        \
                lyrVal += result;                                                    \
            }                                                                        \
            else if (op##lyrNum == "Subtract")                                       \
            {                                                                        \
                lyrVal -= result;                                                    \
            }                                                                        \
            else if (op##lyrNum == "Overlay")                                        \
            {                                                                        \
                lyrVal = mix((2.0 * result * lyrVal),                                \
                (1.0 - (2.0 * (1.0 - result) * (1.0 - lyrVal))), step(0.5, lyrVal)); \
            }                                                                        \
            result = mix(result, lyrVal, wt##lyrNum);                                \
        }

#endif // FLOAT_H              