#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H

#include <charconv>


#include "base_filter.h"
#include "command_line_parser.h"
#include "command_line_parser.h"
#include "filter_pipeline_maker.h"
#include "bitmap.h"

class Application {
public:
    Application(int argc, char** argv) {
        argc_ = argc;
        argv_ = argv;
    }
    void run();
protected:
    int argc_ = 0;
    char** argv_;
};

namespace FilterMakers {
    BaseFilter* MakeCropFilter(const FilterDescriptor& fd);
    BaseFilter* MakeGsFilter(const FilterDescriptor& fd);
    BaseFilter* MakeNegFilter(const FilterDescriptor& fd);
    BaseFilter* MakeSharpFilter(const FilterDescriptor& fd);
    BaseFilter *MakeEdgeFilter(const FilterDescriptor &);
}

#endif //PROJECT_APPLICATION_H
