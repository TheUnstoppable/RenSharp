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

#include "MPhysDefClass.h"

#pragma managed(push, off)

class StaticPhysDefClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IStaticPhysDefClass : public IPhysDefClass
	{
		literal unsigned int StaticPhysDefClassClassID = 36871;
		literal String^ StaticPhysDefClassTypeName = "StaticPhysDef";

		property IntPtr StaticPhysDefClassPointer
		{
			IntPtr get();
		}
	};

	public ref class StaticPhysDefClass : public PhysDefClass, public IStaticPhysDefClass
	{
		public:
			StaticPhysDefClass(IntPtr pointer);

			property IntPtr StaticPhysDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::PhysDefClass *InternalPhysDefClassPointer
			{
				::PhysDefClass *get() override;
			}

			property ::StaticPhysDefClass *InternalStaticPhysDefClassPointer
			{
				virtual ::StaticPhysDefClass *get();
			}

			property bool IsNonOccluder
			{
				bool get();
				void set(bool value);
			}

			property char CollisionGroup
			{
				char get();
				void set(char value);
			}

			property char VisibilityMode
			{
				char get();
				void set(char value);
			}
	};
}