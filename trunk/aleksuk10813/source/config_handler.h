#ifndef CONFIG_HANDLER_H
#define CONFIG_HANDLER_H

#include "shared.h"
#include "3rdparty/pugixml.hpp"

using namespace std;

class ConfigHandler
{
public:
    ConfigHandler();
    ConfigHandler(ConfigHandlerArgs args);
    void parseArgs(int argc, char **argv);
    void saveConfig(int signal);
private:
    void readConfigFile();
    void readGuidsFile();
    void readDirectionsFile();

    // Запись конфига тока что не предусмотрена
    void writeGuidsFile();
    void writeDirectionsFile();

    pugi::xml_node initializeFile(string filename, string rootItemName);

    string configFilePath;
    string guidsFilePath;
    string DirectionsFilePath;

    SMTPSettings* smtpSettings;

    map<string, set<string> >* guids;
    list<Directions>* directions;

    friend class Tester;
};

#endif // CONFIG_HANDLER_H
