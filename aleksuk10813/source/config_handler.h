#ifndef CONFIG_HANDLER_H
#define CONFIG_HANDLER_H

#include "shared.h"
#include "3rdparty/pugixml.hpp"

using namespace std;

class ConfigHandler
{
public:
    ConfigHandler(ConfigHandlerArgs args);
    void parseArgs(int argc, char **argv);
    void saveConfig(int signal);
private:
    void readConfigFile();
    void readGuidsFile();
    void readDirectionsFile();

    void writeGuidsFile();

    pugi::xml_node initializeFile(string filename, string rootItemName);

    string configFilePath;
    string guidsFilePath;
    string feedsListFilePath;

    SMTPSettings smtpSettings;

    map<string, set<string> >* guids;
};

#endif // CONFIG_HANDLER_H
