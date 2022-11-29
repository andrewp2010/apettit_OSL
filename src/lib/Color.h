#include "Params.h"
#include "Math.h"

#ifndef COLOR_H
#define COLOR_H

////////////////////////////////////////////////////////////////////////////////
// Structs
////////////////////////////////////////////////////////////////////////////////

struct colorAlpha 
{
    color RGB;
    float A;
    int isPremultiplied;
};
 
////////////////////////////////////////////////////////////////////////////////
// Macro Default Macros
////////////////////////////////////////////////////////////////////////////////

#define R_DEF 1.0
#define G_DEF 0.0
#define B_DEF 1.0
#define ALPHA_DEF 1.0
#define PREMULT_DEF 1
#define COLOR_DEF color(R_DEF, G_DEF, B_DEF)
#define COLOR_ONE color(1.0)
#define COLOR_ZERO color(0.0)
#define COLORALPHA_DEF {COLOR_DEF, ALPHA_DEF, PREMULT_DEF}
#define COLORALPHA_ONE {color(1), 1, 1}
#define COLORALPHA_ZERO {color(0.0), 0.0, 0}

////////////////////////////////////////////////////////////////////////////////
// Input Macros
////////////////////////////////////////////////////////////////////////////////

#define COLOR_INPUTS                      \
    COLOR("", "RGB", inputRGB, COLOR_DEF), \
    FLOAT("", "Alpha", inputA, ALPHA_DEF)

// inputRGBA is defined as inputRGBA_ so that when COLOR_ALPHA_TAG_INPPUTS_GET is 
// called it can serve as an intermediary variable and the result variable the user will reference 
// is inputRGBA. Which is a bit clearer to read at the shader level
#define COLOR_ALPHA_INPUTS                                                            \
    PARAM("", "RGBA", colorAlpha, inputRGBA_, COLORALPHA_DEF),                        \
    COLOR_INPUTS,                                                                     \
    CHECKBOX("", "Premultiply Input", premultiplyInput, 1,                            \
             string help = "Whether layer inputRGB is premultiplied by layer inputA")

#define COLOR_SPLIT_INPUTS                                                                     \
    COLOR("", "Color", inputRGB, COLOR_DEF),                                                   \
    FLOAT("", "A", inputA, ALPHA_DEF),                                                         \
    CHECKBOX("", "Use Split Inputs", useSplitInputs, 0),                                       \
    FLOAT("", "R", inputR, R_DEF),                                                             \
    FLOAT("", "G", inputG, G_DEF),                                                             \
    FLOAT("", "B", inputB, B_DEF),                                                             \
    CHECKBOX("", "Premultiply Output", premultiplyOutput, 1,                                   \
             string help = "Normally this is on. All RGBA structs are assumed premultiplied.")

#define COLOR_ALPHA_INPUTS_GET                               \
    colorAlpha inputRGBA;                                    \
    if (isconnected(inputRGBA_))                             \
        inputRGBA = inputRGBA_;                              \
    else                                                     \
    {                                                        \
        inputRGBA.RGB = inputRGB;                            \
        inputRGBA.A = inputA;                                \
        inputRGBA.isPremultiplied = 0;                       \
    }                                                        \
    if (!inputRGBA.isPremultiplied && premultiplyInput)      \
        Premultiply(inputRGBA);                              \
    else if (inputRGBA.isPremultiplied && !premultiplyInput) \
        Unpremultiply(inputRGBA)

////////////////////////////////////////////////////////////////////////////////
// Input Tag Macros
////////////////////////////////////////////////////////////////////////////////

