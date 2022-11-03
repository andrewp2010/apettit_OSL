#include "Params.h"
#include "Manifold.h"

#ifndef TEXTURE_H
#define TEXTURE_H

#define TEXTURE_MANIFOLD_INPUT() \
    PARAM("", Manifold, inputManifold, MANIFOLD_ZERO)

#define TEXTURE_INPUT_PARAMS()                                                              \
    STRING("", filename, "",                                                                \
        string label = "File", string widget = "filename", int connectable = 0),            \
    BOOL("", invertT, 1,                                                                    \
        string label = "Invert T", string widget = "checkBox",                              \
        string help = "Necessary for Renderman", int connectable = 0),                      \
    FLOAT("Scale", scaleGlobal, 1.0,                                                        \
        string label = "Global Scale", int connectable = 0),                                \
    FLOAT("Scale", scaleS, 1.0,                                                             \
        string label = "Scale S", int connectable = 0),                                     \
    FLOAT("Scale", scaleT, 1.0,                                                             \
        string label = "Scale T", int connectable = 0),                                     \
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
    COLOR("Missing Color", missingColor, color(1.0, 0.0, 1.0),                              \
        string label = "Missing Color", string help = "Default color if no texture found"), \
    FLOAT("Missing Color", missingAlpha, 1.0,                                               \
        string label = "Missing Alpha", string help = "Default color if no texture found")

#endif // TEXTURE_H