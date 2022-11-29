#include "Color.h"
#include "Params.h"
#include "Manifold.h"

#ifndef TEXTURE_H
#define TEXTURE_H

////////////////////////////////////////////////////////////////////////////////
// Input Macros
////////////////////////////////////////////////////////////////////////////////

#define TEXTURE_INPUTS                                                             \
    PARAM("", "", Manifold, inputManifold, MANIFOLD_ZERO, string widget = "null"), \
    STRING("", "File", filename, "",                                               \
        string widget = "filename", int connectable = 0),                          \
    CHECKBOX("", "Tile", tileTex, 1, string help = "Tile the texture"),            \
    CHECKBOX("", "Invert T", invertT, 1, string help = "Necessary for Renderman"), \
    FLOAT("Scale", "Global Scale", scaleGlobal, 1.0, int connectable = 0),         \
    FLOAT("Scale", "S Scale", scaleS, 1.0, int connectable = 0),                   \
    FLOAT("Scale", "T Scale", scaleT, 1.0, int connectable = 0),                   \
    CHECKBOX("Remap", "Remap", remap, 0),                                          \
    FLOAT("Remap", "Input Min", inputMin, 0.0, int connectable = 0),               \
    FLOAT("Remap", "Input Max", inputMax, 1.0, int connectable = 0),               \
    FLOAT("Remap", "Output Min", outputMin, 0.0, int connectable = 0),             \
    FLOAT("Remap", "Output Max", outputMax, 1.0, int connectable = 0),             \
    COLOR("Missing Color", "Missing Color", missingRGB, COLOR_DEF,                 \
          string help = "Default color if no texture found"),                      \
    FLOAT("Missing Color", "Missing Alpha", missingA, ALPHA_DEF,                   \
          string help = "Default color if no texture found")

#endif // TEXTURE_H