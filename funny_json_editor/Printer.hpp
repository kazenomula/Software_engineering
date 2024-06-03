#ifndef PRINTER_H
#define PRINTER_H

#include <memory>
#include <sstream>
#include "Component.hpp"

class Printer {
public:
    virtual void print(std::shared_ptr<Component> node, std::ostringstream& out, const std::string& indent = "", bool isLast = true) = 0;
    virtual ~Printer() = default;

protected:
    virtual void printPrefix(std::ostringstream& out, const std::string& indent, bool isLast) = 0;
    virtual void printTreeNode(std::shared_ptr<TreeNode> node, std::ostringstream& out) = 0;
    virtual void printCompositeNode(std::shared_ptr<CompositeNode> node, std::ostringstream& out, const std::string& indent, bool isLast) = 0;
    virtual void printIcon(std::ostringstream& out, bool isLeaf) = 0;
};

class TreePrinter : public Printer {
protected:
    void printPrefix(std::ostringstream& out, const std::string& indent, bool isLast) override {
        if (!isLast) {
            out << "├──";
        } else {
            out << "└──";
        }
    }

    void printTreeNode(std::shared_ptr<TreeNode> node, std::ostringstream& out) override {
        out << node->key << ": " << node->value;
    }

    void printCompositeNode(std::shared_ptr<CompositeNode> node, std::ostringstream& out, const std::string& indent, bool isLast) override {
        if (!node->key.empty()) {
            out << node->key << ":" << std::endl;
        }
        for (size_t i = 0; i < node->children.size(); ++i) {
            bool lastChild = (i == node->children.size() - 1);
            std::string childIndent = indent + (isLast ? "    " : "│   ");
            print(node->children[i], out, childIndent, lastChild);
            if (!lastChild) {
                out << std::endl;
            }
        }
    }
};

class TreePokerPrinter : public TreePrinter {
public:
    void print(std::shared_ptr<Component> node, std::ostringstream& out, const std::string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = std::dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = std::dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }

protected:
    void printIcon(std::ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << "♦";
        } else {
            out << "♠";
        }
    }
};

class TreeSpacePrinter : public TreePrinter {
public:
    void print(std::shared_ptr<Component> node, std::ostringstream& out, const std::string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = std::dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = std::dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }

protected:
    void printIcon(std::ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << " ";
        } else {
            out << " ";
        }
    }
};

class RectanglePrinter : public Printer {
protected:
    void printPrefix(std::ostringstream& out, const std::string& indent, bool isLast) override {
        if (!isLast) {
            out << "├──";
        } else {
            out << "├──";
        }
    }

    void printTreeNode(std::shared_ptr<TreeNode> node, std::ostringstream& out) override {
        out << node->key << ": " << node->value;
    }

    void printCompositeNode(std::shared_ptr<CompositeNode> node, std::ostringstream& out, const std::string& indent, bool isLast) override {
        if (!node->key.empty()) {
            out << node->key << ":";
            out << std::endl;
        }
        for (size_t i = 0; i < node->children.size(); ++i) {
            bool lastChild = (i == node->children.size() - 1);
            std::string childIndent = indent + (isLast ? "    " : "│   ");
            print(node->children[i], out, childIndent, lastChild);
            if (!lastChild) {
                out << std::endl;
            }
        }
    }
};

class RectanglePokerPrinter : public RectanglePrinter {
public:
    void print(std::shared_ptr<Component> node, std::ostringstream& out, const std::string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = std::dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = std::dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }

protected:
    void printIcon(std::ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << "♦";
        } else {
            out << "♠";
        }
    }
};

class RectangleSpacePrinter : public RectanglePrinter {
public:
    void print(std::shared_ptr<Component> node, std::ostringstream& out, const std::string& indent = "", bool isLast = true) override {
        out << indent;
        if (auto treeNode = std::dynamic_pointer_cast<TreeNode>(node)) {
            printPrefix(out, indent, isLast);
            printIcon(out, 1);
            printTreeNode(treeNode, out);
        } else if (auto composite = std::dynamic_pointer_cast<CompositeNode>(node)) {
            if(!node->key.empty()) {
                printPrefix(out, indent, isLast);
                printIcon(out, 0);
            }
            printCompositeNode(composite, out, indent, isLast);
        }
    }

protected:
    void printIcon(std::ostringstream& out, bool isLeaf) override {
        if(!isLeaf) {
            out << " ";
        } else {
            out << " ";
        }
    }
};

#endif // PRINTER_H
