#include <iostream>

using namespace std;

class Wall
{
public:
    virtual void UseWall() = 0;
};

class WoodenWall : public Wall
{
public:
    void UseWall() {cout << "Wooden Wall" << endl;}
};

class BrickWall : public Wall
{
public:
    void UseWall() {cout << "Brick Wall" << endl;}
};
/*****************************/
class Window
{
public:
    virtual void UseWindow() = 0;
};

class WoodenWindow : public Window
{
public:
    void UseWindow() {cout << "Wooden Window" << endl;}
};

class PlasticWindow : public Window
{
public:
    void UseWindow() {cout << "Plastic Window" << endl;}
};
/*****************************/
class Roof
{
public:
    virtual void UseRoof() = 0;
};

class TileRoof : public Roof
{
    void UseRoof() {cout << "Tile Roof" << endl;}
};

class MetalTileRoof : public Roof
{
    void UseRoof() {cout << "Metal Tile Roof" << endl;}
};
/*****************************/
class HouseFactory
{
public:
    virtual Wall* CreateWall() = 0;
    virtual Window* CreateWindow() = 0;
    virtual Roof* CreateRoof() = 0;
};

class WoodenHouseFactory : public HouseFactory
{
    Wall* CreateWall() {return new WoodenWall();}
    Window* CreateWindow() {return new WoodenWindow();}
    Roof* CreateRoof() {return new TileRoof();}
};

class BrickenHouseFactory : public HouseFactory
{
    Wall* CreateWall() {return new BrickWall();}
    Window* CreateWindow() {return new PlasticWindow();}
    Roof* CreateRoof() {return new MetalTileRoof();}
};
/****************************/
int main()
{
    HouseFactory* woodenHouseFactory = new WoodenHouseFactory();
    Wall* woodenHouseWall = woodenHouseFactory->CreateWall();
    Window* woodenHouseWindow = woodenHouseFactory->CreateWindow();
    Roof* woodenHouseRoof = woodenHouseFactory->CreateRoof();
    woodenHouseWall->UseWall();
    woodenHouseWindow->UseWindow();
    woodenHouseRoof->UseRoof();

    HouseFactory* brickHouseFactory = new BrickenHouseFactory();
    Wall* brickHouseWall = brickHouseFactory->CreateWall();
    Window* brickHouseWindow = brickHouseFactory->CreateWindow();
    Roof* brickHouseRoof = brickHouseFactory->CreateRoof();
    brickHouseWall->UseWall();
    brickHouseWindow->UseWindow();
    brickHouseRoof->UseRoof();

    cout << "Hello World!" << endl;
    return 0;
}
