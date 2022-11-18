#include "Params.h"

#ifndef COLOR_H
#define COLOR_H

struct colorAlpha 
{
    color RGB;
    float A;
};
 
#define COLOR_DB color(1.0, 0.0, 1.0)
#define COLOR_R_DB 1.0
#define COLOR_G_DB 0.0
#define COLOR_B_DB 1.0
#define ALPHA_DB 1.0
#define COLORALPHA_DB { COLOR_DB, 1.0 }
#define COLORALPHA_ZERO {color(0.0), 0.0}

#define COLOR_INPUTS                                     \
    COLOR("", inputRGB, COLOR_DB, string label = "RGB"), \
    FLOAT("", inputA, ALPHA_DB, string label = "Alpha")

#define COLOR_TAG_INPUTS(TAG)                                                 \
    COLOR("color "#TAG, inputRGB_##TAG, COLOR_DB, string label = "RGB "#TAG), \
    FLOAT("color "#TAG, inputA_##TAG, ALPHA_DB, string label = "Alpha "#TAG)

#define COLOR_ALPHA_INPUTS                                                  \
    PARAM("", colorAlpha, inputRGBA, COLORALPHA_DB, string label = "RGBA"), \
    COLOR_PARAM_INPUTS

#define COLOR_ALPHA_TAG_INPUTS(TAG)                              \
    PARAM("color B", colorAlpha, inputRGBA_##TAG, COLORALPHA_DB, \
          string label = "RGBA "#TAG),                           \
    COLOR_PARAM_TAG_INPUTS(tag)

#define COLOR_SPLIT_INPUTS                                       \
    BOOL("", useSplitInputs, 0,                                  \
         int connectable = 0, string label = "Use Split Inputs", \
         string widget = "checkBox"),                            \
    COLOR("", inputRGB, COLOR_DB, string label = "RGB"),         \
    FLOAT("", inputR, COLOR_R_DB, string label = "R"),           \
    FLOAT("", inputG, COLOR_G_DB, string label = "G"),           \
    FLOAT("", inputB, COLOR_B_DB, string label = "B"),           \
    FLOAT("", inputA, ALPHA_DB, string label = "A")

#define COLOR_OUTPUTS                                   \
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

#define COLOR_OUTPUTS_SET                    \
    Color_Set_Outputs(resultRGBA, resultRGB, \
                      resultR, resultG,      \
                      resultB, resultA)

#endif // COLOR_H