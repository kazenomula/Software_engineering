#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <memory>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>
#include <unordered_map>

using json = nlohmann::json;
using namespace std;
static unordered_map<int, int> levelCounter;

// 基本的Component类
class Component
{
public:
    string key;
    string value;
    int level;

    Component(const string &key, int level, const string &value = "") : key(key), level(level), value(value) {}

    virtual void addChild(shared_ptr<Component> component)
    {
        throw logic_error("Cannot add child to a leaf Component");
    }

    virtual ~Component() = default;
};

class TreeNode : public Component
{
public:
    TreeNode(const string &key, int level, const string &value) : Component(key, level, value) {}
};

class CompositeNode : public Component
{
public:
    vector<shared_ptr<Component>> children;

    CompositeNode(const string &key, int level) : Component(key, level) {}

    void addChild(shared_ptr<Component> component) override
    {
        children.push_back(component);
    }
};

// 迭代器模式
class Iterator
{
public:
    virtual bool hasNext() const = 0;
    virtual shared_ptr<Component> next() = 0;
    virtual ~Iterator() = default;
};

class TreeIterator : public Iterator
{
    vector<shared_ptr<Component>> nodes;
    size_t index;

    void traverse(shared_ptr<Component> node)
    {
        nodes.push_back(node);
        if (auto composite = dynamic_pointer_cast<CompositeNode>(node))
        {
            for (const auto &child : composite->children)
            {
                traverse(child);
            }
        }
    }

public:
    TreeIterator(shared_ptr<Component> root) : index(0)
    {
        traverse(root);
    }

    bool hasNext() const override
    {
        return index < nodes.size();
    }

    shared_ptr<Component> next() override
    {
        return nodes[index++];
    }
};

shared_ptr<Component> jsonToTree(const json &j, const string &key = "", int level = 0)
{
    if (j.is_object())
    {
        auto composite = make_shared<CompositeNode>(key, level);
        levelCounter[level]+=(level==0?0:1);
        for (auto it = j.begin(); it != j.end(); ++it)
        {
            composite->addChild(jsonToTree(it.value(), it.key(), level + 1));
        }
        return composite;
    }
    else if (j.is_array())
    {
        auto composite = make_shared<CompositeNode>(key, level);
        levelCounter[level]++;
        for (size_t i = 0; i < j.size(); ++i)
        {
            composite->addChild(jsonToTree(j[i], "[" + to_string(i) + "]", level + 1));
        }
        return composite;
    }
    else
    {
        auto treeNode = make_shared<TreeNode>(key, level, j.dump());
        levelCounter[level]+=(level==0?0:1);
        return treeNode;
    }
}

class PrintStrategy
{
public:
    virtual void print(shared_ptr<Component> node, ostringstream &out) = 0;
    virtual void printbuf(ostringstream &out) = 0;
    virtual ~PrintStrategy() = default;
};

class TreeStrategy : public PrintStrategy
{
protected:
    bool parentLast = false;
    void printPrefix(ostringstream &out, int level, bool isLast, bool haschild)
    {
        if (level != 1)
        {
            for (int i = 0; i < level - 1; i++)
            {
                out << (i == 0&&!isLast ? "│   " : "    ");
            }
        }
        out << (haschild ? "├──" : "└──");
    }
    virtual void printIcon(ostringstream &out, bool isLeaf) = 0;

public:
    void print(shared_ptr<Component> node, ostringstream &out) override
    {
        if(!node->key.empty())
        {
            if (auto tnode = dynamic_pointer_cast<TreeNode>(node))
            {
                bool isLast = (levelCounter[tnode->level]== 1);
                printPrefix(out, tnode->level, isLast||parentLast, levelCounter[tnode->level]--!= 1);
                parentLast = isLast;
                printIcon(out, true);
                if (!tnode->value.empty())
                    out << tnode->key << ":" << tnode->value << endl;
                else
                    out << tnode->key << endl;
            }
            else if (auto cnode = dynamic_pointer_cast<CompositeNode>(node))
            {
                bool isLast = (levelCounter[cnode->level]-- == 1);
                printPrefix(out, cnode->level, isLast||parentLast, !cnode->children.empty()&&!isLast);
                parentLast = isLast;
                printIcon(out, false);
                if (!cnode->value.empty())
                    out << cnode->key << ":" << cnode->value << endl;
                else
                    out << cnode->key << endl;
            }
        }
        
    }

