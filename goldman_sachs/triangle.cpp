/*
 * Name: Jean Pascal Cyusa Shyaka
 * Date: March 31st, 2024
 * Goldman Sachs Coding Challenge
 * Triangle Problem
 *
 * A triangle formed by the three points a (x1, y1, b(x2,y2) and (x3,y3) is a
 * non degenerate triangle if the following rules are respected:
    |ab| + |bc| > |ac|
    |bc| + |ad| > |ab|
    |ab| + |ac| > |bc|

 * A point belongs to a triangle if it lies somewhere on or inside the triangle
 * Given two points p= (xp, yp) and q = (xq,yq), return the correct scenario
 * number:
    0 If the triangle does not form a valid non-degerate triangle.
    1 if point p belongs but q does not
    2 if q belongs but p does not
    3 If both P and q belong
    4 If neither p nor q belong to the triangle.

* Complete the function:
* int pointBelong (int x1, int y1, int x2, int y2, int x3, int y3, int xp,
    int yp, int xq, int yq)
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// check if a point belongs to a triangle
bool pointBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xq, int yq) {
    double A = 0.5 * abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    double A1 = 0.5 * abs((x1 * (y2 - yq) + x2 * (yq - y1) + xq * (y1 - y2)));
    double A2 = 0.5 * abs((x1 * (yq - y3) + xq * (y3 - y1) + x3 * (y1 - yq)));
    double A3 = 0.5 * abs((xq * (y2 - y3) + x2 * (y3 - yq) + x3 * (yq - y2)));
    return A == A1 + A2 + A3;
}

// check id is degenerate
bool isDegenerate(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) > distance(x1, y1, x3, y3) &&
           distance(x2, y2, x3, y3) + distance(x1, y1, x4, y4) > distance(x1, y1, x2, y2) &&
           distance(x1, y1, x2, y2) + distance(x1, y1, x3, y3) > distance(x2, y2, x3, y3);
}

int pointBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp,
                int xq, int yq) {
    // triangle does not form a valid non-degerate triangle
    if (!isDegenerate(x1, y1, x2, y2, x3, y3, xq, yq)) {
        return 0;
    }
    // else of p belongs but q does not
    else if (pointBelong(x1, y1, x2, y2, x3, y3, xq, yq) &&
             !pointBelong(x1, y1, x2, y2, x3, y3, xp, yp)) {
        return 1;
    }
    // else of q belongs but p does not
    else if (!pointBelong(x1, y1, x2, y2, x3, y3, xq, yq) &&
             pointBelong(x1, y1, x2, y2, x3, y3, xp, yp)) {
        return 2;
    }
    // else of both belong
    else if (pointBelong(x1, y1, x2, y2, x3, y3, xq, yq) &&
             pointBelong(x1, y1, x2, y2, x3, y3, xp, yp)) {
        return 3;
    }
    // else of neither belong
    else {
        return 4;
    }
}

int main(int argc, char* argv[]) {
    // Read input from file
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>"
                  << std::endl;
        EXIT_FAILURE;
    }

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        EXIT_FAILURE;
    }

    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        int x1, y1, x2, y2, x3, y3, x4, y4, xq, yq;
        iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> xq >> yq;
        output << pointBelong(x1, y1, x2, y2, x3, y3, x4, y4, xq, yq)
               << std::endl;
    }
}