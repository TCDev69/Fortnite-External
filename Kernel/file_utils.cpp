#include "file_utils.hpp"


bool file_utils::create_file_from_buffer(const std::string_view file_path, const void* buffer, size_t size) {
    try {
        std::ofstream stream(file_path.data(), std::ios::binary | std::ios::trunc);
        if (!stream.is_open()) {
            log::error("Failed to open file {} for writing.", file_path);
            return false;
        }
        stream.exceptions(std::ios::failbit | std::ios::badbit);

        stream.write(reinterpret_cast<const char*>(buffer), size);
        stream.close();
        if (stream.fail()) {
            log::error("Failed to write data to file {}.", file_path);
            return false;
        }
    } catch (const std::ofstream::failure& e) {
        log::error("Failed to write data to file {}: {}", file_path, e.what());
        return false;
    }
    return true;
}
