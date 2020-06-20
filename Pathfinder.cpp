#include "Pathfinder.h"
#include "Node.h"
#include <queue>
#include <string>

std::string pathFind(const Node startNode) {
	static int index = 0;// index de queue
	static Node currentNode = startNode; // node de départ
	std::string toReturn;
	
	
	std::priority_queue<Node> nodeQueue; // priority queue de nodes
	currentNode.getPossibleMoves(); // liste des mouvements possibles avec la situation de départ
	
	while (!nodeQueue.empty()) {
		currentNode = nodeQueue.top();
		nodeQueue.pop();
		// test de resolution
		if (currentNode.getTaquin().estResolu()) {
			break;
		}
		
	}
	
	
	return toReturn;
}
