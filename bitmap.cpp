#include <fstream>
#include <string>
#include <stdexcept>

#include "bitmap.h"

bool Bitmap::load(std::istream &istr) {
    BMPHeader bmp_header;
    istr.read(reinterpret_cast<char *>(&bmp_header), sizeof(bmp_header)); //TODO: проверить что поток не это
    bmp_header_ = bmp_header;
    if (!CheckBMPHeader(bmp_header)) {
        std::cout << "wrong file format";
        return false;
    }
    DIBHeader dib_header;
    istr.read(reinterpret_cast<char *>(&dib_header), sizeof(dib_header));
    dib_header_ = dib_header;

    pixelstorage_ = PixelStorage(dib_header.width, dib_header.height);


//    char* buffer = new char [dib_header.img_size];
//    istr.read(buffer, dib_header.img_size);
//    delete[] buffer;

    for (size_t i = 0; i < dib_header.img_size / 3; ++i) {
        Color color;
        istr.read(reinterpret_cast<char *>(&color), 3);
        pixelstorage_.SetPixel(i, color);
    }

    return true;

}

//bool Bitmap::load(std::string_view file_name) {
bool Bitmap::load(const char *file_name) {
    std::string str(file_name);
    std::fstream file;
    file.open(str, std::ios_base::in | std::ios_base::binary);
    if (!file.is_open()) {
        std::cout << "wrong file name";
        return false;
    }
    return load(file);
}

bool Bitmap::save(const std::string_view& file_name) {
    std::string str(file_name);
    std::fstream file;
    file.open(str, std::ios_base::out | std::ios_base::binary);
    if (!file.is_open()) {
        return false;
    }
    return save(file);
}

bool Bitmap::save(std::ostream& ostr) {
    dib_header_.img_size = pixelstorage_.GetWidth() * pixelstorage_.GetHeight() * 3;
    dib_header_.height = pixelstorage_.GetHeight();
    dib_header_.width = pixelstorage_.GetWidth();
    ostr.write(reinterpret_cast<char *>(&(*this).bmp_header_), sizeof(bmp_header_));
    ostr.write(reinterpret_cast<char *>(&(*this).dib_header_), sizeof(dib_header_));
    for (size_t i = 0; i < dib_header_.img_size / 3; ++i) {
        Color color = pixelstorage_.GetPixel(i);;
        ostr.write(reinterpret_cast<char *>(&color), 3);
    }
    return true;
}

bool Bitmap::CheckBMPHeader(const Bitmap::BMPHeader &header) {
    return (header.signature == 0x4D42); //TODO: уточнить на счет именованной константы
}

Bitmap::PixelStorage::PixelStorage(size_t width, size_t height, Bitmap::Color def)
        : storage_(nullptr), width_(width), height_(height) {
    if (width_ == 0 || height_ == 0) {
        width_ = 0;
        height_ = 0;
        return;
    }
    storage_ = new Color[height_ * width_];
    for (size_t i = 0; i < height_; ++i) {
        for (size_t j = 0; j < width_; ++j) {
            (*this)(j, i) = def;
        }

    }
}

Bitmap::PixelStorage::PixelStorage(const PixelStorage &other) : width_(other.width_), height_(other.height_) {
    if (!other.storage_) {
        storage_ = nullptr;
        return;
    }
    size_t new_size = width_ * height_;
    Color* new_st = new Color[new_size];
    storage_ = new_st;
    for (size_t i = 0; i < height_ * width_; ++i) {
        storage_[i] = other.storage_[i];
    }

}

Bitmap::Color &Bitmap::PixelStorage::GetPixel(size_t x, size_t y) {
    if (x >= width_) {
        throw std::out_of_range("x out of boundary");
    }
    if (y >= height_) {
        throw std::out_of_range("y out of boundary");
    }
//    return storage_[y * width_ + x];
    return (*this)(x, y);
}

const Bitmap::Color &Bitmap::PixelStorage::GetPixel(size_t x, size_t y) const {
    if (x >= width_) {
        throw std::out_of_range("x out of boundary");
    }
    if (y >= height_) {
        throw std::out_of_range("y out of boundary");
    }

    return (*this)(x, y);
}

Bitmap::Color &Bitmap::PixelStorage::GetPixel(size_t i) {
    return storage_[i];
}


void Bitmap::PixelStorage::SetPixel(size_t i, Color& other) {
    storage_[i] = other;
}
void Bitmap::PixelStorage::SetPixel(size_t i, Color& other) const {
    storage_[i] = other;
}

void Bitmap::PixelStorage::SetPixel(size_t x, size_t y, Bitmap::Color &other) {
    (*this)(x, y) = other;
}

Bitmap::PixelStorage::~PixelStorage() {
    delete[] storage_;
}

Bitmap::PixelStorage &Bitmap::PixelStorage::operator=(const Bitmap::PixelStorage &other) {
    if (this == &other) {
        return *this;
    }
    Bitmap::PixelStorage ps(other);
    Swap(ps);
    return *this;
}





