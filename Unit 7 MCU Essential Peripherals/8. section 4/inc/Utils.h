/*
 * Utils.h
 *
 * Created: 9/5/2022 7:42:01 PM
 *  Author: Ahmed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg, bit)		( reg |= ( 1 << (bit) ) )
#define CLEAR_BIT(reg, bit)		( reg &= ~( 1 << (bit) ) )
#define TOGGLE_BIT(reg, bit)		( reg ^= ( 1 << (bit) ) )
#define READ_BIT(reg, bit)		( ( reg >> (bit) ) & 1 )

#define WRITE_REG_POS(reg, mask, pos, val)	(reg &= ~((mask) << (pos))); \
											(reg |= ((val) << (pos)))

#define WRITE_REG(reg, mask, val)			(reg &= ~(mask));\
											(reg |= (mask))
											
#define CLEAR_REG(reg, mask)				(reg &= ~(mask))
#define SET_REG(reg, mask)					(reg |= (mask))

#define READ_REG_POS(reg, mask, pos)		(( reg >> (pos) ) & (mask))

#define READ_REG(reg, mask)					(reg & (mask))


#endif /* UTILS_H_ */
