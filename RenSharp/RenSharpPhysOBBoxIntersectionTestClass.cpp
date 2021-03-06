/*
Copyright 2020 Neijwiert

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "General.h"
#include "RenSharpPhysOBBoxIntersectionTestClass.h"

RenSharpPhysOBBoxIntersectionTestClass::RenSharpPhysOBBoxIntersectionTestClass(const OBBoxClass &box, int colGroup, int colType, bool enableResultList)
	: PhysOBBoxIntersectionTestClass(box, colGroup, colType, (enableResultList ? &resultList : nullptr)), resultListEnabled(enableResultList)
{

}

MultiListClass<PhysClass> *RenSharpPhysOBBoxIntersectionTestClass::getResultList()
{
	if (resultListEnabled)
	{
		return &resultList;
	}
	else
	{
		return nullptr;
	}
}