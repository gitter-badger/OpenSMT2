//
// Created by prova on 02.09.20.
//
#include "IteToSwitch.h"
#include <fstream>

void IteToSwitch::stackBasedDFS(PTRef root) const {

    vec<PTRef> queue;
    vec<type> flag;
    flag.growTo(logic.getNumberOfTerms());

    DFS(root, flag);
}

void IteToSwitch::DFS(PTRef root, vec<type> &flag) const {
    auto index = Idx(logic.getPterm(root).getId());
    flag[index] = type::gray;
    Pterm &t = logic.getPterm(root);
    for (int i = 0; i < t.size(); i++) {
        auto childIndex = Idx(logic.getPterm(t[i]).getId());
        if (flag[childIndex] == type::white) {
            DFS(t[i], flag);
        }
    }
    flag[index] = type::black;
}

void IteToSwitch::iterativeDFS(PTRef root) const {
    vec<PTRef> queue;
    vec<type> flag;
    flag.growTo(logic.getNumberOfTerms());
    queue.push(root);

    while (queue.size() != 0) {
        PTRef tr = queue.last();
        const Pterm &t = logic.getPterm(tr);
        auto index = Idx(t.getId());
        if (flag[index] == type::black) {
            queue.pop();
            continue;
        }

        flag[index] = type::gray;

        bool unprocessed_children = false;

        for (int i = 0; i < t.size(); i++) {
            auto childIndex = Idx(logic.getPterm(t[i]).getId());
            if (flag[childIndex] == type::white) {
                queue.push(t[i]);
                unprocessed_children = true;
            }
        }

        if (unprocessed_children) {
            continue;
        }

        flag[index] = type::black;

        queue.pop();
    }
}

void IteToSwitch::printDagToFile(const std::string &fname, const ite::Dag &dag) {
    std::fstream fs;
    fs.open(fname, std::fstream::out);
    dag.getDagAsStream(fs);
    fs.close();
}

void ite::Dag::getDagAsStream(std::ostream &out) const {
    std::string annotations_str;
    std::string edges_str;
    auto &nodes = getNodes();
    std::cout << "Starting production of a graph" << std::endl;
    for (const ite::NodeRef node : nodes) {
        if (isTopLevelIte(na[node].getTerm())) {
            annotations_str += " " + std::to_string(na[node].getId()) + " [shape=box];\n";
        }
        if (na[node].getTrueChild() != NodeRef_Undef) {
            edges_str += " " + std::to_string(na[node].getId()) + " -> " + std::to_string(na[na[node].getTrueChild()].getId()) + ";\n";
        }
        if (na[node].getFalseChild() != NodeRef_Undef) {
            edges_str += " " + std::to_string(na[node].getId()) + " -> " + std::to_string(na[na[node].getFalseChild()].getId()) + ";\n";
        }
    }
    out << "digraph G {" << annotations_str << "\n" << edges_str << "}" << std::endl;
}