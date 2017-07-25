class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
public:
    void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    // Write your code here
public:
    void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        // Write your code here
        if (type == "Dog")
            return new Dog();
        else if (type == "Cat")
            return new Cat();
        return NULL;
    }
};
