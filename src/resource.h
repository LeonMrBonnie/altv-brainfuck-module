#pragma once
#include "brainfuck-module.h"

class BrainfuckRuntime;
class BrainfuckResource : public alt::IResource::Impl
{   
    BrainfuckRuntime* runtime;
    alt::IResource* resource;

public:
    BrainfuckResource(BrainfuckRuntime* runtime, alt::IResource* resource);
    ~BrainfuckResource() = default;

    bool Start();
    bool Stop();

    bool OnEvent(const alt::CEvent* event);
    void OnTick()
    {

    }

    void OnCreateBaseObject(alt::IBaseObject* object)
    {

    }
    void OnRemoveBaseObject(alt::IBaseObject* object)
    {

    }
};
