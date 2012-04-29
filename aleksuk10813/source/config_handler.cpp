#include "config_handler.h"
#include <fstream>
#include <sstream>

ConfigHandler::ConfigHandler()
{
    // Для тестирования
}

ConfigHandler::ConfigHandler(ConfigHandlerArgs args)
{
    parseArgs(args.argc, args.argv);
    guids = args.guids;
    directions = args.directions;
    smtpSettings = args.smtpSettings;

    try
    {
        readConfigFile();
    }
    catch(...) {}

    try
    {
        readGuidsFile();
    }
    catch(...) {}

    try
    {
        readDirectionsFile();
    }
    catch(...) {}
}

void ConfigHandler::parseArgs(int argc, char **argv)
{
    configFilePath = "config.xml";
    guidsFilePath = "guids.xml";
    DirectionsFilePath = "directions.xml";
    // TODO
}

void ConfigHandler::saveConfig(int signal)
{
    try
    {
        writeGuidsFile();
    }
    catch(...) {}

    try
    {
        writeDirectionsFile();
    }
    catch(...) {}
}

void ConfigHandler::readConfigFile()
{
    pugi::xml_node root = initializeFile(configFilePath, "config");
    pugi::xml_node smtp = root.child("smtp");

    if (smtp == NULL)
        throw ConfigHandlerException(ERROR, "No smtp node");

    smtpSettings->username = smtp.child_value("username");
    smtpSettings->password = smtp.child_value("password");
    smtpSettings->server = smtp.child_value("server");
}

void ConfigHandler::readGuidsFile()
{
    pugi::xml_node root = initializeFile(guidsFilePath, "guids");

    for (pugi::xml_node sourceItem = root.child("source"); sourceItem; sourceItem = sourceItem.next_sibling("source") )
    {
        pair<string, set<string> > tempPair;
        tempPair.first = sourceItem.attribute("address").value();

        for (pugi::xml_node guidItem = sourceItem.child("guid"); guidItem; guidItem = guidItem.next_sibling("guid") )
            tempPair.second.insert(guidItem.attribute("value").value() );
        guids->insert(tempPair);
    }
}

void ConfigHandler::readDirectionsFile()
{
    ifstream file(DirectionsFilePath);
    stringstream buffer;
    // Перекидываем содержимое ifstream в stringstream
    buffer << file.rdbuf();
    delete directions;
    directions = importDirectionsFromXML(buffer.str() );
}

void ConfigHandler::writeGuidsFile()
{
    ofstream file(guidsFilePath);

    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("guids");

    for (map<string, set<string> >::iterator sourceIt = guids->begin(); sourceIt != guids->end(); sourceIt++)
    {
        pugi::xml_node source = root.append_child("source");
        pugi::xml_attribute address = source.append_attribute("address");
        address = sourceIt->first.c_str();

        for (set<string>::iterator it = sourceIt->second.begin(); it != sourceIt->second.end(); it++)
        {
            pugi::xml_node guid = source.append_child("guid");
            pugi::xml_attribute value = guid.append_attribute("value");
            value = it->c_str();
        }
    }
    doc.save(file);
    file.close();
}

void ConfigHandler::writeDirectionsFile()
{
    ofstream file(DirectionsFilePath);
    file << generateXMLForDirections(*directions);
    file.close();
}

pugi::xml_node ConfigHandler::initializeFile(string filename, string rootItemName)
{
    ifstream file(filename);
    if (file.fail() ) // похоже, файл нужно создать
    {
        ofstream createFile(filename);
        createFile.close();
        throw ConfigHandlerException(INFO, string("Creating "+filename) );
    }
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(file);

    if (result.status != pugi::status_ok)
        throw ConfigHandlerException(ERROR, "Bad XML syntax");

    pugi::xml_node root = doc.child(rootItemName.c_str() );

    if (root == NULL)
        throw ConfigHandlerException(ERROR, "Incorrect config file");

    return root;
}

