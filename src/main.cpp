#include "RuleEngine.hpp"
#include <iostream>

int main() {
    FactBase facts;
    facts.set("temperature", 35);

    RuleEngine engine;

    engine.addRule(Rule{
        "Cooling Alert", 2,
        [](const FactBase& f) {
            return f.get<int>("temperature") > 30;
        },
        [](FactBase& f) {
            std::cout << "Action: Turn on cooling system.\n";
        }
    });

    engine.addRule(Rule{
        "Extreme Heat Warning", 3,
        [](const FactBase& f) {
            return f.get<int>("temperature") > 40;
        },
        [](FactBase& f) {
            std::cout << "Action: Send emergency heat warning.\n";
        }
    });

    engine.evaluate(facts);
}