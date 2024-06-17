#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <vector>
#include <memory>
#include "Component.hpp"

class Iterator
{
public:
    virtual bool hasNext() const = 0;
    virtual std::shared_ptr<Component> next() = 0;
    virtual ~Iterator() = default;
};

class TreeIterator : public Iterator
{
    std::vector<std::shared_ptr<Component>> nodes;
    size_t index;
    void traverse(std::shared_ptr<Component> node);

public:
    TreeIterator(std::shared_ptr<Component> root);
    bool hasNext() const override;
    std::shared_ptr<Component> next() override;
};

#endif // ITERATOR_HPP
