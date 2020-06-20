#include "Pathfinder.h"
#include "Node.h"
#include <queue>
#include <string>

std::string pathFind(const Node startNode) {
	static int index = 0;// index de queue
	static node* startNode; // node de départ
	
	std::priority_queue<Node> nodeQueue; // priority queue de nodes
	std::vector<int> startNode->getPossibleMoves(); // liste des mouvements possibles avec la situation de départ
	
	
}