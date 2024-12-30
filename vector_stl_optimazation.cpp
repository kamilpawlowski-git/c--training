#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) { std::cout << "normalny" << std::endl; }
    //Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {}
    Vertex(const Vertex& vertex) // treningowo dla "this" :)
    {
        this->x = vertex.x; // opcjonalnie (*this).x
        this->y = vertex.y;
        this->z = vertex.z;
        std::cout << "Copied!" << std::endl;
    }
};

int main()
{
    /*
    najpierw tworzy objekt typu vertex za pomoca copy constructor w main(), a nastepnie rowniez za pomoca copy
    constructor tworzy ten obiekt w vectorze. w main() objekt jest nastepnie usuwany

    std::vector<Vertex> vertices;
    vertices.reserve(3); //bez tego tworzy 6 kopii
    vertices.push_back({ 1, 2, 3 }); 
    vertices.push_back({ 4, 5, 6 });
    vertices.push_back({ 7, 8, 9 });
    */
   //lepsza wersja, nie tworzy 6 ani 3 kopii, daje tylko parametry do utworzenia w vectorze, nie korzystamy z copy
   //construktora, a jedynie z normalnego construktora
   std::vector<Vertex> vertices;
    vertices.reserve(3);
    vertices.emplace_back( 1, 2, 3 ); 
    vertices.emplace_back( 4, 5, 6 );
    vertices.emplace_back( 7, 8, 9 );


}