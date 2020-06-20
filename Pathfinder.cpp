#include "Pathfinder.h"
#include "Node.h"
#include "Taquin.h"
#include <queue>
#include <string>
#include <iostream>

std::string pathFind(const Node startNode) {
	static int index = 0;// index de queue
	Node currentNode = startNode; // node de départ
	std::string toReturn = "";

	
	std::priority_queue<Node> nodeQueue; // priority queue de nodes
	nodeQueue.push(startNode);


	do {
		currentNode = nodeQueue.top();
		nodeQueue.pop();
		std::vector<int> nextMoves = currentNode.getPossibleMoves(); // liste des mouvements possibles avec la situation actuelle
		
		// generation de toutes les possibilites suivantes et adjonction dnas la nodeQueue
		for (int i = 0; i < nextMoves.size(); ++i) {
			std::vector<int> tempPreviousMoves = currentNode.getPreviousMoves(); // copie de liste de mouvements precedents de la node actuelle
			tempPreviousMoves.push_back(nextMoves[i]); // adjonction du dernier mouvement a la copie de liste
			Taquin tempTaquin = currentNode.getTaquin(); // copie du taquin actuel
			Piece tempPiece = tempTaquin.trouvePiece(0);
			tempTaquin.swapPiece(tempPiece, nextMoves[i]); // modification de la copie
			nodeQueue.push((Node){tempTaquin, currentNode.getLevel()+1, tempPreviousMoves}); // construction et adjonction de la nouvelle node dans la nodeQueue
		}
		
		// test de resolution
		if (currentNode.getTaquin().estResolu()) {
			std::cout << "Solution la plus courte: ";
			while (!nodeQueue.empty()) {
				nodeQueue.pop(); // destruction de toutes les nodes restantes, garbage collection
			}
			for (int i = 0; i < currentNode.getPreviousMoves().size(); ++i) {
				std::cout << currentNode.getPreviousMoves()[i] << " "; // display
			}
		}
		
	} while (!nodeQueue.empty()); // infinite loop guard
	
	
	return toReturn;
}
