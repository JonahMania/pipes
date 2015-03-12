#include "headers/map.hpp"
#include "tinyxml2.h"

//Searches a xml map file and returns the level width
int getWidth( const char *m )
{
	int width = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("width");
		w >> width;
	    return width;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return width;
}
//Searches a xml map file and returns the level height
int getHeight( const char *m )
{
	int height = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("height");
		w >> height;
	    return height;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return height;
}
//Searches a xml map file and returns the x position of the starting pipe 
int getStartX( const char *m )
{
	int startX = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("startx");
		w >> startX;
	    return startX;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return startX;
}
//Searches a xml map file and returns the y position of the starting pipe 
int getStartY( const char *m )
{
	int startY = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("starty");
		w >> startY;
	    return startY;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return startY;
}
//Searches a xml map file and returns the x position of the ending pipe 
int getEndX( const char *m )
{
	int endX = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("endx");
		w >> endX;
	    return endX;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return endX;
}
//Searches a xml map file and returns the y position of the ending pipe 
int getEndY( const char *m )
{
	int endY = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("endy");
		w >> endY;
	    return endY;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return endY;
}
//Searches a xml map file and returns the speed of the water
int getSpeed( const char *m )
{
	int speed = -1;
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
	{
        std::stringstream w; 
		w << doc.FirstChildElement( "map" )->Attribute("speed");
		w >> speed;
	    return speed;
	}
	std::cerr << "ERROR: map was not loaded " << doc.ErrorID() << std::endl;
	return speed;
}
//Calculates the x offset of the game board
int getOffsetX( const char *m )
{
	return ( 1024 - ( getWidth( m ) * 96 ) ) / 2;
}
//Calculates the y offset of the game board
int getOffsetY( const char *m )
{
	return ( 768 - ( getHeight( m ) * 96 ) ) / 2;
}

