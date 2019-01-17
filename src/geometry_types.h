
namespace geometry_types
{
struct Point2D
{
    Point2D(const double &x, const double &y) : x(x), y(y) {}
    Point2D() {}
    double x;
    double y;
};
struct Pose2D : public Point2D
{
    Pose2D(const double &x, const double &y, const double &theta) : theta(theta), Point2D(x, y) {}
    Pose2D() {}
    double theta;
};
struct Vector2D : public Point2D
{
    Vector2D(const double &x, const double &y) : Point2D(x, y) {}
    double dot(const Vector2D &other)
    {
        return this->x * other.x + this->y + other.y;
    }
    double cross(const Vector2D &other)
    {
        return this->x * other.y - this->y * other.x;
    }
};
} // namespace geometry_types