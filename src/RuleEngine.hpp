#pragma once
#include "FactBase.hpp"
#include "Rule.hpp"
#include <vector>
#include <algorithm>

class RuleEngine {
public:
    void addRule(const Rule& rule) {
        rules_.push_back(rule);
    }

    void evaluate(FactBase& facts) {
        // Sort by descending priority (higher first)
        std::sort(rules_.begin(), rules_.end(),
                  [](const Rule& a, const Rule& b) {
                      return a.priority() > b.priority();
                  });

        for (const auto& rule : rules_) {
            if (rule.evaluate(facts)) {
                std::cout << "Executing rule: " << rule.name() << "\n";
                rule.execute(facts);
            }
        }
    }

private:
    std::vector<Rule> rules_;
};