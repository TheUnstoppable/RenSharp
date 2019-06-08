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
#include "Mphyscoltest.h"

#include "MPhysClass.h"
#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <physcoltest.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	PhysRayCollisionTestClassRef::PhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreatePhysRayCollisionTestClass1(
			&rayLine,
			static_cast<::Collision_Group_Type>(group),
			static_cast<::Collision_Type>(type)));
	}

	PhysRayCollisionTestClassRef::PhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreatePhysRayCollisionTestClass2(
			&rayLine,
			static_cast<::Collision_Group_Type>(group)));
	}

	PhysRayCollisionTestClassRef::PhysRayCollisionTestClassRef()
	{

	}

	PhysRayCollisionTestClassRef::PhysRayCollisionTestClassRef(IntPtr pointer)
		: RayCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^PhysRayCollisionTestClassRef::CreatePhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew PhysRayCollisionTestClassRef(ray, group, type));
	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^PhysRayCollisionTestClassRef::CreatePhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew PhysRayCollisionTestClassRef(ray, group));
	}

	RayCollisionTestClass ^PhysRayCollisionTestClassRef::ToRayCollisionTestClass()
	{
		return ToPhysRayCollisionTestClass();
	}

	PhysRayCollisionTestClass ^PhysRayCollisionTestClassRef::ToPhysRayCollisionTestClass()
	{
		return gcnew PhysRayCollisionTestClass(this);
	}

	IntPtr PhysRayCollisionTestClassRef::PhysRayCollisionTestClassPointer::get()
	{
		return IntPtr(InternalPhysRayCollisionTestClassPointer);
	}

	IPhysClass ^PhysRayCollisionTestClassRef::CollidedPhysObj::get()
	{
		auto result = InternalPhysRayCollisionTestClassPointer->CollidedPhysObj;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClass(IntPtr(result));
		}
	}

	void PhysRayCollisionTestClassRef::CollidedPhysObj::set(IPhysClass ^value)
	{
		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			InternalPhysRayCollisionTestClassPointer->CollidedPhysObj = nullptr;
		}
		else
		{
			InternalPhysRayCollisionTestClassPointer->CollidedPhysObj = reinterpret_cast<::PhysClass *>(value->PhysClassPointer.ToPointer());
		}
	}

	CollisionGroupType PhysRayCollisionTestClassRef::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysRayCollisionTestClassPointer->CollisionGroup);
	}

	void PhysRayCollisionTestClassRef::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysRayCollisionTestClassPointer->CollisionGroup = static_cast<::Collision_Group_Type>(value);
	}

	bool PhysRayCollisionTestClassRef::CheckStaticObjs::get()
	{
		return InternalPhysRayCollisionTestClassPointer->CheckStaticObjs;
	}

	void PhysRayCollisionTestClassRef::CheckStaticObjs::set(bool value)
	{
		InternalPhysRayCollisionTestClassPointer->CheckStaticObjs = value;
	}

	bool PhysRayCollisionTestClassRef::CheckDynamicObjs::get()
	{
		return InternalPhysRayCollisionTestClassPointer->CheckDynamicObjs;
	}

	void PhysRayCollisionTestClassRef::CheckDynamicObjs::set(bool value)
	{
		InternalPhysRayCollisionTestClassPointer->CheckDynamicObjs = value;
	}

	bool PhysRayCollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyPhysRayCollisionTestClass(InternalPhysRayCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RayCollisionTestClass *PhysRayCollisionTestClassRef::InternalRayCollisionTestClassPointer::get()
	{
		return InternalPhysRayCollisionTestClassPointer;
	}

	::PhysRayCollisionTestClass *PhysRayCollisionTestClassRef::InternalPhysRayCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::PhysRayCollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRenSharpPhysRayCollisionTestClass1(
			&rayLine,
			static_cast<::Collision_Group_Type>(group),
			static_cast<::Collision_Type>(type)));
	}

	RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRenSharpPhysRayCollisionTestClass2(
			&rayLine,
			static_cast<::Collision_Group_Type>(group)));
	}

	RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type)
		: RenSharpPhysRayCollisionTestClass(ray, group, type)
	{
		if (res.HasValue)
		{
			::CastResultStruct resStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resStruct);

			Imports::RenSharpPhysRayCollisionTestClassSetResult(InternalRenSharpPhysRayCollisionTestClassPointer, &resStruct);
		}
	}

	RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, CollisionGroupType group)
		: RenSharpPhysRayCollisionTestClass(ray, group)
	{
		if (res.HasValue)
		{
			::CastResultStruct resStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resStruct);

			Imports::RenSharpPhysRayCollisionTestClassSetResult(InternalRenSharpPhysRayCollisionTestClassPointer, &resStruct);
		}
	}

	RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClass(PhysRayCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(collisionTestClass->Ray, rayLine);

		Pointer = IntPtr(Imports::CreateRenSharpPhysRayCollisionTestClass1(
			&rayLine,
			static_cast<::Collision_Group_Type>(collisionTestClass->CollisionGroup),
			static_cast<::Collision_Type>(collisionTestClass->CollisionType)));

		CollidedPhysObj = collisionTestClass->CollidedPhysObj;
		CheckStaticObjs = collisionTestClass->CheckStaticObjs;
		CheckDynamicObjs = collisionTestClass->CheckDynamicObjs;
		CollidedRenderObj = collisionTestClass->CollidedRenderObj;

		::CastResultStruct castResult;

		CastResultStruct::ManagedToUnmanagedCastResultStruct(collisionTestClass->Result, castResult);

		Imports::RenSharpPhysRayCollisionTestClassSetResult(InternalRenSharpPhysRayCollisionTestClassPointer, &castResult);
	}

	RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClass(IntPtr pointer)
		: PhysRayCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(
		LineSegClass ray,
		CollisionGroupType group,
		RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew RenSharpPhysRayCollisionTestClass(ray, group, type));
	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew RenSharpPhysRayCollisionTestClass(ray, group));
	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res,
		CollisionGroupType group,
		RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew RenSharpPhysRayCollisionTestClass(ray, res, group, type));
	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res,
		CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew RenSharpPhysRayCollisionTestClass(ray, res, group));
	}

	IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(PhysRayCollisionTestClass ^collisionTestClass)
	{
		return gcnew UnmanagedContainer<IPhysRayCollisionTestClass ^>(gcnew RenSharpPhysRayCollisionTestClass(collisionTestClass));
	}

	IntPtr RenSharpPhysRayCollisionTestClass::RenSharpPhysRayCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpPhysRayCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpPhysRayCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpPhysRayCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct res;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, res);

			Imports::RenSharpPhysRayCollisionTestClassSetResult(InternalRenSharpPhysRayCollisionTestClassPointer, &res);
		}
		else
		{
			InternalPhysRayCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpPhysRayCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpPhysRayCollisionTestClass(InternalRenSharpPhysRayCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpPhysRayCollisionTestClass *RenSharpPhysRayCollisionTestClass::InternalRenSharpPhysRayCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpPhysRayCollisionTestClass *>(Pointer.ToPointer());
	}

	PhysRayCollisionTestClass::PhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type)
		: RayCollisionTestClass(ray, type), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysRayCollisionTestClass::PhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group)
		: RayCollisionTestClass(ray, RenSharp::CollisionType::CollisionTypeProjectile), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysRayCollisionTestClass::PhysRayCollisionTestClass(LineSegClass ray, CastResultStruct res, CollisionGroupType group, RenSharp::CollisionType type)
		: RayCollisionTestClass(ray, res, type), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysRayCollisionTestClass::PhysRayCollisionTestClass(LineSegClass ray, CastResultStruct res, CollisionGroupType group)
		: RayCollisionTestClass(ray, res, RenSharp::CollisionType::CollisionTypeProjectile), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysRayCollisionTestClass::PhysRayCollisionTestClass(IPhysRayCollisionTestClass ^collisionTestClass)
		: RayCollisionTestClass(collisionTestClass)
	{
		if (collisionTestClass == nullptr || collisionTestClass->PhysRayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	PhysRayCollisionTestClass::PhysRayCollisionTestClass(PhysRayCollisionTestClass ^collisionTestClass)
		: RayCollisionTestClass(collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	void PhysRayCollisionTestClass::CopyFrom(IPhysRayCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr || collisionTestClass->PhysRayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		RayCollisionTestClass::CopyFrom(collisionTestClass);

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	void PhysRayCollisionTestClass::CopyFrom(PhysRayCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		RayCollisionTestClass::CopyFrom(collisionTestClass);

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	IPhysClass ^PhysRayCollisionTestClass::CollidedPhysObj::get()
	{
		return collidedPhysObj;
	}

	void PhysRayCollisionTestClass::CollidedPhysObj::set(IPhysClass ^value)
	{
		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			collidedPhysObj = nullptr;
		}
		else
		{
			collidedPhysObj = value;
		}
	}

	CollisionGroupType PhysRayCollisionTestClass::CollisionGroup::get()
	{
		return collisionGroup;
	}

	void PhysRayCollisionTestClass::CollisionGroup::set(CollisionGroupType value)
	{
		collisionGroup = value;
	}

	bool PhysRayCollisionTestClass::CheckStaticObjs::get()
	{
		return checkStaticObjs;
	}

	void PhysRayCollisionTestClass::CheckStaticObjs::set(bool value)
	{
		checkStaticObjs = value;
	}

	bool PhysRayCollisionTestClass::CheckDynamicObjs::get()
	{
		return checkDynamicObjs;
	}

	void PhysRayCollisionTestClass::CheckDynamicObjs::set(bool value)
	{
		checkDynamicObjs = value;
	}

	PhysAABoxCollisionTestClassRef::PhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type)
	{
		::AABoxClass boxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreatePhysAABoxCollisionTestClass1(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group),
			static_cast<::Collision_Type>(type)));
	}

	PhysAABoxCollisionTestClassRef::PhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group)
	{
		::AABoxClass boxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreatePhysAABoxCollisionTestClass2(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group)));
	}

	PhysAABoxCollisionTestClassRef::PhysAABoxCollisionTestClassRef()
	{

	}

	PhysAABoxCollisionTestClassRef::PhysAABoxCollisionTestClassRef(IntPtr pointer)
		: AABoxCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^PhysAABoxCollisionTestClassRef::CreatePhysAABoxCollisionTestClassRef(
		AABoxClass box,
		Vector3 move,
		CollisionGroupType group,
		RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew PhysAABoxCollisionTestClassRef(box, move, group, type));
	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^PhysAABoxCollisionTestClassRef::CreatePhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew PhysAABoxCollisionTestClassRef(box, move, group));
	}

	AABoxCollisionTestClass ^PhysAABoxCollisionTestClassRef::ToAABoxCollisionTestClass()
	{
		return ToPhysAABoxCollisionTestClass();
	}

	PhysAABoxCollisionTestClass ^PhysAABoxCollisionTestClassRef::ToPhysAABoxCollisionTestClass()
	{
		return gcnew PhysAABoxCollisionTestClass(this);
	}

	IntPtr PhysAABoxCollisionTestClassRef::PhysAABoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalPhysAABoxCollisionTestClassPointer);
	}

	IPhysClass ^PhysAABoxCollisionTestClassRef::CollidedPhysObj::get()
	{
		auto result = InternalPhysAABoxCollisionTestClassPointer->CollidedPhysObj;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClass(IntPtr(result));
		}
	}

	void PhysAABoxCollisionTestClassRef::CollidedPhysObj::set(IPhysClass ^value)
	{
		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			InternalPhysAABoxCollisionTestClassPointer->CollidedPhysObj = nullptr;
		}
		else
		{
			InternalPhysAABoxCollisionTestClassPointer->CollidedPhysObj = reinterpret_cast<::PhysClass *>(value->PhysClassPointer.ToPointer());
		}
	}

	CollisionGroupType PhysAABoxCollisionTestClassRef::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysAABoxCollisionTestClassPointer->CollisionGroup);
	}

	void PhysAABoxCollisionTestClassRef::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysAABoxCollisionTestClassPointer->CollisionGroup = static_cast<::Collision_Group_Type>(value);
	}

	bool PhysAABoxCollisionTestClassRef::CheckStaticObjs::get()
	{
		return InternalPhysAABoxCollisionTestClassPointer->CheckStaticObjs;
	}

	void PhysAABoxCollisionTestClassRef::CheckStaticObjs::set(bool value)
	{
		InternalPhysAABoxCollisionTestClassPointer->CheckStaticObjs = value;
	}

	bool PhysAABoxCollisionTestClassRef::CheckDynamicObjs::get()
	{
		return InternalPhysAABoxCollisionTestClassPointer->CheckDynamicObjs;
	}

	void PhysAABoxCollisionTestClassRef::CheckDynamicObjs::set(bool value)
	{
		InternalPhysAABoxCollisionTestClassPointer->CheckDynamicObjs = value;
	}

	bool PhysAABoxCollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyPhysAABoxCollisionTestClass(InternalPhysAABoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AABoxCollisionTestClass *PhysAABoxCollisionTestClassRef::InternalAABoxCollisionTestClassPointer::get()
	{
		return InternalPhysAABoxCollisionTestClassPointer;
	}

	::PhysAABoxCollisionTestClass *PhysAABoxCollisionTestClassRef::InternalPhysAABoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::PhysAABoxCollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type)
	{
		::AABoxClass boxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpPhysAABoxCollisionTestClass1(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group),
			static_cast<::Collision_Type>(type)));
	}

	RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group)
	{
		::AABoxClass boxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpPhysAABoxCollisionTestClass2(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group)));
	}

	RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type)
		: RenSharpPhysAABoxCollisionTestClass(box, move, group, type)
	{
		if (res.HasValue)
		{
			::CastResultStruct castResult;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castResult);

			Imports::RenSharpPhysAABoxCollisionTestClassSetResult(InternalRenSharpPhysAABoxCollisionTestClassPointer, &castResult);
		}
	}

	RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group)
		: RenSharpPhysAABoxCollisionTestClass(box, move, group)
	{
		if (res.HasValue)
		{
			::CastResultStruct castResult;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castResult);

			Imports::RenSharpPhysAABoxCollisionTestClassSetResult(InternalRenSharpPhysAABoxCollisionTestClassPointer, &castResult);
		}
	}

	RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		::AABoxClass boxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(collisionTestClass->Box, boxBox);
		Vector3::ManagedToUnmanagedVector3(collisionTestClass->Move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpPhysAABoxCollisionTestClass1(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(collisionTestClass->CollisionGroup),
			static_cast<::Collision_Type>(collisionTestClass->CollisionType)));

		CollidedPhysObj = collisionTestClass->CollidedPhysObj;
		CheckStaticObjs = collisionTestClass->CheckStaticObjs;
		CheckDynamicObjs = collisionTestClass->CheckDynamicObjs;
		SweepMin = collisionTestClass->SweepMin;
		SweepMax = collisionTestClass->SweepMax;
		CollidedRenderObj = collisionTestClass->CollidedRenderObj;

		::CastResultStruct castResult;

		CastResultStruct::ManagedToUnmanagedCastResultStruct(collisionTestClass->Result, castResult);

		Imports::RenSharpPhysAABoxCollisionTestClassSetResult(InternalRenSharpPhysAABoxCollisionTestClassPointer, &castResult);
	}

	RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClass(IntPtr pointer)
		: PhysAABoxCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(
		AABoxClass box,
		Vector3 move,
		CollisionGroupType group,
		RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew RenSharpPhysAABoxCollisionTestClass(box, move, group, type));
	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(
		AABoxClass box,
		Vector3 move,
		CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew RenSharpPhysAABoxCollisionTestClass(box, move, group));
	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(
		AABoxClass box,
		Vector3 move,
		Nullable<CastResultStruct> res,
		CollisionGroupType group, RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew RenSharpPhysAABoxCollisionTestClass(box, move, res, group, type));
	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(
		AABoxClass box,
		Vector3 move,
		Nullable<CastResultStruct> res,
		CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew RenSharpPhysAABoxCollisionTestClass(box, move, res, group));
	}

	IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass ^collisionTestClass)
	{
		return gcnew UnmanagedContainer<IPhysAABoxCollisionTestClass ^>(gcnew RenSharpPhysAABoxCollisionTestClass(collisionTestClass));
	}

	IntPtr RenSharpPhysAABoxCollisionTestClass::RenSharpPhysAABoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpPhysAABoxCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpPhysAABoxCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpPhysAABoxCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct res;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, res);

			Imports::RenSharpPhysAABoxCollisionTestClassSetResult(InternalRenSharpPhysAABoxCollisionTestClassPointer, &res);
		}
		else
		{
			InternalPhysAABoxCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpPhysAABoxCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpPhysAABoxCollisionTestClass(InternalRenSharpPhysAABoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpPhysAABoxCollisionTestClass *RenSharpPhysAABoxCollisionTestClass::InternalRenSharpPhysAABoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpPhysAABoxCollisionTestClass *>(Pointer.ToPointer());
	}

	PhysAABoxCollisionTestClass::PhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type)
		: AABoxCollisionTestClass(box, move, type), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysAABoxCollisionTestClass::PhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group)
		: AABoxCollisionTestClass(box, move, RenSharp::CollisionType::CollisionTypePhysical), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysAABoxCollisionTestClass::PhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CastResultStruct res, CollisionGroupType group, RenSharp::CollisionType type)
		: AABoxCollisionTestClass(box, move, res, type), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{
		
	}

	PhysAABoxCollisionTestClass::PhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CastResultStruct res, CollisionGroupType group)
		: AABoxCollisionTestClass(box, move, res, RenSharp::CollisionType::CollisionTypePhysical), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysAABoxCollisionTestClass::PhysAABoxCollisionTestClass(IPhysAABoxCollisionTestClass ^collisionTestClass)
		: AABoxCollisionTestClass(collisionTestClass)
	{
		if (collisionTestClass == nullptr || collisionTestClass->PhysAABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	PhysAABoxCollisionTestClass::PhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass ^collisionTestClass)
		: AABoxCollisionTestClass(collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	void PhysAABoxCollisionTestClass::CopyFrom(IPhysAABoxCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr || collisionTestClass->PhysAABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		AABoxCollisionTestClass::CopyFrom(collisionTestClass);

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	void PhysAABoxCollisionTestClass::CopyFrom(PhysAABoxCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		AABoxCollisionTestClass::CopyFrom(collisionTestClass);

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	IPhysClass ^PhysAABoxCollisionTestClass::CollidedPhysObj::get()
	{
		return collidedPhysObj;
	}

	void PhysAABoxCollisionTestClass::CollidedPhysObj::set(IPhysClass ^value)
	{
		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			collidedPhysObj = nullptr;
		}
		else
		{
			collidedPhysObj = value;
		}
	}

	CollisionGroupType PhysAABoxCollisionTestClass::CollisionGroup::get()
	{
		return collisionGroup;
	}

	void PhysAABoxCollisionTestClass::CollisionGroup::set(CollisionGroupType value)
	{
		collisionGroup = value;
	}

	bool PhysAABoxCollisionTestClass::CheckStaticObjs::get()
	{
		return checkStaticObjs;
	}

	void PhysAABoxCollisionTestClass::CheckStaticObjs::set(bool value)
	{
		checkStaticObjs = value;
	}

	bool PhysAABoxCollisionTestClass::CheckDynamicObjs::get()
	{
		return checkDynamicObjs;
	}

	void PhysAABoxCollisionTestClass::CheckDynamicObjs::set(bool value)
	{
		checkDynamicObjs = value;
	}

	PhysOBBoxCollisionTestClassRef::PhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type)
	{
		::OBBoxClass boxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreatePhysOBBoxCollisionTestClass1(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group),
			static_cast<::Collision_Type>(type)));
	}

	PhysOBBoxCollisionTestClassRef::PhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group)
	{
		::OBBoxClass boxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreatePhysOBBoxCollisionTestClass2(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group)));
	}

	PhysOBBoxCollisionTestClassRef::PhysOBBoxCollisionTestClassRef()
	{

	}

	PhysOBBoxCollisionTestClassRef::PhysOBBoxCollisionTestClassRef(IntPtr pointer)
		: OBBoxCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^PhysOBBoxCollisionTestClassRef::CreatePhysOBBoxCollisionTestClassRef(
		OBBoxClass box,
		Vector3 move,
		CollisionGroupType group,
		RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew PhysOBBoxCollisionTestClassRef(box, move, group, type));
	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^PhysOBBoxCollisionTestClassRef::CreatePhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew PhysOBBoxCollisionTestClassRef(box, move, group));
	}

	OBBoxCollisionTestClass ^PhysOBBoxCollisionTestClassRef::ToOBBoxCollisionTestClass()
	{
		return ToPhysOBBoxCollisionTestClass();
	}

	PhysOBBoxCollisionTestClass ^PhysOBBoxCollisionTestClassRef::ToPhysOBBoxCollisionTestClass()
	{
		return gcnew PhysOBBoxCollisionTestClass(this);
	}

	IntPtr PhysOBBoxCollisionTestClassRef::PhysOBBoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalPhysOBBoxCollisionTestClassPointer);
	}

	IPhysClass ^PhysOBBoxCollisionTestClassRef::CollidedPhysObj::get()
	{
		auto result = InternalPhysOBBoxCollisionTestClassPointer->CollidedPhysObj;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClass(IntPtr(result));
		}
	}

	void PhysOBBoxCollisionTestClassRef::CollidedPhysObj::set(IPhysClass ^value)
	{
		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			InternalPhysOBBoxCollisionTestClassPointer->CollidedPhysObj = nullptr;
		}
		else
		{
			InternalPhysOBBoxCollisionTestClassPointer->CollidedPhysObj = reinterpret_cast<::PhysClass *>(value->PhysClassPointer.ToPointer());
		}
	}

	CollisionGroupType PhysOBBoxCollisionTestClassRef::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysOBBoxCollisionTestClassPointer->CollisionGroup);
	}

	void PhysOBBoxCollisionTestClassRef::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysOBBoxCollisionTestClassPointer->CollisionGroup = static_cast<::Collision_Group_Type>(value);
	}

	bool PhysOBBoxCollisionTestClassRef::CheckStaticObjs::get()
	{
		return InternalPhysOBBoxCollisionTestClassPointer->CheckStaticObjs;
	}

	void PhysOBBoxCollisionTestClassRef::CheckStaticObjs::set(bool value)
	{
		InternalPhysOBBoxCollisionTestClassPointer->CheckStaticObjs = value;
	}

	bool PhysOBBoxCollisionTestClassRef::CheckDynamicObjs::get()
	{
		return InternalPhysOBBoxCollisionTestClassPointer->CheckDynamicObjs;
	}

	void PhysOBBoxCollisionTestClassRef::CheckDynamicObjs::set(bool value)
	{
		InternalPhysOBBoxCollisionTestClassPointer->CheckDynamicObjs = value;
	}

	bool PhysOBBoxCollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyPhysOBBoxCollisionTestClass(InternalPhysOBBoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::OBBoxCollisionTestClass *PhysOBBoxCollisionTestClassRef::InternalOBBoxCollisionTestClassPointer::get()
	{
		return InternalPhysOBBoxCollisionTestClassPointer;
	}

	::PhysOBBoxCollisionTestClass *PhysOBBoxCollisionTestClassRef::InternalPhysOBBoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::PhysOBBoxCollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type)
	{
		::OBBoxClass boxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpPhysOBBoxCollisionTestClass1(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group),
			static_cast<::Collision_Type>(type)));
	}

	RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group)
	{
		::OBBoxClass boxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpPhysOBBoxCollisionTestClass2(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(group)));
	}

	RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type)
		: RenSharpPhysOBBoxCollisionTestClass(box, move, group, type)
	{
		if (res.HasValue)
		{
			::CastResultStruct castResult;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castResult);

			Imports::RenSharpPhysOBBoxCollisionTestClassSetResult(InternalRenSharpPhysOBBoxCollisionTestClassPointer, &castResult);
		}
	}

	RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group)
		: RenSharpPhysOBBoxCollisionTestClass(box, move, group)
	{
		if (res.HasValue)
		{
			::CastResultStruct castResult;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castResult);

			Imports::RenSharpPhysOBBoxCollisionTestClassSetResult(InternalRenSharpPhysOBBoxCollisionTestClassPointer, &castResult);
		}
	}

	RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		::OBBoxClass boxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(collisionTestClass->Box, boxBox);
		Vector3::ManagedToUnmanagedVector3(collisionTestClass->Move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpPhysOBBoxCollisionTestClass1(
			&boxBox,
			&moveVec,
			static_cast<::Collision_Group_Type>(collisionTestClass->CollisionGroup),
			static_cast<::Collision_Type>(collisionTestClass->CollisionType)));

		CollidedPhysObj = collisionTestClass->CollidedPhysObj;
		CheckStaticObjs = collisionTestClass->CheckStaticObjs;
		CheckDynamicObjs = collisionTestClass->CheckDynamicObjs;
		SweepMin = collisionTestClass->SweepMin;
		SweepMax = collisionTestClass->SweepMax;
		CollidedRenderObj = collisionTestClass->CollidedRenderObj;

		::CastResultStruct castResult;

		CastResultStruct::ManagedToUnmanagedCastResultStruct(collisionTestClass->Result, castResult);

		Imports::RenSharpPhysOBBoxCollisionTestClassSetResult(InternalRenSharpPhysOBBoxCollisionTestClassPointer, &castResult);
	}

	RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClass(IntPtr pointer)
		: PhysOBBoxCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(
		OBBoxClass box,
		Vector3 move,
		CollisionGroupType group,
		RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew RenSharpPhysOBBoxCollisionTestClass(box, move, group, type));
	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(
		OBBoxClass box,
		Vector3 move,
		CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew RenSharpPhysOBBoxCollisionTestClass(box, move, group));
	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(
		OBBoxClass box,
		Vector3 move,
		Nullable<CastResultStruct> res,
		CollisionGroupType group, RenSharp::CollisionType type)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew RenSharpPhysOBBoxCollisionTestClass(box, move, res, group, type));
	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(
		OBBoxClass box,
		Vector3 move,
		Nullable<CastResultStruct> res,
		CollisionGroupType group)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew RenSharpPhysOBBoxCollisionTestClass(box, move, res, group));
	}

	IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass ^collisionTestClass)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxCollisionTestClass ^>(gcnew RenSharpPhysOBBoxCollisionTestClass(collisionTestClass));
	}

	IntPtr RenSharpPhysOBBoxCollisionTestClass::RenSharpPhysOBBoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpPhysOBBoxCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpPhysOBBoxCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpPhysOBBoxCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct res;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, res);

			Imports::RenSharpPhysOBBoxCollisionTestClassSetResult(InternalRenSharpPhysOBBoxCollisionTestClassPointer, &res);
		}
		else
		{
			InternalPhysOBBoxCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpPhysOBBoxCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpPhysOBBoxCollisionTestClass(InternalRenSharpPhysOBBoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpPhysOBBoxCollisionTestClass *RenSharpPhysOBBoxCollisionTestClass::InternalRenSharpPhysOBBoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpPhysOBBoxCollisionTestClass *>(Pointer.ToPointer());
	}

	PhysOBBoxCollisionTestClass::PhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type)
		: OBBoxCollisionTestClass(box, move, type), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysOBBoxCollisionTestClass::PhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group)
		: OBBoxCollisionTestClass(box, move, RenSharp::CollisionType::CollisionTypePhysical), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysOBBoxCollisionTestClass::PhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CastResultStruct res, CollisionGroupType group, RenSharp::CollisionType type)
		: OBBoxCollisionTestClass(box, move, res, type), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysOBBoxCollisionTestClass::PhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CastResultStruct res, CollisionGroupType group)
		: OBBoxCollisionTestClass(box, move, res, RenSharp::CollisionType::CollisionTypePhysical), collidedPhysObj(nullptr), collisionGroup(group), checkStaticObjs(true), checkDynamicObjs(true)
	{

	}

	PhysOBBoxCollisionTestClass::PhysOBBoxCollisionTestClass(IPhysOBBoxCollisionTestClass ^collisionTestClass)
		: OBBoxCollisionTestClass(collisionTestClass)
	{
		if (collisionTestClass == nullptr || collisionTestClass->PhysOBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	PhysOBBoxCollisionTestClass::PhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass ^collisionTestClass)
		: OBBoxCollisionTestClass(collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	void PhysOBBoxCollisionTestClass::CopyFrom(IPhysOBBoxCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr || collisionTestClass->PhysOBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		OBBoxCollisionTestClass::CopyFrom(collisionTestClass);

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	void PhysOBBoxCollisionTestClass::CopyFrom(PhysOBBoxCollisionTestClass ^collisionTestClass)
	{
		if (collisionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("collisionTestClass");
		}

		OBBoxCollisionTestClass::CopyFrom(collisionTestClass);

		collidedPhysObj = collisionTestClass->CollidedPhysObj;
		collisionGroup = collisionTestClass->CollisionGroup;
		checkStaticObjs = collisionTestClass->CheckStaticObjs;
		checkDynamicObjs = collisionTestClass->CheckDynamicObjs;
	}

	IPhysClass ^PhysOBBoxCollisionTestClass::CollidedPhysObj::get()
	{
		return collidedPhysObj;
	}

	void PhysOBBoxCollisionTestClass::CollidedPhysObj::set(IPhysClass ^value)
	{
		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			collidedPhysObj = nullptr;
		}
		else
		{
			collidedPhysObj = value;
		}
	}

	CollisionGroupType PhysOBBoxCollisionTestClass::CollisionGroup::get()
	{
		return collisionGroup;
	}

	void PhysOBBoxCollisionTestClass::CollisionGroup::set(CollisionGroupType value)
	{
		collisionGroup = value;
	}

	bool PhysOBBoxCollisionTestClass::CheckStaticObjs::get()
	{
		return checkStaticObjs;
	}

	void PhysOBBoxCollisionTestClass::CheckStaticObjs::set(bool value)
	{
		checkStaticObjs = value;
	}

	bool PhysOBBoxCollisionTestClass::CheckDynamicObjs::get()
	{
		return checkDynamicObjs;
	}

	void PhysOBBoxCollisionTestClass::CheckDynamicObjs::set(bool value)
	{
		checkDynamicObjs = value;
	}
}