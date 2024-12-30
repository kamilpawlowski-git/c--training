#include <iostream>
#include <vector>

using std::cout, std::endl;

struct Vertex
{
    float x, y, z;
};

std::ostream& operator << (std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z << endl;
    return stream;
}

void Function(const std::vector<Vertex>& vertex) {} // w parametrze funkcji zawsze przez referencje zeby
                                                    // zbednie nie kopiowac 

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({ 1, 2, 3});
    vertices.push_back({ 4, 5, 6});

    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << endl;
    }

    for(Vertex& v : vertices) // lepiej dac "&" wtedy dane nie sa kopiowane, bardziej optymalne
        cout << v << endl;

    // jesli chcemy usunac np drugi element musimy to zrobic poprzez dodanie do vertices.begin() + 1, czemu?
    // bo vector operuje na iteratorze, iterator jest wzgledny, wie gdzie jest poczatek i traktuje to jako
    // odniesienia

    vertices.erase(vertices.begin() + 1);

    //zobaczmy
    for(Vertex& v : vertices) // lepiej dac "&" wtedy dane nie sa kopiowane, bardziej optymalne
        cout << v << endl;
    
    
    Function(vertices); // ta funkcja nic nie robi spokojnie :)



}