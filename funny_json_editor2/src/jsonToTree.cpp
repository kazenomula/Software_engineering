#include "jsonToTree.hpp"
#include <unordered_map>

extern std::unordered_map<int, int> levelCounter;

std::shared_ptr<Component> jsonToTree(const nlohmann::json &j, const std::string &key, int level)
{
    if (j.is_object())
    {
        auto composite = std::make_shared<CompositeNode>(key, level);
        levelCounter[level] += (level == 0 ? 0 : 1);
        for (auto it = j.begin(); it != j.end(); ++it)
        {
            composite->addChild(jsonToTree(it.value(), it.key(), level + 1));
        }
        return composite;
    }
    else if (j.is_array())
    {
        auto composite = std::make_shared<CompositeNode>(key, level);
        levelCounter[level]++;
        for (size_t i = 0; i < j.size(); ++i)
        {
            composite->addChild(jsonToTree(j[i], "[" + std::to_string(i) + "]", level + 1));
        }
        return composite;
    }
    else
    {
        auto treeNode = std::make_shared<TreeNode>(key, level, j.dump());
        levelCounter[level] += (level == 0 ? 0 : 1);
        return treeNode;
    }
}
