#ifndef PROJECT_BITMAP_H
#define PROJECT_BITMAP_H

#include <cstdint>
#include <iostream>
#include <string_view>
#include <tuple>


class Bitmap {

public:
    struct Color {
        uint8_t blue = 0;
        uint8_t green = 0;
        uint8_t red = 0;

       bool operator==(const Color& other) const {
           return std::tie(blue, green, red) == std::tie(other.blue, other.green, other.red);
       }
        bool operator!=(const Color& other) const {
           return !(*this == other);
       }
    };

    class PixelStorage {
        friend Bitmap;
    public:
        PixelStorage(): storage_(nullptr), width_(0), height_(0) {}
        PixelStorage(size_t width, size_t height, Color def = {0,0,0});
        ~PixelStorage();

        PixelStorage(const PixelStorage& other);
        PixelStorage& operator=(const PixelStorage& other);


        Color& GetPixel(size_t x, size_t y);
        Color& GetPixel(size_t i);
        const Color& GetPixel(size_t x, size_t y) const;

        void SetPixel(size_t i, Color& other);
        void SetPixel(size_t i, Color& other) const;
        void SetPixel(size_t x, size_t y, Color& other);

        Color& operator()(size_t x, size_t y) {
            return storage_[y * width_ + x];
        }
        const Color& operator()(size_t x, size_t y) const {
            return storage_[y * width_ + x];
        }
        size_t GetWidth() const {
            return width_;
        }
        size_t GetHeight() const {
            return height_;
        }
        void SetWidth(const size_t& width) {
            width_ = width;
        }
        void SetHeight(const size_t& height) {
            height_ = height;
        }


    protected:
        void Swap(PixelStorage& other) {
            //std::swap(*this, other); попытка обменять 2 объекта местами ведёт к бесконечной рекурсии, т.к.
            std::swap(width_, other.width_);
            std::swap(height_, other.height_);
            std::swap(storage_, other.storage_);
        }

    protected:
        Color* storage_;
        size_t width_;
        size_t height_;

    };

    struct BMPHeader {
        uint16_t signature;
        uint32_t bmp_size;
        uint16_t dummy_1;
        uint16_t dummy_2;
        uint32_t offset;
    } __attribute__((packed));

    struct DIBHeader {
        uint32_t header_size;
        int32_t width;
        int32_t height;
        uint16_t color_plane_num;
        uint16_t bpp;
        uint32_t compr_method;
        uint32_t img_size;
        int32_t hor_res;
        int32_t vert_res;
        uint32_t color_num;
        uint32_t imp_color_num;
    } __attribute__((packed));

    //возвращаем тру если переданный заголовок хороший, иначе фолс
    static bool CheckBMPHeader(const BMPHeader& header);

    bool load(std::istream& istr);

    bool load(const char* file_name);

    bool save(const std::string_view& file_name);

    bool save(std::ostream& ostr);

    PixelStorage& GetStorage() {
        return pixelstorage_;
    }
    void SetStorage(PixelStorage& other) {
        pixelstorage_ = other;
    }

protected:
    PixelStorage pixelstorage_;
    BMPHeader bmp_header_;
    DIBHeader dib_header_;
};



#endif //PROJECT_BITMAP_H
