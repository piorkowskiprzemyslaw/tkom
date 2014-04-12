/*
 * TreePresentation.cpp
 *
 *  Created on: 11 kwi 2014
 *      Author: przemek
 */

#include <syntax/TreePresentation.h>

TreePresentation::TreePresentation(const std::shared_ptr<Tree> tree) {
	this->tree = tree;
	this->height = tree->getRoot()->height();
	graph = ogdf::Graph();
	ga = ogdf::GraphAttributes(graph, ogdf::GraphAttributes::nodeGraphics | ogdf::GraphAttributes::edgeGraphics |
			ogdf::GraphAttributes::nodeLabel | ogdf::GraphAttributes::nodeColor |
			ogdf::GraphAttributes::edgeColor | ogdf::GraphAttributes::edgeStyle |
			ogdf::GraphAttributes::nodeStyle | ogdf::GraphAttributes::nodeTemplate );

}

TreePresentation::~TreePresentation() { }

/*
 * Przygotowuje reprezentacje drzewa.
 */
void TreePresentation::createGraph() {
	tree->getRoot()->createTreeReprezentation(graph, ga, nullptr);
}

/*
 * Dodaje layout.
 */
void TreePresentation::addLayout() {
    ogdf::SugiyamaLayout SL;
    SL.setRanking(new ogdf::OptimalRanking);
    SL.setCrossMin(new ogdf::MedianHeuristic);

    ogdf::OptimalHierarchyLayout *ohl = new ogdf::OptimalHierarchyLayout;
    ohl->layerDistance(30.0);
    ohl->nodeDistance(55.0);
    ohl->weightBalancing(0.8);
    SL.setLayout(ohl);

    SL.call(ga);
    ga.writeGML("tree.gml");
}

/*
 * Pokazuje drzewo.
 */
void TreePresentation::show() {
	// czyszczenie po porzednich wywyołaniach.
	system("rm tree.gml");
	system("rm tree.png");

	createGraph();
	addLayout();

    system("gml2pic tree.gml");
    system("eog tree.png &");
}
