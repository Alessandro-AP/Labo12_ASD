#include "Taquin.h"
#include <vector>

#ifndef LABO12_ASD_NODE_H
#define LABO12_ASD_NODE_H

// classe Node inspirée de https://code.activestate.com/recipes/577457-a-star-shortest-path-algorithm/

class Node {
	
public:
	Node(Taquin taquin, int level, int priority);
	Node(std::array<int, 9> array);
	Taquin getTaquin();
	int getLevel() const;
	int getPriority() const;
	std::vector<int> getPossibleMoves();
	void updatePriority();
	
private:
	Taquin _taquin; // taquin membre, un des etats du graphe
	int _level; // nombre d'étapes utilisées pour arriver à l'étape actuelle
	int _priority; // priority = level + Manhattan du taquin membre * facteur
	const int manhattanDistance();
	
	
};

bool operator<(const Node &a, const Node &b);

#endif //LABO12_ASD_NODE_H