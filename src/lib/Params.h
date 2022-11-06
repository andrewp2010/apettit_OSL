#ifndef PARAMS_H
#define PARAMS_H

// [[  ]] causes a syntax error, therefore page is included
#define PARAM(pg, type, name, val, ...) \
        type name = val [[ string page = pg, __VA_ARGS__ ]]

#define COLOR(pg, name, val, ...)   PARAM(pg, color, name, val, __VA_ARGS__)
#define FLOAT(pg, name, val, ...)   PARAM(pg, float, name, val, __VA_ARGS__)
#define INT(pg, name, val, ...)     PARAM(pg, int, name, val, __VA_ARGS__)
#define NORMAL(pg, name, val, ...)  PARAM(pg, normal, name, val, __VA_ARGS__)
#define POINT(pg, name, val, ...)   PARAM(pg, point, name, val, __VA_ARGS__)
#define STRING(pg, name, val, ...)  PARAM(pg, string, name, val, __VA_ARGS__) 
#define VECTOR(pg, name, val, ...)     PARAM(pg, vector, name, val, __VA_ARGS__)
#define BOOL(pg, name, val, ...)    INT(pg, name, val, \
                                        string widget = "checkBox", __VA_ARGS__)

#define OUT_PARAM(type, name, val) output type name = val
#define OUT_COLOR(name, val)       OUT_PARAM(color, name, val)
#define OUT_FLOAT(name, val)       OUT_PARAM(float, name, val)
#define OUT_NORMAL(name, val)      OUT_PARAM(normal, name, val)
#define OUT_POINT(name, val)       OUT_PARAM(point, name, val)

#endif // PARAMS_H