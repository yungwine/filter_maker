#include "base_filter.h"

void CropFilter::Apply(Bitmap& bmp) {
    std::cout << "crop filter apply implementation\n";
    Bitmap::PixelStorage& image = bmp.GetStorage();
    if (width_ == std::numeric_limits<int>::max()) {
        width_ = image.GetWidth();
    }
    if (height_ == std::numeric_limits<int>::max()) {
        height_ = image.GetHeight();
    }
    if (width_ > image.GetWidth()) {
        width_ = image.GetWidth();
    }
    if (height_ > image.GetHeight()) {
        height_ = image.GetHeight();
    }
    Bitmap::PixelStorage new_image(width_, height_);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            new_image.SetPixel(x, height_ - y - 1, image.GetPixel(x, image.GetHeight() - y - 1));
        }
    }
    bmp.SetStorage(new_image);
}

void GsFilter::Apply(Bitmap &bmp) {
    std::cout << "grayscale filter apply implementation\n";
    Bitmap::PixelStorage& image = bmp.GetStorage();
    for (size_t i = 0; i < image.GetWidth() * image.GetHeight(); ++i) {
        Bitmap::Color color;
        int color_value =  (int) (image.GetPixel(i).blue * 0.114 + image.GetPixel(i).green * 0.587 +  image.GetPixel(i).red * 0.299);
        color.blue = color_value;
        color.red = color_value;
        color.green = color_value;
        image.SetPixel(i, color);
    }
}

void NegFilter::Apply(Bitmap &bmp) {
    std::cout << "negative filter apply implementation\n";
    Bitmap::PixelStorage& image = bmp.GetStorage();
    for (size_t i = 0; i < image.GetWidth() * image.GetHeight(); ++i) {
        Bitmap::Color color;
        color.blue = 255 - image.GetPixel(i).blue;
        color.red = 255 - image.GetPixel(i).red;
        color.green = 255 - image.GetPixel(i).green;
        image.SetPixel(i, color);
    }
}

void SharpFilter::Apply(Bitmap &bmp) {
    std::cout << "sharp filter apply implementation\n";
    Bitmap::PixelStorage& image = bmp.GetStorage();
    Bitmap::PixelStorage new_image(image.GetWidth(), image.GetHeight());
    for (int y = 0; y < image.GetHeight(); ++y) {
        for (int x = 0; x < image.GetWidth(); ++x) {
            //Bitmap::Color color = image.GetPixel(x, y);
            Bitmap::Color new_color;
            new_color.blue = BlueValue(image, x, y, -1, -1, -1, -1, 5);
            new_color.green = GreenValue(image, x, y, -1, -1, -1, -1, 5);
            new_color.red = RedValue(image, x, y, -1, -1, -1, -1, 5);
            new_image.SetPixel(x, y, new_color);
        }
    }
    bmp.SetStorage(new_image);
}

void EdgeFilter::Apply(Bitmap &bmp) {
    if (treshold_ == std::numeric_limits<int>::max()) {
        throw std::invalid_argument("empty parametr for -edge");
        return;
    }
    std::cout << "edge filter apply implementation\n";
    GsFilter::Apply(bmp);
    Bitmap::PixelStorage& image = bmp.GetStorage();
    Bitmap::PixelStorage new_image(image.GetWidth(), image.GetHeight());
    for (int y = 0; y < image.GetHeight(); ++y) {
        for (int x = 0; x < image.GetWidth(); ++x) {
            Bitmap::Color new_color;
            new_color.blue = BlueValue(image, x, y, -1, -1, -1, -1, 4);
            if (new_color.blue > treshold_) {
                new_color.blue = 255;
                new_color.green = 255;
                new_color.red = 255;
            } else {
                new_color.blue = 0;
                new_color.green = 0;
                new_color.red = 0;
            }
            new_image.SetPixel(x, y, new_color);
        }
    }
    bmp.SetStorage(new_image);
}


size_t BaseFilter::BlueValue(Bitmap::PixelStorage &image, const int &x, const int &y, const int &a, const int &b, const int &c,
                      const int &d, const int &e) {
    return std::min(255, std::max(0, e * image.GetPixel(x, y).blue +
                                     d * image.GetPixel(std::clamp(static_cast<int>(x - 1), 0, static_cast<int>(image.GetWidth() - 1)), y).blue +
                                     b * image.GetPixel(std::clamp(static_cast<int>(x + 1), 0, static_cast<int>(image.GetWidth() - 1)), y).blue +
                                     a * image.GetPixel(x, std::clamp(static_cast<int>(y - 1), 0, static_cast<int>(image.GetHeight() - 1))).blue +
                                     c * image.GetPixel(x, std::clamp(static_cast<int>(y + 1), 0, static_cast<int>(image.GetHeight() - 1))).blue));
}

size_t BaseFilter::GreenValue(Bitmap::PixelStorage &image, const int &x, const int &y, const int &a, const int &b, const int &c,
                             const int &d, const int &e) {
    return std::min(255, std::max(0, e * image.GetPixel(x, y).green +
                                     d * image.GetPixel(std::clamp(static_cast<int>(x - 1), 0, static_cast<int>(image.GetWidth() - 1)), y).green +
                                     b * image.GetPixel(std::clamp(static_cast<int>(x + 1), 0, static_cast<int>(image.GetWidth() - 1)), y).green +
                                     a * image.GetPixel(x, std::clamp(static_cast<int>(y - 1), 0, static_cast<int>(image.GetHeight() - 1))).green +
                                     c * image.GetPixel(x, std::clamp(static_cast<int>(y + 1), 0, static_cast<int>(image.GetHeight() - 1))).green));
}

size_t BaseFilter::RedValue(Bitmap::PixelStorage &image, const int &x, const int &y, const int &a, const int &b, const int &c,
                     const int &d, const int &e) {
    return std::min(255, std::max(0, e * image.GetPixel(x, y).red +
                                     d * image.GetPixel(std::clamp(static_cast<int>(x - 1), 0, static_cast<int>(image.GetWidth() - 1)), y).red +
                                     b * image.GetPixel(std::clamp(static_cast<int>(x + 1), 0, static_cast<int>(image.GetWidth() - 1)), y).red +
                                     a * image.GetPixel(x, std::clamp(static_cast<int>(y - 1), 0, static_cast<int>(image.GetHeight() - 1))).red +
                                     c * image.GetPixel(x, std::clamp(static_cast<int>(y + 1), 0, static_cast<int>(image.GetHeight() - 1))).red));
}
