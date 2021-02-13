/*
 * IObject.h
 *
 *  Created on: Jul 24, 2020
 *      Author: User
 */

#ifndef INC_OBJECT_H_
#define INC_OBJECT_H_

#include <string>
#include <typeinfo>
#include <stdint.h>


class Object
{
public:
	virtual bool IsEqual(const Object& obj) const
	{
		return typeid(obj) == typeid(this) &&
			   obj.GetHashCode() == this->GetHashCode();
	}
	
	
	virtual uint32_t GetHashCode() const
	{
		return typeid(this).hash_code();
	}
	
	
	virtual std::string ToString() const
	{
		return   std::string(typeid(this).name()) +  "@" + std::to_string(*((uint32_t*)this));
	}
	
	friend bool operator==(const Object& obj1, const Object& obj2);
	friend bool operator!=(const Object& obj1, const Object& obj2);
};



#endif /* INC_OBJECT_H_ */
