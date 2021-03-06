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

#include "stdafx.h"
#include "MAirFactoryGameObj.h"

#include "MAirFactoryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <AirFactoryGameObj.h>
#include <AirFactoryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	AirFactoryGameObj::AirFactoryGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IntPtr AirFactoryGameObj::AirFactoryGameObjPointer::get()
	{
		return IntPtr(InternalAirFactoryGameObjPointer);
	}

	IAirFactoryGameObjDef ^AirFactoryGameObj::Definition::get()
	{
		return safe_cast<IAirFactoryGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalAirFactoryGameObjPointer->Get_Definition()));
	}

	bool AirFactoryGameObj::IsAvailable::get()
	{
		return InternalAirFactoryGameObjPointer->Is_Available();
	}

	bool AirFactoryGameObj::IsBusy::get()
	{
		return InternalAirFactoryGameObjPointer->Is_Busy();
	}

	void AirFactoryGameObj::IsBusy::set(bool value)
	{
		InternalAirFactoryGameObjPointer->Set_Busy(value);
	}

	bool AirFactoryGameObj::IsDisabled::get()
	{
		return InternalAirFactoryGameObjPointer->Is_Disabled();
	}

	void AirFactoryGameObj::IsDisabled::set(bool value)
	{
		InternalAirFactoryGameObjPointer->Set_Disabled(value);
	}

	::PhysObserverClass *AirFactoryGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalAirFactoryGameObjPointer;
	}

	::CombatPhysObserverClass *AirFactoryGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalAirFactoryGameObjPointer;
	}

	::BuildingGameObj *AirFactoryGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalAirFactoryGameObjPointer;
	}

	::AirFactoryGameObj *AirFactoryGameObj::InternalAirFactoryGameObjPointer::get()
	{
		return reinterpret_cast<::AirFactoryGameObj *>(Pointer.ToPointer());
	}
}