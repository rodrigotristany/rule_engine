#pragma once
#include "Rule.hpp"
#include <vector>

class RuleEngine {
  std::vector<Rule> rules;

public:
  void addRule(const Rule &rule) { rules.push_back(rule); }

  void evaluate(const FactBase &facts) const {
    for (const auto &rule : rules) {
      rule.evaluate(facts);
    }
  }
};