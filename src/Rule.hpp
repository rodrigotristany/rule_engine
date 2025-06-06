#pragma once
#include "FactBase.hpp"
#include <functional>

class Rule {
public:
    Rule(std::string name, int priority,
         std::function<bool(const FactBase&)> condition,
         std::function<void(FactBase&)> action)
        : name_(std::move(name)), priority_(priority),
          condition_(std::move(condition)), action_(std::move(action)) {}

    bool evaluate(const FactBase& facts) const {
        return condition_ ? condition_(facts) : false;
    }

    void execute(FactBase& facts) const {
        if (action_) action_(facts);
    }

    const std::string& name() const { return name_; }
    int priority() const { return priority_; }

private:
    std::string name_;
    int priority_;
    std::function<bool(const FactBase&)> condition_;
    std::function<void(FactBase&)> action_;
};