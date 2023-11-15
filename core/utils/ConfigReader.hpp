#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>

class ConfigReader
{
private:
    const char* CONFIG_FILENAME = "config.txt";

    std::string delimiter = ":";
    std::unordered_map<std::string, std::string> configData;

public:
    bool load()
    {
        std::fstream file;
        file.open(CONFIG_FILENAME, std::ios::in);

        if(file.is_open())
        {
            std::string line;
            while(getline(file, line))
            {
                size_t pos = 0;
                std::string token;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                    token = line.substr(0, pos);
                    std::string value = line.substr(pos + 1);

                    configData[token] = value;

                    line.erase(0, pos + delimiter.length());
                }
            }
            file.close();

            return true;
        }

        std::cout << "Failed to open configuration file\n";
        return false;
    }

    inline std::string& getValue(const std::string& token)
    {
        return configData.at(token);
    }
};