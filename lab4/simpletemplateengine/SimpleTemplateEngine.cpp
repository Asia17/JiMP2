//
// Created by Asia on 2018-04-09.
//

#include "SimpleTemplateEngine.h"

using nets::View;

View::View() : nana("") {}
View::View(string nana_) {
    this->nana = nana_;
}
View::~View() {}

string View::Render(const unordered_map <string, string> &model) const {
    string lala = nana;
    string rara = "";
    regex pattern {R"(\{\{\w+\}\})"};
    smatch matches;

    while (regex_search (lala, matches, pattern)) {
        for (auto match : matches) {
            string sub = match.str();
            sub = sub.substr(2, sub.length()-4);
            rara += matches.prefix().str();
            if (model.find(sub) != model.end()) {
                string next;
                next = model.find(sub)->second;
                rara += next;
            }
        }
        lala = matches.suffix().str();
    }
    rara += lala;
    return rara;
}