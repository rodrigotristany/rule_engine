#pragma once
#include "FactBase.hpp"
#include <functional>

class Rule {
  std::function<bool(const FactBase &)> condition;
  std::function<void()> action;

public:
  Rule(std::function<bool(const FactBase &)> cond, std::function<void()> act)
      : condition(cond), action(act) {}

  void evaluate(const FactBase &facts) const {
    if (condition(facts)) {
      action();
    }
  }
};