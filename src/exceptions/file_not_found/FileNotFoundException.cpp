#include "FileNotFoundException.h"
#include "spdlog/spdlog.h"

FileNotFoundException::FileNotFoundException(const std::string &filename)
    : std::runtime_error("File not found: " + filename), m_filename(filename)
{
    spdlog::error("'{}' file not found", filename);
}

const std::string &FileNotFoundException::getFilename() const
{
    return m_filename;
}