#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <memory>
#include "jsonToTree.hpp"
#include "Iterator.hpp"
#include "PrintStrategy.hpp"
#include "Printer.hpp"

int main()
{
    // 打开JSON文件
    std::ifstream inputFile("example.json");
    if (!inputFile.is_open())
    {
        std::cerr << "无法打开文件!" << std::endl;
        return 1;
    }

    // 解析JSON文件
    nlohmann::json j;
    inputFile >> j;

    std::shared_ptr<Component> root = jsonToTree(j);

    std::shared_ptr<Iterator> its = std::make_shared<TreeIterator>(root);

    std::shared_ptr<PrintStrategy> ps = std::make_shared<RecSpaceStrategy>();
    std::shared_ptr<Printer> pt = std::make_shared<Printer>(ps);
    pt->BufferConstruct(its);
    pt->PrintBuffer();

    return 0;
}
