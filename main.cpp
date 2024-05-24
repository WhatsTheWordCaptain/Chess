#include <iostream>

struct Coordinate {
    int x, y;
};

bool ThreatChecker(Coordinate king, Coordinate rook, Coordinate bishop) {
    // Check for threat from rook
    if (king.x == rook.x || king.y == rook.y) {
        std::cout << "Threat from rook." << std::endl;
        return true;
    }

    // Check for threat from bishop
    int dx = abs(king.x - bishop.x);
    int dy = abs(king.y - bishop.y);
    if (dx == dy) {
        std::cout << "Threat from bishop." << std::endl;
        return true;
    }

    std::cout << "No theat found." << std::endl;
    return false;
}

int main() {
    // coordinates input
    Coordinate king, rook, bishop;

    std::cout << "Input king coordinates (x y): ";
    std::cin >> king.x >> king.y;

    std::cout << "Input rook coordinates(x y): ";
    std::cin >> rook.x >> rook.y;

    std::cout << "Input bishop coordinates(x y): ";
    std::cin >> bishop.x >> bishop.y;

    ThreatChecker(king, rook, bishop);

    return 0;
}
