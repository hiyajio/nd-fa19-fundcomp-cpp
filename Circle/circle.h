/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: circle.h
 * Description: Class interface for Circle class for Part 1 of lab (Circle)
 */
#include <string>
using namespace std;

// Class interface (added defRadius to define default radius)
// Added newRadius to set later on and const
class Circle {
    public:
        Circle();
        Circle(float defRadius);
        ~Circle();
        float getRadius() const;
        void setRadius(float newRadius);
        float circumference() const;
        float area() const;
        void info() const;
    private:
        float radius;
};
