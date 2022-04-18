#include "pch.h"
#include "CppUnitTest.h"
#include "../TDD_main/Field.h"
#include "../TDD_main/Field.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FieldTesting
{
	TEST_CLASS(DefaultTester)
	{
	public:
		
		TEST_METHOD(TestFieldInit)
		{
			int size = 10;
			Field* player_field = new Field(size);
			std::vector<std::string> test_field = std::vector<std::string>(size + 1); //+1 = PADDING
			test_field[0] = {" ABCDEFGHIJ"};
			test_field[1] = {"0~~~~~~~~~~"};
			test_field[2] = {"1~~~~~~~~~~"};
			test_field[3] = {"2~~~~~~~~~~"};
			test_field[4] = {"3~~~~~~~~~~"};
			test_field[5] = {"4~~~~~~~~~~"};
			test_field[6] = {"5~~~~~~~~~~"};
			test_field[7] = {"6~~~~~~~~~~"};
			test_field[8] = {"7~~~~~~~~~~"};
			test_field[9] = {"8~~~~~~~~~~"};
			test_field[10] = {"9~~~~~~~~~~"};
			for (int i = 0; i < size + 1; i++)
			{
				Assert::AreEqual(player_field->field[i], test_field[i]);
			}
		}
	};
}
