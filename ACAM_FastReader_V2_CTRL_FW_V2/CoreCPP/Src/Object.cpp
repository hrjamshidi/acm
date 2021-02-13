/*
 * Object.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: User
 */

#include "../Inc/Object.h"


bool operator==(const Object& obj1, const Object& obj2)
{
   return obj1.IsEqual(obj2);
}


bool operator!=(const Object& obj1, const Object& obj2)
{
  return !(obj1 == obj2);
}

