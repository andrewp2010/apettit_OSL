#ifndef TRIG_H
#define TRIG_H

float AngleAsUnit(float angle, string unit)
{
    return (unit == "degrees" ? radians(angle) : angle);
}

#endif // TRIG_H