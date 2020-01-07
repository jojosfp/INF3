/*
 * STRATEGY.H
 *
 *  Created on: 07.01.2020
 *      Author: JojoDPC
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

class IStrategy{

public:

	virtual void strat() = 0;

protected:

private:

};


class StrategyOne : public IStrategy{

public:

	virtual void strat();

protected:

private:

};


#endif /* STRATEGY_H_ */
