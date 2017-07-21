/* Find where the two rectangles intersect. Create a new rectangle showing 
    where they overlap.
*/


#include <iostream>
using namespace std;

struct PosAndLength{
    int position;
    int length;
};


class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};

PosAndLength closerRect(int a_pos, int a_length, int b_pos, int b_length){
    PosAndLength result;
    
    
    //position that starts later is our starting position
    if(a_pos > b_pos){
        result.position = a_pos;
    }
    else{
        result.position = b_pos;
    }
    
    //is there an overlap?
    if(b_pos > a_pos+a_length){
        return PosAndLength{0,0};
    }
    
    //ending position is based on which one ends first
    if(a_pos+a_length < b_pos+b_length){
        result.length = a_pos + a_length - result.position;
    }
    else{
        result.length = b_pos + b_length - result.position;
    }
    
    cout << result.position << " " << result.length << endl;
    return result;
    
}


Rectangle* find_intersection(Rectangle a, Rectangle b){
    PosAndLength x_plane, y_plane;
    
    x_plane = closerRect(a.getLeftX(), a.getWidth(), b.getLeftX(), b.getWidth());
    y_plane = closerRect(a.getBottomY(), a.getHeight(), b.getBottomY(), b.getHeight());
    
    if(x_plane.length == 0 || y_plane.length == 0)
        return NULL;
    
    Rectangle *result = new Rectangle(x_plane.position, y_plane.position, x_plane.length, y_plane.length);

    return result;
}


int main() {
    
    Rectangle a(2, 1, 6, 6);
//     Rectangle b(8, 1, 6, 6);    //does not overlap    
    Rectangle b(4, 3, 7, 9);
//     Rectangle b(10, 10, 10, 10);    //does not overlap
    
    Rectangle *c = find_intersection(a, b);
    
    if(c != NULL)
        cout << c->getLeftX() << " " << c->getBottomY() << " " << c->getWidth() << " " << c->getHeight() << endl;
    else
        cout << "Rectangles do not overlap." << endl;

    return 0;
}
