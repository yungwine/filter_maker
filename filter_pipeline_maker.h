#ifndef PROJECT_FILTER_PIPELINE_MAKER_H
#define PROJECT_FILTER_PIPELINE_MAKER_H

#include <stdexcept>
#include <limits>
#include <map>
#include <string_view>

#include "command_line_parser.h"
#include "base_filter.h"


class FilterPipelineMaker {
public:
    typedef BaseFilter*(*FilterMakerPtr)(const FilterDescriptor&);
    typedef std::map<std::string_view, FilterMakerPtr> FilterCreators;
public:
    void AddFilterCreator(std::string_view filter_name, FilterMakerPtr filter_maker) {
        filter_creators_.insert({filter_name, filter_maker});
    }

    BaseFilter* MakeFilter(const FilterDescriptor& fd);

    FilterMakerPtr GetFilterMaker(std::string_view name) const;

protected:
    FilterCreators filter_creators_;
};


#endif //PROJECT_FILTER_PIPELINE_MAKER_H
