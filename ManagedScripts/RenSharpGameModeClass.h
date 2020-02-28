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

#include "IUnmanagedAttachable.h"
#include "Mda_gamemode.h"

#pragma managed(push, off)

class DAGameModeClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IRenSharpGameModeFactoryClass;

	public interface class IRenSharpGameModeClass : public IUnmanagedAttachable<IDAGameModeClass^>
	{
		void Init();

		property IntPtr DAGameModeClassPointer
		{
			IntPtr get();
		}

		property String^ LongName
		{
			String^ get();
		}

		property String^ ShortName
		{
			String^ get();
		}

		property IDAGameModeFactoryClass^ Factory
		{
			IDAGameModeFactoryClass^ get();
			void set(IDAGameModeFactoryClass^ value);
		}
	};

	public ref class RenSharpGameModeClass abstract : public IRenSharpGameModeClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daGameModeClassPointer;
			IDAGameModeClass^ daGameModeClass;

		public:
			RenSharpGameModeClass();
			~RenSharpGameModeClass();
			!RenSharpGameModeClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void InitUnmanagedAttachable() sealed;
			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual IDAGameModeClass^ AsUnmanagedObject() sealed;

			virtual void Init();

			property IntPtr DAGameModeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsAttached
			{
				virtual bool get() sealed;
			}

			property bool IsRegistered
			{
				virtual bool get() sealed;
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String^ LongName
			{
				virtual String^ get() sealed;
			}

			property String^ ShortName
			{
				virtual String^ get() sealed;
			}

			property IDAGameModeFactoryClass^ Factory
			{
				virtual IDAGameModeFactoryClass^ get() sealed;
				virtual void set(IDAGameModeFactoryClass^ value) sealed;
			}

		protected:
			property ::DAGameModeClass* InternalDAGameModeClassPointer
			{
				virtual ::DAGameModeClass* get();
			}
	};
}