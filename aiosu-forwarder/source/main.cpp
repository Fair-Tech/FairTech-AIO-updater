#include <filesystem>
#include <string>

#include <switch.h>

#define PATH        "/switch/FairTech-AIO-Updater/"
#define FULL_PATH   "/switch/FairTech-AIO-Updater/FairTech-AIO-Updater.nro"
#define CONFIG_PATH "/config/FairTech-AIO-Updater/switch/FairTech-AIO-Updater/FairTech-AIO-Updater.nro"
#define PREFIX      "/switch/FairTech-AIO-Updater/FairTech-AIO-Updater-v"
#define FORWARDER_PATH      "/config/FairTech-AIO-Updater/aiosu-forwarder.nro"
#define CONFIG_SWITCH       "/config/FairTech-AIO-Updater/switch/"
#define HIDDEN_FILE "/config/FairTech-AIO-Updater/.FairTech-AIO-Updater"

int removeDir(const char* path)
{
    Result ret = 0;
    FsFileSystem *fs = fsdevGetDeviceFileSystem("sdmc");
    if (R_FAILED(ret = fsFsDeleteDirectoryRecursively(fs, path))) {
        return ret;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    std::filesystem::create_directory(PATH);
    for (const auto & entry : std::filesystem::directory_iterator(PATH)){
        if(entry.path().string().find(PREFIX) != std::string::npos) {
            std::filesystem::remove(entry.path().string());
            std::filesystem::remove(entry.path().string() + ".star");
        }
    }
    std::filesystem::remove(HIDDEN_FILE);

    if(std::filesystem::exists(CONFIG_PATH)){
        std::filesystem::create_directory(PATH);
        std::filesystem::remove(FULL_PATH);
        std::filesystem::rename(CONFIG_PATH, FULL_PATH);
        removeDir(CONFIG_SWITCH);
    }

    std::filesystem::remove(FORWARDER_PATH);

    envSetNextLoad(FULL_PATH, ("\"" + std::string(FULL_PATH) + "\"").c_str());
    return 0;
}
