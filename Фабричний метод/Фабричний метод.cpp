#include <iostream>

// Базовий клас продукту
class Product {
public:
    virtual void display() = 0;
};

// Конкретний клас продукту
class ConcreteProduct : public Product {
public:
    void display() override {
        std::cout << "Concrete Product" << std::endl;
    }
};

// Інтерфейс фабричного методу
class Creator {
public:
    virtual Product* createProduct() = 0;
};

// Конкретний фабричний метод
class ConcreteCreator : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};

int main() {
    // Використання фабричного методу
    Creator* creator = new ConcreteCreator();
    Product* product = creator->createProduct();
    product->display();

    // Очищення пам'яті
    delete product;
    delete creator;

    return 0;
}
