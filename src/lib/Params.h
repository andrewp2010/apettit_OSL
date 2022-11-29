#ifndef PARAMS_H
#define PARAMS_H

////////////////////////////////////////////////////////////////////////////////
// INPUT PARAMETER MACROS
////////////////////////////////////////////////////////////////////////////////

// [[ ]] causes an OSL syntax error, therefore at least one metadata variable 
// must be included. Since __VA_ARGS__ can be empty, page and label are used for
// this reason (among others).
// 'pg' and 'lbl' must be used as variable names since 'page' and 'label' are 
// already defined OSL symbols.
#define PARAM(pg, lbl, type, name, val, ...) \
    type name = val                          \
    [[                                       \
        string label = lbl,                  \
        string page = pg,                    \
        __VA_ARGS__                          \
    ]]

#define COLOR(pg, lbl, name, val, ...)  PARAM(pg, lbl, color, name, val, __VA_ARGS__)
#define FLOAT(pg, lbl, name, val, ...)  PARAM(pg, lbl, float, name, val, __VA_ARGS__)
#define INT(pg, lbl, name, val, ...)    PARAM(pg, lbl, int, name, val, __VA_ARGS__)
#define NORMAL(pg, lbl, name, val, ...) PARAM(pg, lbl, normal, name, val, __VA_ARGS__)
#define POINT(pg, lbl, name, val, ...)  PARAM(pg, lbl, point, name, val, __VA_ARGS__)
#define STRING(pg, lbl, name, val, ...) PARAM(pg, lbl, string, name, val, \
                                              int connectable = 0, __VA_ARGS__) 
#define VECTOR(pg, lbl, name, val, ...) PARAM(pg, lbl, vector, name, val, __VA_ARGS__)

#define CHECKBOX(pg, lbl, name, val, ...)                \
    INT(pg, lbl, name, val,                              \
        int connectable = 0, string widget = "checkBox", \
        __VA_ARGS__)
#define POPUP(pg, lbl, name, val, opt, ...)              \
    STRING(pg, lbl, name, val,                           \
           int connectable = 0, string widget = "popup", \
           string options = opt, __VA_ARGS__)

////////////////////////////////////////////////////////////////////////////////
// OUTPUT PARAMETER MACROS
////////////////////////////////////////////////////////////////////////////////

#define OUT_PARAM(type, name, val) output type name = val

#define OUT_COLOR(name, val)  OUT_PARAM(color, name, val)
#define OUT_FLOAT(name, val)  OUT_PARAM(float, name, val)
#define OUT_NORMAL(name, val) OUT_PARAM(normal, name, val)
#define OUT_POINT(name, val)  OUT_PARAM(point, name, val)

#endif // PARAMS_H