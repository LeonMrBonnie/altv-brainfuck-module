#include "runtime.h"

alt::IResource::Impl* BrainfuckRuntime::CreateImpl(alt::IResource* impl)
{
    auto resource = new BrainfuckResource(this, impl);
    //resources.emplace(&resource);
    return resource;
}

void BrainfuckRuntime::DestroyImpl(alt::IResource::Impl* impl)
{
    BrainfuckResource* resource = dynamic_cast<BrainfuckResource*>(impl);
    if(resource != nullptr) 
    {
        //resources.erase(resource);
        delete resource;
    }
}