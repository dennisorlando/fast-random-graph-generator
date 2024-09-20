#include <iostream>
#include <fstream>  // For file handling

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <nodes> <edges> <outname>" << std::endl;
        return 1;
    }

    int NODES = atoi(argv[1]);
    int EDGES = atoi(argv[2]);
    int EDGES_PER_NODE = EDGES/NODES;

    FILE * out = fopen(argv[3], "w");

    if (out) {

        fprintf(out, "#Nodes: %d", NODES);

        for (int from = 0; from < NODES; from++){

            //uniformly distribute edges in order to not check duplicates
            for (int to = 0; to < EDGES_PER_NODE; to++){
                int to_ = to*NODES/EDGES_PER_NODE;
                fprintf(out, "%d %d\n", from, to_);
            }

        }

        fclose(out);
        std::cout << "Done! :D" << std::endl;
    } else {
        std::cerr << "Unable to open the file! D:" << std::endl;
    }

    return 0;
}
