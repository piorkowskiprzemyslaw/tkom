/*
 * TokenType.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_


enum class TokenType : int {
	a = 0,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,t,u,w,x,y,z,DOT, TERMINATE,
	CONCATENATION, OR , PLUS, MULTIPLICATION, PARENTHESIS_LEFT, PARENTHESIS_RIGHT,
	WRONG_TYPE
};


#endif /* TOKENTYPE_H_ */
