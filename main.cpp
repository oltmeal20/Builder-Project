#include <iostream>
using namespace std;

// Your end product 
class AppleProduct {
    string _product;
    string _input;
    string _processor;
    string _lifespan;
    string _weight;

public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setInput(string set_input) { _input = set_input; }

    void setLifespan(string set_lifespan) { _lifespan = set_lifespan; }

    void setWeight(string set_weight) { _weight = set_weight; }

    string getProcessor() { return _processor; }
    string getInput() { return _input; }
    string getLifespan() { return _lifespan; }
    string getWeight() { return _weight; }

    void show() {
        cout << "Apple Base Product Info: " << _product << endl;
        cout << "Input Type: " << _input << endl;
        cout << "Processor Type: " << _processor << endl;
        cout << "Lifespan: " << _lifespan << endl;
        cout << "Product Weight: " << _weight << endl << endl;
    }
};

// AppleProductBuilder Abstract Class all builders should have at least these methods
class AppleProductBuilder {
protected:
    AppleProduct* _apple_product;
public:
    virtual void getOtherParts() = 0;
    virtual void buildInput() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildLifespan() = 0;
    virtual void buildWeight() = 0;
    AppleProduct* getAppleProduct() { return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder : public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen Input"); }

    void buildLifespan() { _apple_product->setLifespan("4.25 Years"); }

    void buildWeight() { _apple_product->setWeight("0.25 pound"); }
};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder : public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input"); }

    void buildLifespan() { _apple_product->setLifespan("4 Years"); }

    void buildWeight() { _apple_product->setWeight("3 pounds"); }
};

// AppleProductBuilder concrete class knows only how to build HomePod Mini AppleProduct
class HomePodMiniBuilder : public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for HomePod Mini"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor"); }

    void buildInput() { _apple_product->setInput("Voice control"); }

    void buildLifespan() { _apple_product->setLifespan("Unknown"); }

    void buildWeight() { _apple_product->setWeight("0.75 pound"); }
};

// AppleProductBuilder concrete class knows only how to build Watch AppleProduct
class WatchBuilder : public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Watch"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen Input"); }

    void buildLifespan() { _apple_product->setLifespan("3 Years"); }

    void buildWeight() { _apple_product->setWeight("0.085 pound"); }
};

// AppleProductBuilder concrete class knows only how to build iPad AppleProduct
class iPadBuilder : public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPad"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen Input"); }

    void buildLifespan() { _apple_product->setLifespan("2 Years"); }

    void buildWeight() { _apple_product->setWeight("1 pound"); }
};

// Defines steps and tells to the builder that build in given order.
class Director {

    AppleProductBuilder* builder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder* builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        //my added builders
        builder->buildLifespan();
        builder->buildWeight();
        return builder->getAppleProduct();
    }
};

int main() {

    Director dir;
    MacBuilder mb;
    iPhoneBuilder ib;
    HomePodMiniBuilder hpmb;
    //my added products
    WatchBuilder wb;
    iPadBuilder ipb;

    AppleProduct* mac = dir.createAppleProduct(&mb);
    AppleProduct* iphone = dir.createAppleProduct(&ib);
    AppleProduct* homepodmini = dir.createAppleProduct(&hpmb);
    AppleProduct* watch = dir.createAppleProduct(&wb);
    AppleProduct* ipad = dir.createAppleProduct(&ipb);

    mac->show();
    delete mac;

    iphone->show();
    delete iphone;

    homepodmini->show();
    delete homepodmini;

    watch->show();
    delete watch;

    ipad->show();
    delete ipad;

    return 0;
}