#define COLOR_TAG_INPUTS(TAG)                                     \
    COLOR("color "#TAG, "Color "#TAG, inputRGB_##TAG, COLOR_DEF), \
    FLOAT("color "#TAG, "Alpha "#TAG, inputA_##TAG, ALPHA_DEF)

// inputRGBA is defined as inputRGBA_##TAG##_ so that when COLOR_ALPHA_TAG_INPPUTS_GET(TAG) is 
// called it can serve as an intermediary variable and the result variable the user will reference 
// is inputRGBA_##TAG. Which is a bit clearer to read at the shader level
#define COLOR_ALPHA_TAG_INPUTS(TAG)                                                          \
    PARAM("color "#TAG, "Color Alpha "#TAG, colorAlpha, inputRGBA_##TAG##_, COLORALPHA_DEF), \
    COLOR_TAG_INPUTS(TAG),                                                                   \
    CHECKBOX("color "#TAG, "Premultiply Input "#TAG, premultiplyInput_##TAG, 1,              \
             string help = "Whether layer inputRGB is premultiplied by layer inputA")

#define COLOR_ALPHA_TAG_INPUTS_GET(TAG)                                  \
    colorAlpha inputRGBA_##TAG;                                          \
    if (isconnected(inputRGBA_##TAG##_))                                 \
        inputRGBA_##TAG = inputRGBA_##TAG##_;                            \
    else                                                                 \
    {                                                                    \
        inputRGBA_##TAG.RGB = inputRGB_##TAG;                            \
        inputRGBA_##TAG.A = inputA_##TAG;                                \
        inputRGBA_##TAG.isPremultiplied = 0;                             \
    }                                                                    \
    if (!inputRGBA_##TAG.isPremultiplied && premultiplyInput_##TAG)      \
        Premultiply(inputRGBA_##TAG);                                    \
    else if (inputRGBA_##TAG.isPremultiplied && !premultiplyInput_##TAG) \
        Unpremultiply(inputRGBA_##TAG)

////////////////////////////////////////////////////////////////////////////////
// Output Macros
////////////////////////////////////////////////////////////////////////////////

#define COLOR_OUTPUTS                 \
    OUT_COLOR(resultRGB, COLOR_ZERO), \
    OUT_FLOAT(resultR, 0.0),   \
    OUT_FLOAT(resultG, 0.0),   \
    OUT_FLOAT(resultB, 0.0)

#define COLOR_OUTPUTS_SET   \
    resultR = resultRGB[0]; \
    resultG = resultRGB[1]; \
    resultB = resultRGB[2]

#define COLOR_ALPHA_OUTPUTS                                          \
    OUT_PARAM(colorAlpha, resultRGBA, COLORALPHA_ZERO),              \
    OUT_COLOR(resultRGB, COLOR_ZERO),                                \
    OUT_FLOAT(resultR, 0.0),                                         \
    OUT_FLOAT(resultG, 0.0),                                         \
    OUT_FLOAT(resultB, 0.0),                                         \
    OUT_FLOAT(resultA, 0.0)

#define COLOR_ALPHA_OUTPUTS_SET    \
    resultRGB = resultRGBA.RGB;    \
    resultR = resultRGBA.RGB[0];   \
    resultG = resultRGBA.RGB[1];   \
    resultB = resultRGBA.RGB[2];   \
    resultA = resultRGBA.A

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void ColorAlphaClamp(output colorAlpha inputRGBA)
{
    colorAlpha tmpRGBA;
    inputRGBA.RGB = clamp(inputRGBA.RGB, COLOR_ZERO, COLOR_ONE);
    inputRGBA.A = clamp(inputRGBA.A, 0.0, 1.0);
}

void Premultiply(output colorAlpha RGBA)
{
    if (!RGBA.isPremultiplied)
    {
        RGBA.RGB *= RGBA.A;
        RGBA.isPremultiplied = 1;
    }
}

void Unpremultiply(output colorAlpha RGBA)
{
    if (RGBA.isPremultiplied)
    {
        RGBA.RGB /= RGBA.A;
        RGBA.isPremultiplied = 0;
    }
}

color RGBtoHSV(color rgb)
{
    // clamp R, G, B values below 0.0 to 0.0
    float r = max(rgb[0], 0.0);
    float g = max(rgb[1], 0.0);
    float b = max(rgb[2], 0.0);

    float cMax = max(r, max(g, b));
     // set value, before inputRGB overrange check
    float v = cMax;
    // normalize R, G, B values for hue/sat calculation, if inputRGB value is over 1.0
    if (cMax > 1.0)
    {
        r = r / cMax;
        g = g / cMax;
        b = b / cMax;
        cMax = 1.0;
    }
    float cMin = min(r, min(g, b));
    float delta = cMax - cMin;

    // calculate hue
    float h = 0.0;
    if (cMax <= r)
        h = (((g - b) / delta) + 6.0) / 6.0;
    else if (cMax <= g)
        h = (((b - r) / delta) + 2.0) / 6.0;
    else if (cMax <= b)
        h = (((r - g) / delta) + 4.0) / 6.0;
    if (h < 0.0)
        h += 1.0;

    // calculate sat
    float s = 0.0;
    if (cMax > 0.0)
        s = delta / cMax;

    return color(h, s, v);  
}

color HSVtoRGB(color hsv)
{
    float h = hsv[0];
    float s = hsv[1];
    float v = hsv[2];

    color rgb;
    float hh = 6.0 * Remainder(h);
    int hi = (int)hh;
    float f = hh - hi;
    // clamp overrange values for hue/sat calculations
    float vv = min(v, 10);
    float ss = clamp(s, 0.0, 1.0);
    float p = vv * (1.0 - ss);
    float q = vv * (1.0 - (ss * f));
    float t = vv * (1.0 - (ss * (1.0 - f)));

    if (hi == 0)
        rgb = color(vv, t, p);
    else if (hi == 1)
        rgb = color(q, vv, p);
    else if (hi == 2)
        rgb = color(p, vv, t);
    else if (hi == 3)
        rgb = color(p, q, vv);
    else if (hi == 4)
        rgb = color(t, p, vv);
    else
        rgb = color(vv, p, q);
    // if value was clamped, return to overrange value
    if (v > 1.0)
        rgb *= v;

    return rgb;
}

#endif // COLOR_H