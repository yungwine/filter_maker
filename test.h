#ifndef PROJECT_TEST_H
#define PROJECT_TEST_H

#include "application.h"
#include <cassert>

class Test {
public:
    // тест подразумевает передачу трёх аргументов: второй и третий это input.bmp и output.bmp соответственно
    static void Parser(int argc, char* argv[]) {
        CommandLineParser parser;
        assert(parser.Parse(argc, argv));
        assert(parser.GetInput() == "input.bmp");
        assert(parser.GetOutput() == "output.bmp");
    }

    static void TestFilterCreation() {
        FilterPipelineMaker fpm;
        fpm.AddFilterCreator("-crop", &FilterMakers::MakeCropFilter);

        FilterDescriptor fd1;
        fd1.SetFilter({"-crop", "800",  "600"});

        FilterDescriptor fd2;
        fd2.SetFilter({"-noname", "800",  "600"});

        BaseFilter* filter1 = fpm.MakeFilter(fd1);
        BaseFilter* filter2 = fpm.MakeFilter(fd2);

        assert(filter1 != nullptr);
        assert(filter2 == nullptr);

        delete filter1;
        delete filter2;
    }

    static void TestColor() {
        Bitmap::Color color {50, 10, 30};
        Bitmap::PixelStorage ps(100, 100);
        assert(ps.GetPixel(50, 50) == Bitmap::Color({0, 0 ,0}));
        ps.SetPixel(50, 50, color);
        assert(ps.GetPixel(50, 50) == color);
    }

    static void TestLoadFile() {
        const char* TEST_FILE_NAME1 = "C:/example.bmp";
        const char* TEST_FILE_NAME2 = "C:/exampleeeeeee.bmp";
        Bitmap bmp;
        assert(bmp.load(TEST_FILE_NAME1));
        assert(!bmp.load(TEST_FILE_NAME2));
    }

    static void TestLoadWrongFile() {
        const char* TEST_FILE_NAME = "C:/example.png";
        Bitmap bmp;
        assert(!bmp.load(TEST_FILE_NAME));
    }

};


#endif //PROJECT_TEST_H
