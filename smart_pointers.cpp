#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Object created!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Object destroyed!" << std::endl;
    }

    void Print() {}
};

int main()
{
    /*
    unique_ptr wskazuje na miejsce w pamieci, tworzy i usuwa za nas obiekt jesli tylko nie bedzie on nam juz
    potrzebny, zastepuje troche keyword "new" oraz "delete"
    */
    {
        // std::unique_ptr<Entity> entity(new Entity());  <---dobry sposob, ale lepiej uzyc std::make_unique
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->Print();
        std::unique_ptr<Entity> entity_ptr;
        // entity_ptr = entity;  <--- nielegalne dla unique_ptr
    }

    /*
    shared_ptr tworza dodatkowe miejsce w pamieci nazywane "control block", jest to licznik referencji ile razy
    nawiazujemy do danego adresu pamieci, kiedy licznik referencji bedzie wynosic zero "0" wtedy obiekt zostanie
    dlatego nie musimy sie martwic ze inny pointer wskazujacy na to samo miejsce pamieci nagle bedzie wskazywac
    na adres, ktorego pamiec zostala zwolniona
    */
    {
        std::shared_ptr<Entity> sharedEntity;
        {
            std::shared_ptr<Entity> sharedEntity_ptr = std::make_shared<Entity>();
            sharedEntity = sharedEntity_ptr;
        }
    }
    
    /*
    weak_ptr nie maja opcji zliczania referencji, jesli miejsce w pamieci na ktore wskazuja chce sie usunac,
    to sie usunie, nie interesuje go ze weak_ptr bedzie wskazywac na pamiec, ktore bedzie "invalid", mozemy zrobic 
    sprawdzanie czy weak_ptr wskazuje na cos konkretego czy nie, ale jak? jeszcze do tego nie doszedlem
    */
    {
        std::weak_ptr<Entity> weakEntity;
        {
            std::shared_ptr<Entity> shared = std::make_shared<Entity>();
            weakEntity = shared;
        }
    }
    std::cin.get();
}