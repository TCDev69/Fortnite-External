#include "file_utils.hpp"


bool file_utils::create_file_from_buffer(const std::string_view file_path, const void* buffer, size_t size) {
    std::ofstream stream(file_path.data(), std::ios::binary);
    if (!stream) {
        std::cerr << "Error: Failed to open file '" << file_path.data() << "' for writing." << std::endl;
        return false;
    }
    stream.write(reinterpret_cast<const char*>(buffer), size);
    if (!stream) {
        std::cerr << "Error: Failed to write data to file '" << file_path.data() << "'." << std::endl;
        return false;
    }
    stream.close();
    return true;
}
