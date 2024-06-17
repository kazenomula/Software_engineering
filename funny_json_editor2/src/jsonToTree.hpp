#ifndef JSONTOTREE_HPP
#define JSONTOTREE_HPP

#include <nlohmann/json.hpp>
#include <memory>
#include "Component.hpp"

std::shared_ptr<Component> jsonToTree(const nlohmann::json &j, const std::string &key = "", int level = 0);

#endif // JSONTOTREE_HPP
