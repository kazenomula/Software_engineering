#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Component
{
public:
    std::string key;
    std::string value;
    int level;

    Component(const std::string &key, int level, const std::string &value = "");
    virtual void addChild(std::shared_ptr<Component> component);
    virtual ~Component() = default;
};

class TreeNode : public Component
{
public:
    TreeNode(const std::string &key, int level, const std::string &value);
};

class CompositeNode : public Component
{
public:
    std::vector<std::shared_ptr<Component>> children;
    CompositeNode(const std::string &key, int level);
    void addChild(std::shared_ptr<Component> component) override;
};

#endif // COMPONENT_HPP
