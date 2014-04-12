/*
 * TreePresentation.h
 *
 *  Created on: 11 kwi 2014
 *      Author: przemek
 */

#ifndef TREEPRESENTATION_H_
#define TREEPRESENTATION_H_

#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/layered/SugiyamaLayout.h>
#include <ogdf/layered/MedianHeuristic.h>
#include <ogdf/layered/OptimalRanking.h>
#include <ogdf/layered/OptimalHierarchyLayout.h>
#include <ogdf/tree/TreeLayout.h>

#include <syntax/Tree.h>

#include <memory>
#include <vector>

class TreePresentation {
private:
	std::shared_ptr<Tree> tree;
	unsigned int height;
	ogdf::Graph graph;
	ogdf::GraphAttributes ga;
	std::vector<int> rank;


	void createGraph();
	void addLayout();
public:
	TreePresentation(const std::shared_ptr<Tree> tree);
	~TreePresentation();
	void show();
};

#endif /* TREEPRESENTATION_H_ */
