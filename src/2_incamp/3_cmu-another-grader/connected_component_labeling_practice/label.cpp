#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <map>
#include "bmplib.h"
#include "dsu.h"

using namespace std;

void usage() {
    cerr << "usage: ./label <options>" << endl;
    cerr << "Examples" << endl;
    cerr << "./label gray <input file> <outputfile>" << endl;
    cerr << "./label binary <inputfile> <outputfile>" << endl;
    cerr << "./label segment <inputfile> <outputfile>" << endl;
}

// Function prototypes
void clean(unsigned char ***input, unsigned char **gray, unsigned char **binary,
           int **labeled_image, int height, int width);

void rgb2gray(unsigned char ***in, unsigned char **out, int height, int width);
void gray2binary(unsigned char **in, unsigned char **out, int height, int width);
int component_labeling(unsigned char **binary_image, int **labeled_image, int height, int width);
void label2RGB(int **labeled_image, unsigned char ***rgb_image, int num_segment, int height, int width);

int main(int argc, char **argv) {
    srand(time(0));

    if (argc < 2) {
        usage();
        return -1;
    }

    unsigned char ***input = 0;
    unsigned char **gray = 0;
    unsigned char **binary = 0;
    int **labeled_image = 0;

    if (strcmp("gray", argv[1]) == 0) {
        if (argc < 4) {
            cerr << "not enough argument for gray" << endl;
            return -1;
        }

        int height, width;
        input = readRGBBMP(argv[2], &height, &width);
        if (input == 0) {
            cerr << "unable to open " << argv[2] << " for input." << endl;
            return -1;
        }

        gray = new unsigned char*[height];
        for (int i = 0; i < height; i++) {
            gray[i] = new unsigned char[width];
        }

        rgb2gray(input, gray, height, width);

        if (writeGSBMP(argv[3], gray, height, width) != 0) {
            cerr << "error writing file " << argv[3] << endl;
            clean(input, gray, binary, labeled_image, height, width);
            return -1;
        }

        clean(input, gray, binary, labeled_image, height, width);
    }
    else if (strcmp("binary", argv[1]) == 0) {
        if (argc < 4) {
            cerr << "not enough argument for binary" << endl;
            return -1;
        }

        int height, width;
        input = readRGBBMP(argv[2], &height, &width);
        if (input == 0) {
            cerr << "unable to open " << argv[2] << " for input." << endl;
            return -1;
        }

        gray = new unsigned char*[height];
        binary = new unsigned char*[height];
        for (int i = 0; i < height; i++) {
            gray[i] = new unsigned char[width];
            binary[i] = new unsigned char[width];
        }

        rgb2gray(input, gray, height, width);
        gray2binary(gray, binary, height, width);

        if (writeBinary(argv[3], binary, height, width) != 0) {
            cerr << "error writing file " << argv[3] << endl;
            clean(input, gray, binary, labeled_image, height, width);
            return -1;
        }

        clean(input, gray, binary, labeled_image, height, width);
    }
    else if (strcmp("segment", argv[1]) == 0) {
        if (argc < 4) {
            cerr << "not enough argument for segment" << endl;
            return -1;
        }

        int height, width;
        input = readRGBBMP(argv[2], &height, &width);
        if (input == 0) {
            cerr << "unable to open " << argv[2] << " for input." << endl;
            return -1;
        }

        gray = new unsigned char*[height];
        binary = new unsigned char*[height];
        for (int i = 0; i < height; i++) {
            gray[i] = new unsigned char[width];
            binary[i] = new unsigned char[width];
        }

        rgb2gray(input, gray, height, width);
        gray2binary(gray, binary, height, width);

        labeled_image = new int*[height];
        for (int i = 0; i < height; i++) {
            labeled_image[i] = new int[width];
            for (int j = 0; j < width; j++) {
                labeled_image[i][j] = 0;
            }
        }

        int segments = component_labeling(binary, labeled_image, height, width);

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < RGB; k++) {
                    input[i][j][k] = 0;
                }
            }
        }

        label2RGB(labeled_image, input, segments, height, width);

        if (writeRGBBMP(argv[3], input, height, width) != 0) {
            cerr << "error writing file " << argv[3] << endl;
            clean(input, gray, binary, labeled_image, height, width);
            return -1;
        }

        clean(input, gray, binary, labeled_image, height, width);
    }
    else {
        usage();
        return -1;
    }

    return 0;
}

// Convert RGB to grayscale
void rgb2gray(unsigned char ***in, unsigned char **out, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            out[i][j] = (unsigned char)(
                0.2989 * (double)in[i][j][0] +
                0.5870 * (double)in[i][j][1] +
                0.1140 * (double)in[i][j][2]
            );
        }
    }
}

// Convert grayscale to binary
void gray2binary(unsigned char **in, unsigned char **out, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (in[i][j] > THRESHOLD) {
                out[i][j] = 1;
            } else {
                out[i][j] = 0;
            }
        }
    }
}

// DSU-based connected component labeling
// The function return number of segments found
int component_labeling(unsigned char **binary_image, int **label, int height, int width) {
    //implement this function with DSU

    int totalPixels = height * width;
    DSU dsu(totalPixels);

    // [i,j] = [i * width + j]
    //หา group ในตำแหน่งบน ซ้าย
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (binary_image[i][j] == 0) continue;
            if (i > 0 && binary_image[i-1][j] == 1){
                dsu.unionSet((i * width + j), ((i-1) * width + j));
            }
            if (j > 0 && binary_image[i][j-1] == 1){
                dsu.unionSet((i * width + j), (i * width + (j-1)));
            }

        }
    }

    map<int, int> rootToLabel;
    int numComponents = 0;
    //แปะป้ายชื่อ
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (binary_image[i][j] == 0) label[i][j] = 0;
            else{
                //เช็คเข้า map
                int root = dsu.findSet((i*width+j));
                if (rootToLabel.count(root) == 0){
                    numComponents++;
                    rootToLabel[root] = numComponents;
                }
                label[i][j] = rootToLabel[root];
            }
        }
    }

    return numComponents;
}

// Assign random RGB color to each segment
void label2RGB(int **labeled_image, unsigned char ***rgb_image, int num_segments, int height, int width) {
    
    unsigned char **colors = new unsigned char*[num_segments];

    //implement this

    for (int i = 0; i < num_segments; i++){
        colors[i] = new unsigned char[3];
        colors[i][0] = rand()%256;
        colors[i][1] = rand()%256;
        colors[i][2] = rand()%256;
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int seg = labeled_image[i][j];
            if (seg > 0){
                rgb_image[i][j][0] = colors[seg-1][0];
                rgb_image[i][j][1] = colors[seg-1][1];
                rgb_image[i][j][2] = colors[seg-1][2];
            }
        }
    }

    for (int i = 0; i < num_segments; i++){
        delete[] colors[i];
    }

    delete colors;





}

// Free all allocated memory
void clean(unsigned char ***input, unsigned char **gray, unsigned char **binary,
           int **labeled_image, int height, int width) {
    if (input) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                delete[] input[i][j];
            }
            delete[] input[i];
        }
        delete[] input;
    }

    if (gray) {
        for (int i = 0; i < height; i++) {
            delete[] gray[i];
        }
        delete[] gray;
    }

    if (binary) {
        for (int i = 0; i < height; i++) {
            delete[] binary[i];
        }
        delete[] binary;
    }

    if (labeled_image) {
        for (int i = 0; i < height; i++) {
            delete[] labeled_image[i];
        }
        delete[] labeled_image;
    }
}