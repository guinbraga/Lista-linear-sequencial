#include <stdio.h>
#include <stdbool.h>

// Function to find the orientation of the ordered triplet (p, q, r)
// Returns:
// 0 -> p, q, and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(int px, int py, int qx, int qy, int rx, int ry) {
    int val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if point q lies on the segment pr
bool onSegment(int px, int py, int qx, int qy, int rx, int ry) {
    return (qx <= (px > rx ? px : rx) && qx >= (px < rx ? px : rx) &&
            qy <= (py > ry ? py : ry) && qy >= (py < ry ? py : ry));
}

// Function to check if two line segments (p1q1) and (p2q2) intersect
bool doIntersect(int p1x, int p1y, int q1x, int q1y,
                 int p2x, int p2y, int q2x, int q2y) {
    // Find the four orientations
    int o1 = orientation(p1x, p1y, q1x, q1y, p2x, p2y);
    int o2 = orientation(p1x, p1y, q1x, q1y, q2x, q2y);
    int o3 = orientation(p2x, p2y, q2x, q2y, p1x, p1y);
    int o4 = orientation(p2x, p2y, q2x, q2y, q1x, q1y);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special cases
    // p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1x, p1y, p2x, p2y, q1x, q1y)) return true;

    // q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1x, p1y, q2x, q2y, q1x, q1y)) return true;

    // p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2x, p2y, p1x, p1y, q2x, q2y)) return true;

    // q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2x, p2y, q1x, q1y, q2x, q2y)) return true;

    return false; // No intersection
}

int main() {
    // Example usage
    // Line segments represented as {x1, y1, x2, y2}
    int lineSegments[2][4] = {
        {1, 1, 10, 1}, // Segment 1: (1,1) to (10,1)
        {1, 2, 10, 0}  // Segment 2: (1,2) to (10,0)
    };

    if (doIntersect(lineSegments[0][0], lineSegments[0][1],
                    lineSegments[0][2], lineSegments[0][3],
                    lineSegments[1][0], lineSegments[1][1],
                    lineSegments[1][2], lineSegments[1][3])) {
        printf("The line segments intersect.\\n");
    } else {
        printf("The line segments do not intersect.\\n");
    }

    return 0;
}
