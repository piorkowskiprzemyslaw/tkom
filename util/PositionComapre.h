/*
 * PositionComapre.h
 *
 *  Created on: 4 kwi 2014
 *      Author: przemek
 */

#ifndef POSITIONCOMAPRE_H_
#define POSITIONCOMAPRE_H_

#include <memory>
#include <util/Position.h>

struct PositionComapre {
	bool operator() (const std::shared_ptr<Position> lhs, const std::shared_ptr<Position> rhs ) const {
		return (*lhs) < (*rhs);
	}
};

#endif /* POSITIONCOMAPRE_H_ */
