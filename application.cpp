#include "application.h"



namespace FilterMakers {

    BaseFilter* MakeCropFilter(const FilterDescriptor& fd) {
        if (fd.GetName() != "-crop") {
            throw std::invalid_argument("invalid filter descriptor passed to MakeCropFilter");
        }

        size_t width, height;
        if (fd.GetParams().empty()) {
            width = std::numeric_limits<size_t>::max();
            height = std::numeric_limits<size_t>::max();
        } else {
            std::from_chars(fd.GetParams()[0].data(), fd.GetParams()[0].data() + fd.GetParams()[0].size(), width);
            std::from_chars(fd.GetParams()[1].data(), fd.GetParams()[1].data() + fd.GetParams()[1].size(), height);
        }
        return new CropFilter(width, height);
    }

    BaseFilter* MakeGsFilter(const FilterDescriptor &fd) {
        if (fd.GetName() != "-gs") {
            throw std::invalid_argument("invalid filter descriptor passed to MakeGsFilter");
        }
        return new GsFilter();
    }

    BaseFilter* MakeNegFilter(const FilterDescriptor &fd) {
        if (fd.GetName() != "-neg") {
            throw std::invalid_argument("invalid filter descriptor passed to MakeNegFilter");
        }
        return new NegFilter();
    }

    BaseFilter* MakeSharpFilter(const FilterDescriptor &fd) {
        if (fd.GetName() != "-sharp") {
            throw std::invalid_argument("invalid filter descriptor passed to MakeSharpFilter");
        }
        return new SharpFilter();
    }

    BaseFilter* MakeEdgeFilter(const FilterDescriptor &fd) {
        if (fd.GetName() != "-edge") {
            throw std::invalid_argument("invalid filter descriptor passed to MakeEdgeFilter");
        }
        size_t treshold;
        if (fd.GetParams().empty()) {
            treshold = std::numeric_limits<size_t>::max();
        } else {
            std::from_chars(fd.GetParams()[0].data(), fd.GetParams()[0].data() + fd.GetParams()[0].size(), treshold);
        }
        return new EdgeFilter(treshold);
    }

}

void Application::run() {

    CommandLineParser parser;
    Bitmap bmp;
    FilterPipelineMaker fpm;

    parser.Parse(argc_, argv_);

    fpm.AddFilterCreator("-crop", &FilterMakers::MakeCropFilter);
    fpm.AddFilterCreator("-gs", &FilterMakers::MakeGsFilter);
    fpm.AddFilterCreator("-neg", &FilterMakers::MakeNegFilter);
    fpm.AddFilterCreator("-sharp", &FilterMakers::MakeSharpFilter);
    fpm.AddFilterCreator("-edge", &FilterMakers::MakeEdgeFilter);

    if (!bmp.load(std::string(parser.GetInput()).c_str())) {
        return;
    }

    for (auto& f : parser.GetFilters()) {
        BaseFilter* filter = fpm.MakeFilter(f);
        filter->Apply(bmp);
        delete filter;
    }

    if (!bmp.save(parser.GetOutput())) {
        std::cout << "can't save file";
    }

}
