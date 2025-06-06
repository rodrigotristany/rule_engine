#pragma once
#include <any>
#include <stdexcept>
#include <string>
#include <unordered_map>

class FactBase {
  std::unordered_map<std::string, std::any> facts;

public:
  template <typename T> void set(const std::string &key, T value) {
    facts[key] = value;
  }

  template <typename T> T get(const std::string &key) const {
    auto it = facts.find(key);
    if (it == facts.end()) {
      throw std::runtime_error("Fact not found: " + key);
    }
    return std::any_cast<T>(it->second);
  }
};