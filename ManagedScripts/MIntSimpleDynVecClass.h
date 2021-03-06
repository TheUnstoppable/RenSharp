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

#include "Mengine_vector.h"

namespace RenSharp
{
	public ref class IntSimpleDynVecClass : public SimpleDynVecClass<int>
	{
		private:
			IntSimpleDynVecClass();
			IntSimpleDynVecClass(int size);

		public:
			IntSimpleDynVecClass(IntPtr pointer);

			static IUnmanagedContainer<ISimpleDynVecClass<int> ^> ^CreateIntSimpleDynVecClass();
			static IUnmanagedContainer<ISimpleDynVecClass<int> ^> ^CreateIntSimpleDynVecClass(int size);

			bool Resize(int newSize) override sealed;
			bool UninitialisedGrow(int newSize) override sealed;
			void UninitializedResize(int newSize) override sealed;
			IntPtr Peek() override sealed;

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
			void ZeroMemory() override sealed;
#pragma pop_macro("ZeroMemory")

			int FindIndex(int object) override sealed;
			bool Add(int data, int newSizeHint) override sealed;
			bool Add(int data) override;
			int AddMultiple(int numberToAdd) override sealed;
			bool AddHead(int object) override sealed;
			void Insert(int index, int item) override;
			bool DeleteIndex(int index, bool allowShrink) override sealed;
			bool DeleteIndex(int index) override sealed;
			bool DeleteObject(int object, bool allowShrink) override sealed;
			bool DeleteObject(int object) override sealed;
			bool DeleteRange(int start, int count, bool allowShrink) override sealed;
			bool DeleteRange(int start, int count) override sealed;
			void DeleteAll(bool allowShrink) override sealed;
			void DeleteAll() override sealed;

			property IntPtr IntSimpleDynVecClassPointer
			{
				IntPtr get();
			}

			property int Length
			{
				int get() override sealed;
			}

			property int default[int]
			{
				int get(int index) override;
				void set(int index, int value) override;
			}

			property bool IsEmpty
			{
				bool get() override;
			}

			property int Count
			{
				virtual int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;
			bool Grow(int newSizeHint) override sealed;
			bool Shrink() override sealed;

			property ::SimpleDynVecClass<int> *InternalIntSimpleDynVecClassPointer
			{
				virtual ::SimpleDynVecClass<int> *get();
			}

			property IntPtr Vector
			{
				IntPtr get() override sealed;
				void set(IntPtr value) override sealed;
			}

			property int VectorMax
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

			property int ActiveCount
			{
				int get() override sealed;
				void set(int value) override sealed;
			}
	};
}