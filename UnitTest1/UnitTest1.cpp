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
				Assert::AreEqual(test_field[i], player_field->field[i]);
			}
		}

		TEST_METHOD(TestShipPlacementRight) //test placing 5 ships of different size with no mistakes
		{
			int size = 10;
			Field* player_field = new Field(size);
			int first = player_field->place_ship(4, 3, 0, 0);
			int second = player_field->place_ship(1, 1, 8, 8);
			int third = player_field->place_ship(2, 4, 7, 8);
			int fourth = player_field->place_ship(3, 3, 0, 1);
			int fifth = player_field->place_ship(4, 2, 3, 5);
			Assert::AreEqual(0, first); //if everything worked, everything will return 0
			Assert::AreEqual(0, second);
			Assert::AreEqual(0, third);
			Assert::AreEqual(0, fourth);
			Assert::AreEqual(0, fifth);
		}

		TEST_METHOD(TestShipPlacementWrong) //different mistakes
		{
			int size = 10;
			Field* player_field = new Field(size);
			int first = player_field->place_ship(4, 1, 0, 0); // BOUNDARY_ERROR
			int second = player_field->place_ship(1, 1, -1, -1); // INPUT_ERROR
			int third = player_field->place_ship(1, 3, 0, 0); // no error
			int fourth = player_field->place_ship(4, 3, 0, 0); //placing a ship on top of another ship COLLISION ERROR
			int fifth = player_field->place_ship(1, 5, 5, 5); // INPUT_ERROR
			int sixth = player_field->place_ship(2, 2, 9, 9); //BOUNDARY_ERROR
			int seventh = player_field->place_ship(2, 3, 9, 8); //BOUNDARY_ERROR
			int eighth = player_field->place_ship(2, 4, 9, 0); //BOUNDARY_ERROR
			Assert::AreEqual(BOUNDARY_ERROR, first);
			Assert::AreEqual(INPUT_ERROR, second);
			Assert::AreEqual(0, third);
			Assert::AreEqual(COLLISION_ERROR, fourth);
			Assert::AreEqual(INPUT_ERROR, fifth);
			Assert::AreEqual(BOUNDARY_ERROR, sixth);
			Assert::AreEqual(BOUNDARY_ERROR, seventh);
			Assert::AreEqual(BOUNDARY_ERROR, eighth);
		}

		TEST_METHOD(TestShoot)
		{
			int size = 10;
			Field* player_field = new Field(size);
			player_field->place_ship(4, 3, 0, 0);
			player_field->place_ship(1, 1, 8, 8);
			player_field->place_ship(2, 4, 7, 8);
			player_field->place_ship(3, 3, 0, 1);
			player_field->place_ship(4, 2, 3, 5);
			int first = player_field->shoot(0, 0); //hit
			int second = player_field->shoot(5, 5); //miss
			int third = player_field->shoot(10, 10); //INPUT_ERROR
			Assert::AreEqual(1, first);
			Assert::AreEqual(0, second);
			Assert::AreEqual(INPUT_ERROR, third);
		}

		TEST_METHOD(TestWin)
		{
			int size = 10;
			Field* player_field = new Field(size);
			player_field->place_ship(1, 1, 8, 8);
			player_field->place_ship(1, 1, 7, 7);
			player_field->shoot(8, 8); //hit
			int first = player_field->check_win();
			player_field->shoot(7, 7); //hit
			int second = player_field->check_win();
			Assert::AreEqual(0, first);
			Assert::AreEqual(1, second);
			}
	};
}
