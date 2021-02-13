/*
 * IErrorHandler.h
 *
 *  Created on: Jul 24, 2020
 *      Author: User
 */

#ifndef INC_IEVENT_H_
#define INC_IEVENT_H_

#include <stdint.h>
#include <stddef.h>
#include "Object.h"

#define EVENT(evt,src,obj) { if(evt) evt->OnEvent(src,obj); }

#define DEFINE_EVENT(t,e)  IEvent<t> *evt##e;
#define IMPLEMENT_EVENT(t,e) void SetEvent##e(IEvent<t> *x) { this->evt##e = x; } \
                             IEvent<t> *GetEvent##e() { return this->evt##e; }

#define EVENT_DEF(type,name,statements)  class name : public IEvent<type> { \
	                                                       public: \
														        virtual void OnEvent(Object *src, type *obj)\
																{\
	                                                    	       statements \
																}\
										 }
template <class T>
class IEvent : public Object
{
public:
	virtual void OnEvent(Object *source, T* obj) = 0;
};




#endif /* INC_IEVENT_H_ */
