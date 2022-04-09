#ifndef PROJECT_BASEFILTER_H
#define PROJECT_BASEFILTER_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#include "bitmap.h"


class BaseFilter {
public:
    virtual void Apply(Bitmap& bmp) = 0;
    size_t BlueValue(Bitmap::PixelStorage& image, const int& x, const int& y, const int& a,
                     const int& b, const int& c, const int& d, const int& e);
    size_t GreenValue(Bitmap::PixelStorage& image, const int& x, const int& y, const int& a,
                    const int& b, const int& c, const int& d, const int& e);
    size_t RedValue(Bitmap::PixelStorage& image, const int& x, const int& y, const int& a,
                     const int& b, const int& c, const int& d, const int& e);
    virtual ~BaseFilter() = default;
};

class CropFilter : public BaseFilter {
public:
    CropFilter(size_t& width, size_t& height) {
        width_ = width;
        height_ = height;
    }
    void Apply(Bitmap& bmp) override;
protected:
    size_t width_;
    size_t height_;
};

class GsFilter : public BaseFilter {
protected:
    void Apply(Bitmap& bmp) override;
};

class NegFilter : public BaseFilter {
    void Apply(Bitmap& bmp) override;
};

class SharpFilter : public BaseFilter {
    void Apply(Bitmap& bmp) override;
};

class EdgeFilter : public GsFilter {
public:
    explicit EdgeFilter(size_t& treshold) {
        treshold_ = treshold;
    }
    void Apply(Bitmap& bmp) override;
protected:
    size_t treshold_;
};


#endif //PROJECT_BASEFILTER_H
