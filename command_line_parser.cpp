#include "command_line_parser.h"

bool CommandLineParser::Parse(int argc, char* argv[]) {
    if (argc < MIN_ARG_NUM) {
        return false;
    }
    input_file_name_ = argv[1];
    output_file_name_ = argv[2];

    size_t i = 3;
    std::vector<std::string_view> params;
    while (i < argc) {
        if (argv[i][0] == '-') {
            if (std::find(basic_names_.begin(), basic_names_.end(), argv[i]) != basic_names_.end()) {

                params.push_back(argv[i]);
                ++i;
            } else {
                std::cout << "wrong filter name\n";
                ++i;
                continue;
            }
            while (i < argc && argv[i][0] != '-') {
                params.push_back(argv[i]);
                ++i;
            }
            FilterDescriptor fd;
            fd.SetFilter(params);
            filters_.push_back(fd);
            params.clear();
        } else {
            ++i;
        }
    }

    return true;
}
