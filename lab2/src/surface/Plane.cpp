#include "../../include/surface/Plane.h"

namespace explorer {

  size_t
  Plane::
  distance(const Point& p1, const Point& p2) const

  {
    size_t distY = p1.y > p2.y ? p1.y - p2.y : p2.y - p1.y;
    size_t distX = p1.x > p2.x ? p1.x - p2.x : p2.x - p1.x;

    return distX + distY;
  }


  vector<Point>
  Plane::
  lookup(Point point) const
  {
    vector<Point> neighborhood;

    if (!this->isPointWithinBounds(point)) {
      return neighborhood;
    }

    if (point.x < this->getWidth() - 1)
      neighborhood.push_back(Point(point.x + 1, point.y));

    if (point.x > 0)
      neighborhood.push_back(Point(point.x - 1, point.y));

    if (point.y < this->getHeight() - 1)
      neighborhood.push_back(Point(point.x, point.y+1));

    if (point.y > 0)
      neighborhood.push_back(Point(point.x, point.y-1));

    return neighborhood;
  }

}