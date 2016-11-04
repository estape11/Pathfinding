#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <string>

using namespace std;

const int n=20; // horizontal size of the map
const int m=11; // vertical size size of the map
static int Map[n][m];
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir=8; // number of possible directions to go at any position
// if dir==4
//static int dx[dir]={1, 0, -1, 0};
//static int dy[dir]={0, 1, 0, -1};
// if dir==8
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

class Node{
private:
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority
public:
    Node(int xp, int yp, int d, int p);
    int getxPos() const ;
    int getyPos() const ;
    int getLevel() const ;
    int getPriority() const ;
    void updatePriority(const int & xDest, const int & yDest);
    // give better priority to going strait instead of diagonally
    void nextLevel(const int & i);
    // Estimation function for the remaining distance to the goal.
    const int & estimate(const int & xDest, const int & yDest) const;
    bool operator<(const Node& a) const;
};

#endif // NODE_H
