enum Direction {North, South, East, West}; 

class MapSite {
 public:
 	virtual void Enter() = 0;
 }; 

 class Room : public MapSite {
 public:
	 Room(int roomNo);

	 MapSite* GetSide(Direction) const;
	 void SetSide(Direction, MapSite*);

	 virtual void Enter();

 private:
	 MapSite* _sides[4];
	 int _roomNumber;
 }; 
class Wall : public MapSite {
 public:
	 Wall();
	 virtual void Enter();
 };

 class Door : public MapSite {
 public:
	 Door(Room* = 0, Room* = 0);

	 virtual void Enter();
	 Room* OtherSideFrom(Room*);

 private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;
 };

class Maze {
 public:
 Maze();

 void AddRoom(Room*);
 Room* RoomNo(int) const;
 private:
 // ...
 }; 

class MazeFactory {
 public:
 MazeFactory();

 virtual Maze* MakeMaze() const
 { return new Maze; }
 virtual Wall* MakeWall() const
 { return new Wall; }
 virtual Room* MakeRoom(int n) const
 { return new Room(n); }
 virtual Door* MakeDoor(Room* r1, Room* r2) const
 { return new Door(r1, r2); }
 }; 

 Maze* MazeGame::CreateMaze (MazeFactory& factory) {
 Maze* aMaze = factory.MakeMaze();
 Room* r1 = factory.MakeRoom(1);
 Room* r2 = factory.MakeRoom(2);
 Door* aDoor = factory.MakeDoor(r1, r2);

 aMaze->AddRoom(r1);
 aMaze->AddRoom(r2);

 r1->SetSide(North, factory.MakeWall());
 r1->SetSide(East, aDoor);
 r1->SetSide(South, factory.MakeWall());
 r1->SetSide(West, factory.MakeWall());

 r2->SetSide(North, factory.MakeWall());
 r2->SetSide(East, factory.MakeWall());
 r2->SetSide(South, factory.MakeWall());
 r2->SetSide(West, aDoor);

 return aMaze;
 } 
Maze* MazeGame::CreateMaze () {
 Maze* aMaze = new Maze;
 Room* r1 = new Room(1);
 Room* r2 = new Room(2);
 Door* theDoor = new Door(r1, r2);

 aMaze->AddRoom(r1);
 aMaze->AddRoom(r2);

 r1->SetSide(North, new Wall);
 r1->SetSide(East, theDoor);
 r1->SetSide(South, new Wall);
 r1->SetSide(West, new Wall);

 r2->SetSide(North, new Wall);
 r2->SetSide(East, new Wall);
 r2->SetSide(South, new Wall);
 r2->SetSide(West, theDoor);

 return aMaze;
 } 


  class EnchantedMazeFactory : public MazeFactory {
 public:
 EnchantedMazeFactory();

 virtual Room* MakeRoom(int n) const
 { return new EnchantedRoom(n, CastSpell()); }

 virtual Door* MakeDoor(Room* r1, Room* r2) const
 { return new DoorNeedingSpell(r1, r2); }

 protected:
 	Spell* CastSpell() const;
 }; 

 Wall* BombedMazeFactory::MakeWall () const {
 return new BombedWall;
 } 
 Room* BombedMazeFactory::MakeRoom(int n) const {
 return new RoomWithABomb(n);
 } 
int main(int argc, char const *argv[])
{
	MazeGame game;
	BombedMazeFactory factory;
	game.CreateMaze(factory); 	
	return 0;
}




