/*
 * STRATEGY.H
 *
 *  Created on: 07.01.2020
 *      Author: JojoDPC
 */

/**
 * \file	STRATEGY.H
 *
 * \brief	definition for the Strategy of Battleships.
 *
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

/**
 *  \class	IStrategy
 *
 *  \brief	The interface-class for the strategies.
 *
 */

class IStrategy{

public:

	virtual void strat() = 0;

protected:

private:

};

/**
 * \class	StrategyOne
 *
 * \brief	Contains one solving strategy for Battleships.
 *
 */

class StrategyOne : public IStrategy{

public:

	/**
	 *\brief	Implements the solving strategy by linear shooting each row.
	 *			From left to right and up to down.
	 *
	 */

	virtual void strat();

protected:

private:

};

/**
 * \class	StrategyOne
 *
 * \brief	Contains a second solving strategy for Battleships
 *
 */

class StrategyTwo : public IStrategy{

public:

	/**
	 *\brief	Implements the solving strategy with random shoots with a memory function.
	 *
	 */

	virtual void strat();

protected:

private:

};

#endif /* STRATEGY_H_ */
