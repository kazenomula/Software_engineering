#include "PrintStrategy.hpp"
#include <iostream>

std::unordered_map<int, int> levelCounter;

void TreeStrategy::printPrefix(std::ostringstream &out, int level, bool isLast, bool haschild)
{
    if (level != 1)
    {
        for (int i = 0; i < level - 1; i++)
        {
            out << (i == 0 && !isLast ? "│   " : "    ");
        }
    }
    out << (haschild ? "├──" : "└──");
}

void TreeStrategy::print(std::shared_ptr<Component> node, std::ostringstream &out)
{
    if (!node->key.empty())
    {
        if (auto tnode = std::dynamic_pointer_cast<TreeNode>(node))
        {
            bool isLast = (levelCounter[tnode->level] == 1);
            printPrefix(out, tnode->level, isLast || parentLast, levelCounter[tnode->level]-- != 1);
            parentLast = isLast;
            printIcon(out, true);
            if (!tnode->value.empty())
                out << tnode->key << ":" << tnode->value << std::endl;
            else
                out << tnode->key << std::endl;
        }
        else if (auto cnode = std::dynamic_pointer_cast<CompositeNode>(node))
        {
            bool isLast = (levelCounter[cnode->level]-- == 1);
            printPrefix(out, cnode->level, isLast || parentLast, !cnode->children.empty() && !isLast);
            parentLast = isLast;
            printIcon(out, false);
            if (!cnode->value.empty())
                out << cnode->key << ":" << cnode->value << std::endl;
            else
                out << cnode->key << std::endl;
        }
    }
}

void TreeStrategy::printbuf(std::ostringstream &out)
{
    std::cout << out.str();
}

void RectangleStrategy::printPrefix(std::ostringstream &out, int level, bool isLast)
{
    if (isFirst)
    {
        out << "┌──";
        for (int i = 0; i < level - 1; i++)
        {
            out << "┌───";
        }
    }
    else if (!isLast && !isFirst)
    {
        for (int i = 0; i < level - 1; i++)
        {
            out << "│   ";
        }
        out << "├──";
    }
    else
    {
        out << "└───";
        for (int i = 1; i < level - 1; i++)
        {
            out << "┴───";
        }
        out << "┴──";
    }
}

void RectangleStrategy::print(std::shared_ptr<Component> node, std::ostringstream &out)
{
    if (!node->key.empty())
    {
        if (auto tnode = std::dynamic_pointer_cast<TreeNode>(node))
        {
            bool isLast = true;
            for (const auto &pair : levelCounter)
            {
                if (pair.second > 0 && pair.first != tnode->level)
                {
                    isLast = false;
                    break;
                }
                if (levelCounter[tnode->level] != 1)
                {
                    isLast = false;
                    break;
                }
            }
            printPrefix(out, tnode->level, isLast);
            printIcon(out, true);
            if (!tnode->value.empty())
                out << tnode->key << ":" << tnode->value << std::endl;
            else
                out << tnode->key << std::endl;
            isFirst = false;
            levelCounter[tnode->level]--;
        }
        else if (auto cnode = std::dynamic_pointer_cast<CompositeNode>(node))
        {
            bool isLast = true;
            for (const auto &pair : levelCounter)
            {
                if (pair.second > 0 && pair.first != cnode->level)
                {
                    isLast = false;
                    break;
                }
            }
            printPrefix(out, cnode->level, isLast);
            printIcon(out, false);
            if (!cnode->value.empty())
                out << cnode->key << ":" << cnode->value << std::endl;
            else
                out << cnode->key << std::endl;
            isFirst = false;
            levelCounter[cnode->level]--;
        }
    }
}

void RectangleStrategy::printbuf(std::ostringstream &out)
{
    std::string content = out.str();
    std::istringstream stream(content);
    std::string line;
    std::vector<std::string> lines;
    size_t maxLength = 80;

    while (std::getline(stream, line))
    {
        lines.push_back(line);
        if (line.length() > maxLength)
        {
            maxLength = line.length();
        }
    }

    for (size_t i = 0; i < lines.size(); i++)
    {
        auto l = lines[i];
        std::cout << l;
        for (size_t leng = l.length(); leng < maxLength; leng++)
        {
            std::cout << "─";
        }
        if (i == 0)
            std::cout << "┐" << std::endl;
        else if (i == lines.size() - 1)
            std::cout << "┘" << std::endl;
        else
            std::cout << "┤" << std::endl;
    }
}

void TreePokerStrategy::printIcon(std::ostringstream &out, bool isLeaf)
{
    out << (isLeaf ? "♠" : "♦");
}

void TreeSpaceStrategy::printIcon(std::ostringstream &out, bool isLeaf)
{
    out << " ";
}

void RecPokerStrategy::printIcon(std::ostringstream &out, bool isLeaf)
{
    out << (isLeaf ? "♠" : "♦");
}

void RecSpaceStrategy::printIcon(std::ostringstream &out, bool isLeaf)
{
    out << " ";
}
