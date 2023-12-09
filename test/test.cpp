#include <iostream>
#include <vector>

class point_2d
{
protected:
    int x;
    int y;
public:
    point_2d(const int& x, const int&y)
    {
        setX(x);
        setY(y);
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    void setX(const int& x)
    {
        this->x = x;
    }
    void setY(const int& y)
    {
        this->y = y;
    }
};

class point_3d: public point_2d
{
    int z;
public:
    point_3d(const int & x, const int& y, const int&z):
        point_2d(x,y)
    {
        setZ(z);
    }
    int getZ()
    {
        return this->z;
    }
    void setZ(const int& z)
    {
        this->z = z;
    }
};

int main()
{
    std::vector<point_2d*> vec;
    point_2d point_1(2,3);
    point_3d point_2(2,8,1);
    
    vec.push_back(&point_1);
    vec.push_back(&point_2);

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i]->getY() << std::endl;
    }
}

