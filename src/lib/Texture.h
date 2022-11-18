#include "Color.h"
#include "Params.h"
#include "Manifold.h"

#ifndef TEXTURE_H
#define TEXTURE_H

#define TEXTURE_INPUTS                                                                      \
    PARAM("", Manifold, inputManifold, MANIFOLD_ZERO, string widget = "null"),              \
    STRING("", filename, "",                                                                \
        string label = "File", string widget = "filename", int connectable = 0),            \
    BOOL("", tileTex, 1,                                                                    \
        string label = "Tile", string widget = "checkBox",                                  \
        string help = "Tile the texture", int connectable = 0),                             \
    BOOL("", invertT, 1,                                                                    \
        string label = "Invert T", string widget = "checkBox",                              \
        string help = "Necessary for Renderman", int connectable = 0),                      \
    FLOAT("Scale", scaleGlobal, 1.0,                                                        \
        string label = "Global Scale", int connectable = 0),                                \
    FLOAT("Scale", scaleS, 1.0,                                                             \
        string label = "S Scale", int connectable = 0),                                     \
    FLOAT("Scale", scaleT, 1.0,                                                             \
        string label = "T Scale", int connectable = 0),                                     \
    BOOL("Remap", remap, 0,                                                                 \
        string label = "Remap", string widget = "checkBox", int connectable = 0),           \
    FLOAT("Remap", inputMin, 0.0,                                                           \
        string label = "Input Min", int connectable = 0),                                   \
    FLOAT("Remap", inputMax, 1.0,                                                           \
        string label = "Input Max", int connectable = 0),                                   \
    FLOAT("Remap", outputMin, 0.0,                                                          \
        string label = "Output Min", int connectable = 0),                                  \
    FLOAT("Remap", outputMax, 1.0,                                                          \
        string label = "Output Max", int connectable = 0),                                  \
    COLOR("Missing Color", missingRGB, COLOR_DB,                                            \
        string label = "Missing Color", string help = "Default color if no texture found"), \
    FLOAT("Missing Color", missingA, 1.0,                                                   \
        string label = "Missing Alpha", string help = "Default color if no texture found")

#endif // TEXTURE_H