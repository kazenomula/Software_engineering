#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Component {
public:
    std::string key;
    std::string value;

    Component(const std::string& key, const std::string& value = "") : key(key), value(value) {}

    virtual void addChild(std::shared_ptr<Component> component) {
        throw std::logic_error("Cannot add child to a leaf component");
    }

    virtual ~Component() = default;
};

class TreeNode : public Component {
public:
    TreeNode(const std::string& key, const std::string& value) : Component(key, value) {}
};

class CompositeNode : public Component {
public:
    std::vector<std::shared_ptr<Component>> children;

    CompositeNode(const std::string& key) : Component(key) {}

    void addChild(std::shared_ptr<Component> component) override {
        children.push_back(component);
    }
};

std::shared_ptr<Component> jsonToTree(const nlohmann::json& j, const std::string& key = "");

#endif // COMPONENT_H
