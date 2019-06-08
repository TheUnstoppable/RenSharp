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

#include "stdafx.h"
#include "MDamageZoneGameObjDef.h"

#include "MVector3.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DamageZoneGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DamageZoneGameObjDef::DamageZoneGameObjDef(IntPtr pointer)
		: BaseGameObjDef(pointer)
	{

	}

	IntPtr DamageZoneGameObjDef::DamageZoneGameObjDefPointer::get()
	{
		return IntPtr(InternalDamageZoneGameObjDefPointer);
	}

	float DamageZoneGameObjDef::DamageRate::get()
	{
		return InternalDamageZoneGameObjDefPointer->DamageRate;
	}

	void DamageZoneGameObjDef::DamageRate::set(float value)
	{
		InternalDamageZoneGameObjDefPointer->DamageRate = value;
	}

	int DamageZoneGameObjDef::DamageWarhead::get()
	{
		return InternalDamageZoneGameObjDefPointer->DamageWarhead;
	}

	void DamageZoneGameObjDef::DamageWarhead::set(int value)
	{
		InternalDamageZoneGameObjDefPointer->DamageWarhead = value;
	}

	Vector3 DamageZoneGameObjDef::Color::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDamageZoneGameObjDefPointer->Color, result);

		return result;
	}

	void DamageZoneGameObjDef::Color::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalDamageZoneGameObjDefPointer->Color);
	}

	::BaseGameObjDef* DamageZoneGameObjDef::InternalBaseGameObjDefPointer::get()
	{
		return InternalDamageZoneGameObjDefPointer;
	}

	::DamageZoneGameObjDef* DamageZoneGameObjDef::InternalDamageZoneGameObjDefPointer::get()
	{
		return reinterpret_cast<::DamageZoneGameObjDef*>(Pointer.ToPointer());
	}
}