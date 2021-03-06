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

#pragma once

#include "MDynamicPhysDefClass.h"

#pragma managed(push, off)

class DecorationPhysDefClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDecorationPhysDefClass : public IDynamicPhysDefClass
	{
		literal unsigned int DecorationPhysDefClassClassID = 36864;
		literal String^ DecorationPhysDefClassTypeName = "DecorationPhysDef";

		property IntPtr DecorationPhysDefClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DecorationPhysDefClass : public DynamicPhysDefClass, public IDecorationPhysDefClass
	{
		public:
			DecorationPhysDefClass(IntPtr pointer);

			property IntPtr DecorationPhysDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DynamicPhysDefClass *InternalDynamicPhysDefClassPointer
			{
				::DynamicPhysDefClass *get() override;
			}

			property ::DecorationPhysDefClass *InternalDecorationPhysDefClassPointer
			{
				virtual ::DecorationPhysDefClass *get();
			}
	};
}