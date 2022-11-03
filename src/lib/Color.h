#include "Params.h"

#ifndef COLOR_H
#define COLOR_H

struct colorAlpha 
{
    color RGB;
    float A;
};
 
#define COLOR_DB color(1.0, 0.0, 1.0)
#define COLORALPHA_DB { COLOR_DB, 1.0 }
#define COLORALPHA_ZERO {color(0.0), 0.0}

#define COLOR_PARAM_INPUTS                               \
    COLOR("", inputRGB, COLOR_DB, string label = "RGB"), \
    FLOAT("", inputA, 1.0, string label = "Alpha")

#define COLOR_PARAM_TAG_INPUTS(tag)                                             \
    COLOR("color "#tag, inputRGB_##tag, COLOR_DB, string label = "RGB "#tag), \
    FLOAT("color "#tag, inputA_##tag, 1.0, string label = "Alpha "#tag)

#define COLOR_ALPHA_PARAM_INPUTS                                            \
    PARAM("", colorAlpha, inputRGBA, COLORALPHA_DB, string label = "RGBA"), \
    COLOR_PARAM_INPUTS

#define COLOR_ALPHA_PARAM_TAG_INPUTS(tag)                            \
    PARAM("color B", colorAlpha, inputRGBA_##tag, COLORALPHA_DB, \
          string label = "RGBA "#tag, string widget = "null"),                                \
    COLOR_PARAM_TAG_INPUTS(tag)

#define COLOR_SPLIT_PARAM_INPUTS()                              \
    BOOL("", useSplitInputs, 0,                                 \
        int connectable = 0, string label = "Use Split Inputs", \
        string widget = "checkBox"),                            \
    COLOR("", inputRGB, COLOR_DB, string label = "RGB"),        \
    FLOAT("", inputR, 0.0, string label = "R"),                 \
    FLOAT("", inputG, 0.0, string label = "G"),                 \
    FLOAT("", inputB, 0.0, string label = "B"),                 \
    FLOAT("", inputA, 1.0, string label = "A")

#define COLOR_PARAM_OUTPUTS()                           \
    OUT_PARAM(colorAlpha, resultRGBA, COLORALPHA_ZERO), \
    OUT_COLOR(resultRGB, color(0.0)),                   \
    OUT_FLOAT(resultR, 0.0),                            \
    OUT_FLOAT(resultG, 0.0),                            \
    OUT_FLOAT(resultB, 0.0),                            \
    OUT_FLOAT(resultA, 0.0)

void Color_Set_Outputs(colorAlpha resultRGBA, output color resultRGB,
                       output float resultR, output float resultG,
                       output float resultB, output float resultA)
{
    resultRGB = resultRGBA.RGB;
    resultR = resultRGBA.RGB[0];
    resultG = resultRGBA.RGB[1];
    resultB = resultRGBA.RGB[2];
    resultA = resultRGBA.A;
}

#define COLOR_PARAM_OUTPUTS_SET()            \
    Color_Set_Outputs(resultRGBA, resultRGB, \
                      resultR, resultG,      \
                      resultB, resultA)

#endif // COLOR_H