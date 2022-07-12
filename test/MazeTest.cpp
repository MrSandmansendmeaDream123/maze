// #include <gtest/gtest.h>
// #include "../room.hpp"
// # include <cstring>
// /*#define NORTH 0
// #define EAST 1
// #define SOUTH 2
// #define WEST 3*/

// //Fixture
// struct MazeTest
//     :public ::testing::Test
//     {
//         Room * x;
//         Room* a = new Room ("Alpha");
//         Room* b = new Room ("Beta");
//         Room* c = new Room ("Charlie");
//         Room* d = new Room ("Delta");
       

//         std::string* name = new std::string("Start"); 

//         virtual void SetUp() override {
//             x = new Room("Start");
//             x -> setNeighbor(NORTH,a);
//             x-> setNeighbor(EAST,b);
//             x ->setNeighbor(WEST,c);
//             x -> setNeighbor(SOUTH,d);


//         }

//         virtual void TearDown() override {
//             delete name;
//             delete x;
//             delete a;
//             delete b;
//             delete c;
//             delete d;
//         }

//     };

// TEST_F(MazeTest, getName){
//     EXPECT_EQ(*name ,x -> getName()) << "Expected Name " << *name <<  " but got name " << x-> getName() ; 
//     EXPECT_NE("Brad",x -> getName()) << "Expected Name " << " Brad " << " but got name " << x-> getName(); 
// }

// // TEST_F(MazeTest, setAndGetNeighbors){
// //         Room tempA("NEW ALPHA");
// //         Room tempB("NEW BETA");
// //         Room * ta = &tempA;
// //         Room * tb = &tempB;
// //         std::array<Room*, NEIGHBORCOUNT> temprooms;
// //         const std::array<Room*, NEIGHBORCOUNT> rooms = {ta, tb, NULL, NULL};

// //        // x->setNeighbors(rooms);
// //         temprooms = x->getNeighbors();
// //         for (int i = 0; i < rooms.size(); i++)
// //         {
// //             if(rooms[i] != nullptr){ 
// //                 EXPECT_EQ(rooms[i]->getName(), temprooms[i]->getName()) << "Expected "<< rooms[i] -> getName() << "got" << temprooms[i]-> getName();
// //             }
// //             else{
// //                 EXPECT_EQ(nullptr, temprooms[i]);
// //             }
// //         }
        
        
        

// // }

// TEST_F(MazeTest, setAndGetNeighbor){
//     Room Replaced("Replaced");
//     x -> setNeighbor(NORTH, &Replaced);
//     EXPECT_EQ("Replaced", x-> getNeighbor(NORTH) -> getName()) <<" Expected Neighbor "<< Replaced.getName();
//     EXPECT_EQ("Beta", x-> getNeighbor(EAST) -> getName()) << "Expected Neighbor  Beta, but got " <<  x-> getNeighbor(EAST) -> getName();
// }


// TEST_F(MazeTest, moveRooms){
//     Room * nxtRoom = x->moveRooms(NORTH);
//     EXPECT_NE(nullptr, nxtRoom);
//     //EXPECT_EQ("Alpha", nxtRoom->getName()); //Will segment fault due to null
// }

// TEST(LockTest, setAndGetLockStatus){
// Room * x = new Room("Lockable");
// x->setLockStatus(false);
// EXPECT_FALSE(x->getLockStatus());
// x->setLockStatus(true);
// EXPECT_TRUE(x->getLockStatus());
// delete x;
// }


// // --gtest_filter=DirectionTest*
// TEST(DirectionTest, revdir){
//     EXPECT_EQ(NORTH, revDir(SOUTH));
//     EXPECT_EQ(SOUTH, revDir(NORTH));
//     EXPECT_EQ(EAST, revDir(WEST));
//     EXPECT_EQ(WEST, revDir(EAST));
// }