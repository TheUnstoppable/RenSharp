/*
Copyright 2019 Neijwiert

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

#pragma once

#include "MBuildingGameObjDef.h"

#pragma managed(push, off)

class SoldierFactoryGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISoldierFactoryGameObjDef : public IBuildingGameObjDef
	{
		property IntPtr SoldierFactoryGameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class SoldierFactoryGameObjDef : public BuildingGameObjDef, public ISoldierFactoryGameObjDef
	{
		public:
			SoldierFactoryGameObjDef(IntPtr pointer);

			property IntPtr SoldierFactoryGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::SoldierFactoryGameObjDef *InternalSoldierFactoryGameObjDefPointer
			{
				virtual ::SoldierFactoryGameObjDef *get();
			}
	};
}