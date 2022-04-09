#ifndef PROJECT_COMMAND_LINE_PARSER_H
#define PROJECT_COMMAND_LINE_PARSER_H
#include <iostream>
#include <string_view>
#include <cstddef>
#include <vector>
#include <tuple>


class FilterDescriptor {
public:
    FilterDescriptor() = default;
    FilterDescriptor(std::string_view& name, std::vector<std::string_view>& params) {
        filter_name_ = name;
        params_ = params;
    };
    std::pair<std::string_view, std::vector<std::string_view>> GetFilter() {
        return std::make_pair(filter_name_, params_);
    }
    void SetFilter(std::vector<std::string_view> filters) {
        filter_name_ = filters[0];
        for (size_t i = 1; i < filters.size(); ++i) {
            params_.push_back(filters[i]);
        }
    }
    std::string_view GetName() const {
        return filter_name_;
    }
    std::vector<std::string_view> GetParams() const {
        return params_;
    }
protected:
    std::string_view filter_name_;
    std::vector<std::string_view> params_;
};


class CommandLineParser {
public:
    static const size_t MIN_ARG_NUM = 3;  // минимальное кол-во аргументов для работы программы

public:

    bool Parse(int argc, char* argv[]);

    std::string_view GetInput() const {
        return input_file_name_;
    }
    std::string_view GetOutput() const {
        return output_file_name_;
    }

    std::vector<FilterDescriptor> GetFilters() {
        return filters_;
    }
protected:
    std::string_view input_file_name_;
    std::string_view output_file_name_;
    std::vector<FilterDescriptor> filters_;
    std::vector<std::string> basic_names_ = {"-crop", "-gs", "-edge", "-sharp", "-neg"};

};


#endif //PROJECT_COMMAND_LINE_PARSER_H
