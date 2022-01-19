#include <iostream>
#include <experimental/filesystem>
#include <fstream>



namespace fs = std::experimental::filesystem;
class logger{
    fs::path logpath;
    std::ofstream logfile;
public:
    logger() {
        auto name = uuids::to_string(uuids::uuid_random_generator{}());
        logpath = fs::temp_directory_path() / (name + ".tmp");
        logfile.open(logpath.c_str(), std::ios::out|std::ios::trunc);
    }
    ~logger() noexcept {
        try { if(logfile.is_open()) logfile.close();
              if (!logpath.empty()) fs::remove(logpath);
    }
    catch (...) {}

    }
void persist(fs::path const & path) {
    logfile.close();
    fs::rename(logpath, path);
    logpath.clear();
}

logger& operator<<(std::string_view message) {
    logfile << message.data() << '\n';
    return *this;\
    }
};
