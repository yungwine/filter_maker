#include "filter_pipeline_maker.h"


BaseFilter* FilterPipelineMaker::MakeFilter(const FilterDescriptor& fd) {

    FilterMakerPtr maker = GetFilterMaker(fd.GetName());

    if (!maker) {
        return nullptr;
    }


    return maker(fd);
}

FilterPipelineMaker::FilterMakerPtr FilterPipelineMaker::GetFilterMaker(std::string_view name) const {
    auto ix = filter_creators_.find(name);
    if (ix == filter_creators_.end()) {
        return nullptr;
    }

    return ix->second;
}

