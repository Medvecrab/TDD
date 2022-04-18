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

		TEST_METHOD(TestShipPlacementRight) //test placing 5 ships of different size with no mistakes
		{
			int size = 10;
			Field* player_field = new Field(size);
			int first = player_field->place_ship(4, 3, 0, 0);
			int second = player_field->place_ship(1, 1, 8, 8);
			int third = player_field->place_ship(2, 4, 7, 8);
			int fourth = player_field->place_ship(3, 3, 0, 0);
			int fifth = player_field->place_ship(4, 2, 3, 5);
			Assert::AreEqual(first + second + third + fourth + fifth, 0); //if everything worked, everything will return 0
		}

		TEST_METHOD(TestShipPlacementWrong) //different mistakes
		{
			int size = 10;
			Field* player_field = new Field(size);
			int first = player_field->place_ship(4, 1, 0, 0);
			int second = player_field->place_ship(1, 1, -1, -1);
			int third = player_field->place_ship(1, 3, 0, 0);
			int fourth = player_field->place_ship(4, 3, 0, 0); //placing a ship on top of another ship
			int fifth = player_field->place_ship(1, 5, 5, 5);
			Assert::AreEqual(first + second + third + fourth, -7); //if everything "worked", sum will be -7
		}
	};
}
