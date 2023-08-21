#pragma once
#include <windows.h>
#include <gdiplus.h>
#include <list>

namespace Drawing {    
    struct Color {
        byte r_;
        byte g_;
        byte b_;

        Color() : r_(0), g_(0), b_(0) {}
        Color(byte r, byte g, byte b) : r_(r), g_(g), b_(b) {}
    };

    struct Point2D {
        float x_;
        float y_;
    };

    class Object2D
    {
    protected:
        float borderWidth_;
        Color borderColor_;
    public:
        Object2D();
        virtual ~Object2D();
        virtual void Draw(Gdiplus::Graphics* g) = 0;
        virtual void SetBorderWidth(float width);
        virtual void SetBorderColor(const Color& color);
    };

    class Board : public Object2D {
    protected:
        std::list<Object2D*> shapes_;

    public:
        Board();
        ~Board();
        void Draw(Gdiplus::Graphics* g) override;
        // object that added using this method will be destroyed when the board is destroyed
        void AddObject2D(Object2D* obj);
    };


    class Line2D : public Object2D {
        Point2D start_;
        Point2D end_;
    public:
        Line2D(const Point2D& start, const Point2D& end);
        ~Line2D();

        void Draw(Gdiplus::Graphics* g) override;
    };

    class Rectangle : public Object2D {
        Point2D pos_;
        float width_;
        float height_;
    public:
        Rectangle(const Point2D& pos, float width, float height);
        ~Rectangle();

        void Draw(Gdiplus::Graphics* g) override;
    };

    /////////////////////////////////////////
    class Ellipse : public Object2D {
        Point2D center_;
        float radiusX_;
        float radiusY_;
    public:
        Ellipse(const Point2D& center, float radiusX, float radiusY);
        ~Ellipse();

        void Draw(Gdiplus::Graphics* g) override;
    };

    /////////////////////////////////////////
}
