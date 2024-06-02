#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <memory>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>

using json = nlohmann::json;
using namespace std;

// 基本的Component类
class Component {
public:
    string key;
    string value;

    Component(const string& key, const string& value = "") : key(key), value(value) {}

    virtual void addChild(shared_ptr<Component> component) {
        throw logic_error("Cannot add child to a leaf component");
    }

    virtual ~Component() = default;
};

class TreeNode : public Component {
public:
    TreeNode(const string& key, const string& value) : Component(key, value) {}
};

class CompositeNode : public Component {
public:
    vector<shared_ptr<Component>> children;

    CompositeNode(const string& key) : Component(key) {}

    void addChild(shared_ptr<Component> component) override {
        children.push_back(component);
    }
};

// 基类Printer，定义打印接口
class Printer {
public:
    virtual void print(shared_ptr<Component> node, ostringstream& out, const string& indent = "", bool isLast = true) = 0;
    virtual ~Printer() = default;

protected:
    virtual void printPrefix(ostringstream& out, const string& indent, bool isLast) = 0;
    virtual void printTreeNode(shared_ptr<TreeNode> node, ostringstream& out) = 0;
    virtual void printCompositeNode(shared_ptr<CompositeNode> node, ostringstream& out, const string& indent, bool isLast) = 0;
};

// TreePrinter类继承自Printer
class TreePrinter : public Printer {
protected:
    void printPrefix(ostringstream& out, const string& indent, bool isLast) override {
        if (!isLast) {
            out << "├──";
        } else {
            out << "└──";
        }
    }

    void printTreeNode(shared_ptr<TreeNode> node, ostringstream& out) override {
        out << node->key << ": " << node->value;
    }

    void printCompositeNode(shared_ptr<CompositeNode> node, ostringstream& out, const string& indent, bool isLast) override {
        if (!node->key.empty()) {
            out << node->key << ":" << endl;
        }
        for (size_t i = 0; i < node->children.size(); ++i) {
            bool lastChild = (i == node->children.size() - 1);
            string childIndent = indent + (isLast ? "    " : "│   ");
            print(node->children[i], out, childIndent, lastChild);
            if (!lastChild) {
                out << endl;
            }
        }
    }
    virtual void printIcon(ostringstream& out, bool isLeaf) = 0;
};

// TreePokerPrinter类继承自TreePrinter
class TreePokerPrinter : public TreePrinter {
public:
    void print(shared_ptr<Component> node, ostringstream& out, const string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }
protected:
    void printIcon(ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << "♦";
        } else {
            out << "♠";
        }
    }
};

// TreeSpacePrinter类继承自TreePrinter
class TreeSpacePrinter : public TreePrinter {
public:
    void print(shared_ptr<Component> node, ostringstream& out, const string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }
protected:
    void printIcon(ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << " ";
        } else {
            out << " ";
        }
    }
};

class RectanglePrinter : public Printer {
protected:
    void printPrefix(ostringstream& out, const string& indent, bool isLast) override {
        if (!isLast) {
            out << "├──";
        } else {
            out << "├──";
        }
    }

    void printTreeNode(shared_ptr<TreeNode> node, ostringstream& out) override {
        out << node->key << ": " << node->value;
    }

    void printCompositeNode(shared_ptr<CompositeNode> node, ostringstream& out, const string& indent, bool isLast) override {
        if (!node->key.empty()) {
            out << node->key << ":";
            out << endl;
        }
        for (size_t i = 0; i < node->children.size(); ++i) {
            bool lastChild = (i == node->children.size() - 1);
            string childIndent = indent + (isLast ? "    " : "│   ");
            print(node->children[i], out, childIndent, lastChild);
            if (!lastChild) {
                out << endl;
            }
        }
    }

    virtual void printIcon(ostringstream& out, bool isLeaf) = 0;
};

// RectanglePokerPrinter类继承自RectanglePrinter
class RectanglePokerPrinter : public RectanglePrinter {
public:
    void print(shared_ptr<Component> node, ostringstream& out, const string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }
protected:
    void printIcon(ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << "♦";
        } else {
            out << "♠";
        }
    }
};

// RectangleSpacePrinter类继承自RectanglePrinter
class RectangleSpacePrinter : public RectanglePrinter {
public:
    void print(shared_ptr<Component> node, ostringstream& out, const string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }
protected:
    void printIcon(ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << " ";
        } else {
            out << " ";
        }
    }
};


shared_ptr<Component> jsonToTree(const json& j, const string& key = "") {
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

// 基类Buffer
class Buffer {
public:
    virtual void printTree(shared_ptr<Component> node) = 0;
    virtual void printBuffer() const = 0;
    virtual ~Buffer() = default;
};

// TreeBuffer类继承自Buffer
class TreeBuffer : public Buffer {
public:
    TreeBuffer(shared_ptr<Printer> printer) : printer(printer) {}

    void printTree(shared_ptr<Component> node) override {
        ostringstream& out = buf;
        printer->print(node, out);
    }

    void printBuffer() const override {
        cout << buf.str();
    }

private:
    ostringstream buf;
    shared_ptr<Printer> printer;
};

class RectangleBuffer : public Buffer {
public:
    RectangleBuffer(shared_ptr<Printer> printer) : printer(printer) {}

    void printTree(shared_ptr<Component> node) override {
        ostringstream& out = buf;
        printer->print(node, out);
    }

    void printBuffer() const override {
        // 获取所有内容的字符串
        string content = buf.str();

        // 分割每一行
        vector<string> lines;
        istringstream stream(content);
        string line;
        size_t maxLength = 0;

        // 获取最长行的长度
        while (getline(stream, line)) {
            lines.push_back(line);
            if (line.length() > maxLength) {
                maxLength = line.length();
            }
        }

        // 打印顶边框
        cout << "┌";
        for (size_t i = 0; i < maxLength; ++i) {
            cout << "─";
        }
        cout << "┐" << endl;

        // 打印每一行
        for (const auto& l : lines) {
            cout << "│" << l;
            // 补齐每行后面的空格
            for (size_t i = l.length(); i < maxLength; ++i) {
                cout << "─";
            }
            cout << "┤" << endl;
        }

        // 打印底边框
        cout << "└";
        for (size_t i = 0; i < maxLength; ++i) {
            cout << "─";
        }
        cout << "┘" << endl;
    }

private:
    ostringstream buf;
    shared_ptr<Printer> printer;
};

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