    void printbuf(ostringstream &out) override
    {
        cout << out.str();
    }
};

class RectangleStrategy : public PrintStrategy
{
protected:
    bool isFirst = true;
    void printPrefix(ostringstream &out, int level, bool isLast)
    {
        if (isFirst)
        {
            out << "┌──";
            for (int i = 0; i < level - 1; i++)
            {
                out << "┌───";
            }
        }
        else if (!isLast&&!isFirst)
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
            for (int i = 0; i < level-1; i++)
            {
                out << "┴───";
            }
            out<<"┴──";
        }
    }
    virtual void printIcon(ostringstream &out, bool isLeaf) = 0;

public:
    void print(shared_ptr<Component> node, ostringstream &out) override
    {
        if(!node->key.empty())
        {
            if (auto tnode = dynamic_pointer_cast<TreeNode>(node))
            {
                bool isLast = true;
                for (const auto &pair : levelCounter)
                {
                    //cout<<tnode->key<<levelCounter[tnode->level]<<endl;
                    if (pair.second > 0 && pair.first != tnode->level)
                    {
                        //cout<<tnode->key<<levelCounter[tnode->level]<<endl;
                        isLast = false;
                        break;
                    }
                    if(levelCounter[tnode->level] != 1)
                    {
                        isLast = false;
                        break;
                    }
                }
                printPrefix(out, tnode->level, isLast);
                printIcon(out, true);
                if (!tnode->value.empty())
                    out << tnode->key << ":" << tnode->value << endl;
                else
                    out << tnode->key << endl;
                isFirst = false;
                levelCounter[tnode->level]--;
            }
            else if (auto cnode = dynamic_pointer_cast<CompositeNode>(node))
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
                    out << cnode->key << ":" << cnode->value << endl;
                else
                    out << cnode->key << endl;
                isFirst = false;
                levelCounter[cnode->level]--;
            }
        }
    }

    void printbuf(ostringstream &out) override
    {
        string content = out.str();
        istringstream stream(content);
        string line;
        vector<string> lines;
        size_t maxLength = 80;

        while (getline(stream, line))
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
            cout << l;
            for (size_t leng = l.length(); leng < maxLength; leng++)
            {
                cout << "─";
            }
            if (i == 0)
                cout << "┐" << endl;
            else if (i == lines.size() - 1)
                cout << "┘" << endl;
            else
                cout << "┤" << endl;
        }
    }
};

class TreePokerStrategy : public TreeStrategy
{
protected:
    void printIcon(ostringstream &out, bool isLeaf) override
    {
        out << (isLeaf ? "♠" : "♦");
    }
};

class TreeSpaceStrategy : public TreeStrategy
{
protected:
    void printIcon(ostringstream &out, bool isLeaf) override
    {
        out << " ";
    }
};

class RecPokerStrategy : public RectangleStrategy
{
protected:
    void printIcon(ostringstream &out, bool isLeaf) override
    {
        out << (isLeaf ? "♠" : "♦");
    }
};

class RecSpaceStrategy : public RectangleStrategy
{
protected:
    void printIcon(ostringstream &out, bool isLeaf) override
    {
        out << " ";
    }
};

class Printer
{
public:
    Printer(shared_ptr<PrintStrategy> strategy) : strategy(strategy), buf(make_shared<ostringstream>()) {}
    void BufferConstruct(shared_ptr<Iterator> its)
    {
        while (its->hasNext())
        {
            auto node = its->next();
            strategy->print(node, *buf);
        }
    }
    void PrintBuffer()
    {
        strategy->printbuf(*buf);
    }

private:
    shared_ptr<ostringstream> buf;
    shared_ptr<PrintStrategy> strategy;
};

int main()
{
    // 打开JSON文件
    ifstream inputFile("example.json");
    if (!inputFile.is_open())
    {
        cerr << "无法打开文件!" << endl;
        return 1;
    }

    // 解析JSON文件
    json j;
    inputFile >> j;

    shared_ptr<Component> root = jsonToTree(j);

    shared_ptr<Iterator> its = make_shared<TreeIterator>(root);

    shared_ptr<PrintStrategy> ps = make_shared<TreeSpaceStrategy>();
    shared_ptr<Printer> pt = make_shared<Printer>(ps);
    pt->BufferConstruct(its);
    pt->PrintBuffer();

    return 0;
}
