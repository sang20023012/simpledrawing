
#include "Shape2D.h"
using namespace Gdiplus;

namespace Drawing {

    static Gdiplus::Color toNative(const Drawing::Color& color) {
        return Gdiplus::Color(color.r_, color.g_, color.b_);
    }

    Object2D::Object2D() : borderWidth_(1)
    {
    }

    Object2D::~Object2D()
    {
    }

    void Object2D::SetBorderWidth(float width) {
        borderWidth_ = width;
    }

    void Object2D::SetBorderColor(const Color& color) {
        borderColor_ = color;
    }
    ////////////////////////////////
    Board::Board() {

    }
    Board::~Board() {
        for(auto it = shapes_.begin(); it != shapes_.end(); ++it) {
            delete (*it);
        }
    }

    void Board::Draw(Gdiplus::Graphics* g) {
        for(auto it = shapes_.begin(); it != shapes_.end(); ++it) {
            (*it)->Draw(g);
        }
    }

    void Board::AddObject2D(Object2D* obj) {
        shapes_.push_back(obj);
    }

    ////////////////////////////////
    Line2D::Line2D(const Point2D& start, const Point2D& end) : start_(start), end_(end) {
    }
    Line2D::~Line2D(){}

    void Line2D::Draw(Gdiplus::Graphics* g) {
        Pen pen(toNative(borderColor_),  borderWidth_);
        g->DrawLine(&pen, start_.x_, start_.y_, end_.x_, end_.y_);
    }

    ////////////////////////////////
    Rectangle::Rectangle(const Point2D& pos, float width, float height) : pos_(pos), width_(width), height_(height) {
    }
    Rectangle::~Rectangle() {}

    void Rectangle::Draw(Gdiplus::Graphics* g) {
        Pen pen(toNative(borderColor_), borderWidth_);
        g->DrawRectangle(&pen, pos_.x_, pos_.y_, width_, height_);
    }

    /////////////////////////////////
    Ellipse::Ellipse(const Point2D& center, float radiusX, float radiusY) : center_(center), radiusX_(radiusX), radiusY_(radiusY) {}

    Ellipse::~Ellipse(){}

    void Ellipse::Draw(Gdiplus::Graphics* g) {
        Pen pen(toNative(borderColor_), borderWidth_);
        g->DrawEllipse(&pen, center_.x_ - radiusX_, center_.y_ - radiusY_, 2 * radiusX_, 2 * radiusY_);
    }

    /////////////////////////////////

}

    