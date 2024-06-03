#ifndef BUFFER_H
#define BUFFER_H

#include <memory>
#include <sstream>
#include "Component.hpp"
#include "Printer.hpp"

class Buffer {
public:
    virtual void printTree(std::shared_ptr<Component> node) = 0;
    virtual void printBuffer() const = 0;
    virtual ~Buffer() = default;
};

class TreeBuffer : public Buffer {
public:
    TreeBuffer(std::shared_ptr<Printer> printer) : printer(printer) {}

    void printTree(std::shared_ptr<Component> node) override {
        std::ostringstream& out = buf;
        printer->print(node, out);
    }

    void printBuffer() const override {
        std::cout << buf.str();
    }

private:
    std::ostringstream buf;
    std::shared_ptr<Printer> printer;
};

class RectangleBuffer : public Buffer {
public:
    RectangleBuffer(std::shared_ptr<Printer> printer) : printer(printer) {}

    void printTree(std::shared_ptr<Component> node) override {
        std::ostringstream& out = buf;
        printer->print(node, out);
    }

    void printBuffer() const override {
        // 获取所有内容的字符串
        std::string content = buf.str();

        // 分割每一行
        std::vector<std::string> lines;
        std::istringstream stream(content);
        std::string line;
        size_t maxLength = 0;

        // 获取最长行的长度
        while (std::getline(stream, line)) {
            lines.push_back(line);
            if (line.length() > maxLength) {
                maxLength = line.length();
            }
        }

        // 打印顶边框
        std::cout << "┌";
        for (size_t i = 0; i < maxLength; ++i) {
            std::cout << "─";
        }
        std::cout << "┐" << std::endl;

        // 打印每一行
        for (const auto& l : lines) {
            std::cout << "│" << l;
            // 补齐每行后面的空格
            for (size_t i = l.length(); i < maxLength; ++i) {
                std::cout << "─";
            }
            std::cout << "┤" << std::endl;
        }

        // 打印底边框
        std::cout << "└";
        for (size_t i = 0; i < maxLength; ++i) {
            std::cout << "─";
        }
        std::cout << "┘" << std::endl;
    }

private:
    std::ostringstream buf;
    std::shared_ptr<Printer> printer;
};

#endif // BUFFER_H
