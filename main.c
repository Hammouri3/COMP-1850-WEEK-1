#include <stdio.h>
#include <stdbool.h>

#include "shapes.h"

int main(void) {
    // Use a 3-4-5 right triangle so the expected values are clean
    Point p1 = makePoint(0.0, 0.0);
    Point p2 = makePoint(3.0, 0.0);
    Point p3 = makePoint(0.0, 4.0);
    Point p4 = makePoint(3.0, 4.0);

    printf("p1 = (%.2f, %.2f)\n", p1.x, p1.y);
    printf("p2 = (%.2f, %.2f)\n", p2.x, p2.y);
    printf("p3 = (%.2f, %.2f)\n\n", p3.x, p3.y);

    Line l1 = makeLine(p1, p2);
    Line l2 = makeLine(p1, p3);
    Line l3 = makeLine(p1, p4);

    printf("lineLength(l1) = %.4f  (expected 3.0)\n", lineLength(l1));
    printf("lineLength(l2) = %.4f  (expected 4.0)\n", lineLength(l2));
    printf("lineLength(l3) = %.4f  (expected 5.0)\n\n", lineLength(l3));

    Triangle t1 = makeTriangle(p1, p2, p3);
    printf("triangleArea(t1) = %.4f  (expected 6.0)\n\n", triangleArea(t1));

    Point p1_copy = makePoint(0.0, 0.0);
    printf("samePoint(p1, p1_copy) = %s  (expected true)\n",
           samePoint(p1, p1_copy) ? "true" : "false");
    printf("samePoint(p1, p2)      = %s  (expected false)\n\n",
           samePoint(p1, p2) ? "true" : "false");

    printf("pointInLine(p1, l1) = %s  (expected true)\n",
           pointInLine(p1, l1) ? "true" : "false");
    printf("pointInLine(p3, l1) = %s  (expected false)\n\n",
           pointInLine(p3, l1) ? "true" : "false");

    printf("pointInTriangle(p1, t1) = %s  (expected true)\n",
           pointInTriangle(p1, t1) ? "true" : "false");
    printf("pointInTriangle(p4, t1) = %s  (expected false)\n",
           pointInTriangle(p4, t1) ? "true" : "false");

    return 0;
}