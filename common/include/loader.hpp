#pragma once

#include <string>
#include <vector>

#include "instruction.hpp"

namespace common{

class Loader {
public:
    Loader() = default;
    virtual ~Loader() = default;
    virtual std::vector<Instruction*> load(const std::string& source) = 0;
};
}