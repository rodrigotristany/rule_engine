#include "RuleEngine.hpp"
#include <iostream>

int main() {
  FactBase facts;
  facts.set("age", 25);

  RuleEngine engine;

  Rule rule([](const FactBase &f) { return f.get<int>("age") > 18; },
            []() { std::cout << "Access granted.\n"; });

  engine.addRule(rule);
  engine.evaluate(facts);

  return 0;
}
