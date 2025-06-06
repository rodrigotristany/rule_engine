#pragma once
#include "FactBase.hpp"
#include "Rule.hpp"
#include <vector>
#include <algorithm>

class RuleEngine {
public:
    void addRule(const Rule& rule) {
        auto it = std::lower_bound(rules_.begin(), rules_.end(), rule,
            [](const Rule& a, const Rule& b) {
                return a.priority() > b.priority(); // Descending
            });
        rules_.insert(it, rule);
    }

    void evaluate(FactBase& facts) {
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