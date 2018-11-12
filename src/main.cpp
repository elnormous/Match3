#include "Match3.hpp"

std::unique_ptr<ouzel::Application> ouzel::main(const std::vector<std::string>&)
{
    return std::unique_ptr<Application>(new Match3());
}
