#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Device {};

class DeviceManager 
{
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
    {
        return m_Devices;
    }
};

int main()
{
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    /* zamiast tego
    for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    */ 
    // pisze to
    for(auto it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    DeviceManager dm;
    const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices(); // strasznie dlugi typ prawda?
    // dlatego mozna to zrobic tak jak ponizej:
    auto& devices_v2 = dm.GetDevices();
    // lub jesli bardzo nie chcemy uzywac auto to:
    using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
    const DeviceMap& devices_v3 = dm.GetDevices();
    // albo
    typedef std::unordered_map<std::string, std::vector<Device*>> DeviceType;
    const DeviceType& devices_v4 = dm.GetDevices();
}   