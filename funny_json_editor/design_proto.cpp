#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Buffer.hpp"
#include "Component.hpp"
#include "Printer.hpp"

using json = nlohmann::json;
using namespace std;

shared_ptr<Component> jsonToTree(const json& j, const string& key) {
    if (j.is_object()) {
        auto composite = make_shared<CompositeNode>(key);
        for (auto it = j.begin(); it != j.end(); ++it) {
            composite->addChild(jsonToTree(it.value(), it.key()));
        }
        return composite;
    } else if (j.is_array()) {
        auto composite = make_shared<CompositeNode>(key);
        for (size_t i = 0; i < j.size(); ++i) {
            composite->addChild(jsonToTree(j[i], "[" + to_string(i) + "]"));
        }
        return composite;
    } else {
        return make_shared<TreeNode>(key, j.dump());
    }
}

int main() {
    // 打开JSON文件
    ifstream inputFile("example.json");
    if (!inputFile.is_open()) {
        cerr << "无法打开文件!" << endl;
        return 1;
    }

    // 解析JSON文件
    json j;
    inputFile >> j;

    // 将JSON转换为多叉树
    shared_ptr<Component> root = jsonToTree(j);

    // 创建Printer对象
    shared_ptr<Printer> printer = make_shared<RectangleSpacePrinter>();

    // 创建Buffer对象
    shared_ptr<Buffer> buffer = make_shared<RectangleBuffer>(printer);

    // 将多叉树内容转换为风格并放入缓冲区
    buffer->printTree(root);

    // 打印缓冲区内容
    buffer->printBuffer();
    std::cout << std::endl;

    return 0;
}
