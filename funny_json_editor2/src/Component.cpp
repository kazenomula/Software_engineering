#include "Component.hpp"

Component::Component(const std::string &key, int level, const std::string &value)
    : key(key), level(level), value(value) {}

void Component::addChild(std::shared_ptr<Component> component)
{
    throw std::logic_error("Cannot add child to a leaf Component");
}

TreeNode::TreeNode(const std::string &key, int level, const std::string &value)
    : Component(key, level, value) {}

CompositeNode::CompositeNode(const std::string &key, int level)
    : Component(key, level) {}

void CompositeNode::addChild(std::shared_ptr<Component> component)
{
    children.push_back(component);
}
