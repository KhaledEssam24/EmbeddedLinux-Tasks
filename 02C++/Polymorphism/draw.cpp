// 2- Interface and Multiple Inheritance:
//  -Create an interface class Drawable with a pure virtual function draw().
//  -Derive classes like Circle, Rectangle, and Triangle from Shape and implement the Drawable 
// interface.
// -Create objects of these derived classes and call the draw() function through a pointer to the 
// Drawable interface
#include <iostream>
#include <cmath>

class Drawable
{
private:
    /* data */
public:
    virtual void draw()=0;
    virtual ~Drawable(){}
};

class Rectangle : public Drawable
{
private:
    int height,width;
public:
    Rectangle(int height,int width):height(height),width(width){}
    ~Rectangle(){}
    void draw(){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cout << '*';
            }
        std::cout << std::endl;
    }
    }
};

class Circle : public Drawable
{
private:
    int radius;
public:
    Circle(int radius):radius(radius){}
    ~Circle(){}
    void draw(){
        double aspect_ratio = 2.5; // Adjust for non-square characters
        for (int y = radius; y >= -radius; --y) {
            for (int x = -radius * aspect_ratio; x <= radius * aspect_ratio; ++x) {
                double distance = (x / aspect_ratio) * (x / aspect_ratio) + y * y;
                if (distance <= radius * radius)
                    std::cout << '*';
                else
                    std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
};

class Triangle : public Drawable
{
private:
    int height;
public:
    Triangle(int height):height(height){}
    ~Triangle(){}
    void draw(){
        int width = 2 * height - 1;  // The width of the triangle's base

        for (int i = 0; i < height; ++i) {
            // Calculate the number of stars to print
            int numStars = 2 * i + 1;
            int numSpaces = (width - numStars) / 2;

            // Print leading spaces
            for (int j = 0; j < numSpaces; ++j) {
                std::cout << ' ';
            }

            // Print stars
            for (int j = 0; j < numStars; ++j) {
                std::cout << '*';
            }

            // Print trailing spaces (optional, just for symmetry)
            for (int j = 0; j < numSpaces; ++j) {
                std::cout << ' ';
            }

            std::cout << std::endl;
        }
    }
};

int main(){
    Drawable* shape;
    
    shape = new Circle(5);
    shape->draw();
    delete shape;
    std::cout<<"\n\n";

    shape = new Triangle(5);
    shape->draw();
    delete shape;
    std::cout<<"\n\n";

    shape = new Rectangle(9,6);
    shape->draw();
    delete shape;
    std::cout<<"\n\n";

    return 0;
}