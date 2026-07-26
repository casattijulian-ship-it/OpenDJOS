#pragma once

#include <string_view>

#include "Core/Services/IService.hpp"

namespace OpenDJ
{

class Logger final : public IService
{
public:
    Logger() = default;
    ~Logger() override = default;

    bool initialize() override;
    void shutdown() override;

    void info(std::string_view message);
    void warning(std::string_view message);
    void error(std::string_view message);
    void debug(std::string_view message);
};

} // namespace OpenDJ