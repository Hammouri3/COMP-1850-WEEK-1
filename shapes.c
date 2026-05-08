#include <math.h>
#include <stdbool.h>

#include "shapes.h"

/*
  Structure initialisation functions
*/

Point makePoint(float x, float y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

Line makeLine(Point p1, Point p2) {
    Line l;
    l.p[0] = p1;
    l.p[1] = p2;
    return l;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle t;
    t.p[0] = p1;
    t.p[1] = p2;
    t.p[2] = p3;
    return t;
}

/*
  Structure calculation functions
*/

float lineLength(Line l) {
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;
    return sqrtf(dx * dx + dy * dy);
}

float triangleArea(Triangle t) {
    float x1 = t.p[0].x, y1 = t.p[0].y;
    float x2 = t.p[1].x, y2 = t.p[1].y;
    float x3 = t.p[2].x, y3 = t.p[2].y;
    return fabsf(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f;
}

/*
  Structure comparison functions
*/

bool samePoint(Point p1, Point p2) {
    return lineLength(makeLine(p1, p2)) < 1.0e-6f;
}

bool pointInLine(Point p, Line l) {
    return samePoint(p, l.p[0]) || samePoint(p, l.p[1]);
}

bool pointInTriangle(Point p, Triangle t) {
    return samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2]);
}