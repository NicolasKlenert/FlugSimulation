/*
 * CallBack.h
 *
 *  Created on: 21.12.2008
 *      Author: st
 */

#ifndef CALLBACK_H_
#define CALLBACK_H_

class CallBack {
public:
	CallBack();
	virtual ~CallBack();
	virtual void update() =0;
};

#endif /* CALLBACK_H_ */
