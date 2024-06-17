#ifndef PRINTSTRATEGY_HPP
#define PRINTSTRATEGY_HPP

#include <sstream>
#include "Component.hpp"
#include <unordered_map>

extern std::unordered_map<int, int> levelCounter;

class PrintStrategy
{
public:
    virtual void print(std::shared_ptr<Component> node, std::ostringstream &out) = 0;
    virtual void printbuf(std::ostringstream &out) = 0;
    virtual ~PrintStrategy() = default;
};

class TreeStrategy : public PrintStrategy
{
protected:
    bool parentLast = false;
    void printPrefix(std::ostringstream &out, int level, bool isLast, bool haschild);
    virtual void printIcon(std::ostringstream &out, bool isLeaf) = 0;

public:
    void print(std::shared_ptr<Component> node, std::ostringstream &out) override;
    void printbuf(std::ostringstream &out) override;
};

class RectangleStrategy : public PrintStrategy
{
protected:
    bool isFirst = true;
    void printPrefix(std::ostringstream &out, int level, bool isLast);
    virtual void printIcon(std::ostringstream &out, bool isLeaf) = 0;

public:
    void print(std::shared_ptr<Component> node, std::ostringstream &out) override;
    void printbuf(std::ostringstream &out) override;
};

class TreePokerStrategy : public TreeStrategy
{
protected:
    void printIcon(std::ostringstream &out, bool isLeaf) override;
};

class TreeSpaceStrategy : public TreeStrategy
{
protected:
    void printIcon(std::ostringstream &out, bool isLeaf) override;
};

class RecPokerStrategy : public RectangleStrategy
{
protected:
    void printIcon(std::ostringstream &out, bool isLeaf) override;
};

class RecSpaceStrategy : public RectangleStrategy
{
protected:
    void printIcon(std::ostringstream &out, bool isLeaf) override;
};

#endif // PRINTSTRATEGY_HPP
