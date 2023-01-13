#include "file_utils.hpp"


bool file_utils::create_file_from_buffer(const std::string_view file_path, const void* buffer, size_t size) {
    std::ofstream stream(file_path.data(), std::ios::binary | std::ios::trunc); 
    if (!stream) {
        std::cerr << "Error: Failed to open file '" << file_path.data() << "' for writing." << std::endl;
        return false;
    }
    stream.exceptions(std::ios::failbit | std::ios::badbit);
    try {
        stream.write(reinterpret_cast<const char*>(buffer), size);
    } catch (const std::ofstream::failure& e) {
        std::cerr << "Error: Failed to write data to file '" << file_path.data() << "': " << e.what() << std::endl;
        return false;
    }
    stream.close();
    return true;
}
