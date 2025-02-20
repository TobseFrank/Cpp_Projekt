#pragma once
#include <stdexcept>
#include <string>

class FileNotFoundException : public std::runtime_error
{
public:
    FileNotFoundException(const std::string &filename);

    const std::string &getFilename() const;

private:
    std::string m_filename;
};