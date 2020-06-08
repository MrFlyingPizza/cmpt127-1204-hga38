// inrect.c
// checks if a given point is in a rectangle on the xy plane

int InRectangle(float pt[2], float rect[4]) {
  float xS, xL, yS, yL;
  // orders rectangle bounds to left small right large
  for (unsigned short bound_i = 0; bound_i < 2; bound_i++) {

    if (rect[0] < rect[2]) { //x
      xS = rect[0];
      xL = rect[2];
    } else {
      xS = rect[2];
      xL = rect[0];
    }

    if (rect[1] < rect[3]) { //y
      yS = rect[1];
      yL = rect[3];
    } else {
      yS = rect[3];
      yL = rect[1];
    }

  }

  int inBoundary = 0;
  if (pt[0] >= xS && pt[0] <= xL) {

    if (pt[1] >= yS && pt[1] <= yL) {
      inBoundary = 1;
    }

  }
  return inBoundary;
}
