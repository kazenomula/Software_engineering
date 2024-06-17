#include "Iterator.hpp"

TreeIterator::TreeIterator(std::shared_ptr<Component> root) : index(0)
{
    traverse(root);
}

void TreeIterator::traverse(std::shared_ptr<Component> node)
{
    nodes.push_back(node);
    if (auto composite = std::dynamic_pointer_cast<CompositeNode>(node))
    {
        for (const auto &child : composite->children)
        {
            traverse(child);
        }
    }
}

bool TreeIterator::hasNext() const
{
    return index < nodes.size();
}

std::shared_ptr<Component> TreeIterator::next()
{
    return nodes[index++];
}
