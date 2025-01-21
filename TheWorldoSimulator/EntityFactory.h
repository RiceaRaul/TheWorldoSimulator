#pragma once
#include "Rhaptor.h"
#include "Katzel.h"
#include "Pysika.h"
#include "Shoarek.h"
#include "Fournika.h"
#include "Plantha.h"

class EntityFactory {
public:
    static std::shared_ptr<Entity> createEntity(const std::string& type) {
        if (type == "Rhaptor") return std::make_shared<Rhaptor>();
        if (type == "Katzel") return std::make_shared<Katzel>();
        if (type == "Pysika") return std::make_shared<Pysika>();
        if (type == "Shoarek") return std::make_shared<Shoarek>();
        if (type == "Fournika") return std::make_shared<Fournika>();
        if (type == "Plantha") return std::make_shared<Plantha>();
        // Add other species...
        return nullptr;
    }
};
