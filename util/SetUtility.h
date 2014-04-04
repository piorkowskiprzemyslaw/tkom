/*
 * addSets.h
 *
 *  Created on: 4 kwi 2014
 *      Author: przemek
 */

#ifndef ADDSETS_H_
#define ADDSETS_H_

#include <memory>
#include <set>

#include <util/Position.h>
#include <util/PositionComapre.h>

struct SetUtility {

	/*
	 * Do pierwszego argumentu jest dodwany zbiór reprezentowany przez drugi argument.
	 */
	static void addSets( std::set< std::shared_ptr<Position>, PositionComapre> & lhs, const std::set< std::shared_ptr<Position>, PositionComapre> & rhs){
		for(auto element : rhs){
			lhs.insert(element);
		}
	}
};


#endif /* ADDSETS_H_ */
